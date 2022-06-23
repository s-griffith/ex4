#include "Mtmchkin.h"

//----------------------------------------Additional Functions-------------------------------------
std::unique_ptr<Card> creationFactory();
std::map<std::string, std::unique_ptr<Card>(*)()> createCardDictionary();
std::queue<std::unique_ptr<Card>> createDeck(std::ifstream& sourceFile);
std::unique_ptr<Gang> addGang(int& lineCounter, std::ifstream& sourceFile);
std::list<std::shared_ptr<Player>> createPlayers();
int receiveTeamSize();
void receivePlayer(std::string& name, std::string& job);
bool checkName(const std::string& givenName);
bool checkJob(const std::string& givenJob);
void printMessages(const bool validName, const bool validJob);
//-------------------------------------------------------------------------------------------------

//----------------------------------------Static Variables-----------------------------------------
static const int MIN_PLAYERS = 2;
static const int MAX_PLAYERS = 6;
//-------------------------------------------------------------------------------------------------

//Constructor
Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    //Check if file name valid, throw appropriate error if not
    std::ifstream sourceFile(fileName);
    if (!sourceFile || !sourceFile.is_open()) {
        throw DeckFileNotFound();
    }
    //Create card deck and throw appropriate errors if needed
    try {
        m_deck = std::move(createDeck(sourceFile));
    }
    catch (DeckFileFormatError& e) {
        sourceFile.close();
        throw e;
    }
    catch (DeckFileInvalidSize& e) {
        sourceFile.close();
        throw e;
    }
    catch (std::exception& e) {
        sourceFile.close();
        throw e;
    }
    //If the card deck is less than 5 cards, throw appropriate error
    if (m_deck.size() < 5) {
        throw DeckFileInvalidSize();
    }
    //Create players, throw appropriate errors if needed
    try {
        m_players = std::move(createPlayers());
    }
    catch (std::exception &e) {
        sourceFile.close();
        throw e;
    }
    //Set game rounds
    m_numRounds = 1;
}

// Play the next Round of the game - according to the instruction in the exercise document.
void Mtmchkin::playRound()
{
    if (!isGameOver()) {
        printRoundStartMessage(m_numRounds);
        for (std::shared_ptr<Player>& currentPlayer : m_players) {
            if (((*currentPlayer).getLevel() != Player::MAX_LEVEL) && (!(*currentPlayer).isKnockedOut())) {
                //Print player's turn
                printTurnStartMessage((*currentPlayer).getName());
                //Draw card
                (*(m_deck.front())).applyEncounter(*currentPlayer);
                //Return card to back of deck
                m_deck.push(std::move(m_deck.front()));
                m_deck.pop();
                //If the player has reached max level, the player has won the game!
                if ((*currentPlayer).getLevel() == Player::MAX_LEVEL) {
                    m_winners.push_back(currentPlayer);
                }
                //If the player is knocked out, the player has lost...
                else if ((*currentPlayer).isKnockedOut()) {
                    m_losers.insert(m_losers.begin(), currentPlayer);
                }
            }

        }
        //Count number of rounds completed in game
        m_numRounds++;
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
}

// Prints the leaderBoard of the game at a given stage of the game
void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int playerCounter = 1;
    //Prints winners
    for (const std::shared_ptr<Player>& currentPlayer : m_winners) {
        printPlayerLeaderBoard(playerCounter, (*currentPlayer));
        playerCounter++;
    }
    //Prints current players by their turn
    for (const std::shared_ptr<Player>& currentPlayer : m_players) {
        if (((*currentPlayer).getLevel() != Player::MAX_LEVEL) && (!(*currentPlayer).isKnockedOut())) {
            printPlayerLeaderBoard(playerCounter, (*currentPlayer));
            playerCounter++;
        }
    }
    //Prints losers
    for (const std::shared_ptr<Player>& currentPlayer : m_losers) {
        printPlayerLeaderBoard(playerCounter, (*currentPlayer));
        playerCounter++;
    }
}

//Checks if the game has ended
bool Mtmchkin::isGameOver() const
{
    bool gameOver = true;
    for (const std::shared_ptr<Player>& currentPlayer : m_players) {
        if (((*currentPlayer).getLevel() != Player::MAX_LEVEL) && (!(*currentPlayer).isKnockedOut())) {
            gameOver = false;
        }
    }
    return gameOver;
}

//Returns the number of rounds played
int Mtmchkin::getNumberOfRounds() const
{
    return m_numRounds-1;
}

//----------------------------------------Additional Functions-------------------------------------

//Factory function for creating cards according to the appropriate derived class
template <class Derived>
std::unique_ptr<Card> creationFactory()
{
    std::unique_ptr<Card> currentCard(new Derived);
    return currentCard;
}

//Create dictionary of cards: between their name (string) and a factory function to create the cards
std::map<std::string, std::unique_ptr<Card>(*)()> createCardDictionary() 
{
    std::map<std::string, std::unique_ptr<Card>(*)()> cardDictionary;
    cardDictionary["Barfight"] = &creationFactory<Barfight>;
    cardDictionary["Dragon"] =  &creationFactory<Dragon>;
    cardDictionary["Fairy"] =  &creationFactory<Fairy>;
    cardDictionary["Goblin"] =  &creationFactory<Goblin>;
    cardDictionary["Merchant"] =  &creationFactory<Merchant>;
    cardDictionary["Pitfall"] =  &creationFactory<Pitfall>;
    cardDictionary["Treasure"] =  &creationFactory<Treasure>;
    cardDictionary["Vampire"] =  &creationFactory<Vampire>;
    return cardDictionary;
}

//Create queue of cards from file input
std::queue<std::unique_ptr<Card>> createDeck(std::ifstream& sourceFile)
{
    //Initiate card dictionary
    std::map<std::string, std::unique_ptr<Card>(*)()> cardDictionary = createCardDictionary();
    std::queue<std::unique_ptr<Card>> tmpDeck;
    std::string line;
    int lineCounter = 1;
    while (!sourceFile.eof()) {
        std::getline(sourceFile, line);
        //*Bonus* If there is a gang in the deck, create separately
        if (line == "Gang") {
            lineCounter++;
            tmpDeck.push(std::move(addGang(lineCounter, sourceFile)));
        }
        //Create card according to given name in file line
        else if (cardDictionary.count(line)) {
            lineCounter++;
            tmpDeck.push(std::move(cardDictionary[line]()));
        }
        //If file has invalid name in one of the lines, throw appropriate error
        else {
            if (lineCounter == 1 && line == "" && sourceFile.eof()) {
                throw DeckFileInvalidSize();
            }
            else {
                throw DeckFileFormatError(lineCounter);
            }
        }
    }
    return tmpDeck;
}

//Read from file to create a gang of monsters
std::unique_ptr<Gang> addGang(int& lineCounter, std::ifstream& sourceFile)
{
    std::vector<std::string> tmpMonsterGang;
    std::string line;
    while ((sourceFile.eof() != true) && (line != "EndGang")) {
        std::getline(sourceFile, line);
        //Add card to gang according to monster type
        if ((line == "Vampire") || (line == "Goblin") || (line == "Dragon")) {
            lineCounter++;
            tmpMonsterGang.push_back(line);
        }
        //If there was an invalid line (or non-monster card), throw appropriate error
        else if (line != "EndGang") {
            throw DeckFileFormatError(lineCounter);
        }
    }
    //If the file ended without and "EndGang", throw appropriate error
    if (line != "EndGang") {
        throw DeckFileFormatError(lineCounter);
    }
    lineCounter++;
    //Create unique ptr to gang
    std::unique_ptr<Gang> newGang(new Gang(tmpMonsterGang));
    return newGang;
}

//Create queue of shared pointers to players
std::list<std::shared_ptr<Player>> createPlayers()
{
    std::list<std::shared_ptr<Player>> tmpPlayers;
    //Receives and validates team size from user
    int teamSize = receiveTeamSize();
    std::string name;
    std::string job;
    for (int i = 0; i < teamSize; i++) {
        receivePlayer(name, job);
        //Create smart pointer to player according to job
        std::shared_ptr<Player> ptrNewPlayer;
        if (job == "Fighter") {
            ptrNewPlayer.reset(new Fighter(name));
        }
        else if (job == "Rogue") {
            ptrNewPlayer.reset(new Rogue(name));
        }
        else {
            ptrNewPlayer.reset(new Wizard(name));
        }
        //Add pointer to queue
        tmpPlayers.push_back(ptrNewPlayer);
    }
    return tmpPlayers;
}

//Accept team size from command line until given valid argument
int receiveTeamSize()
{
    int teamSize = 0;
    std::string initialInput = "";
    bool validInput = true;
    //Ask user for team size
    printEnterTeamSizeMessage();
    do {
        validInput = true;
        try {
            std::getline(std::cin, initialInput);
            teamSize = std::stoi(initialInput);
        }
        catch (std::exception&) {
            validInput = false;
        }
        //If input was invalid (not an int or not in valid team size range) ask for new input
        if ((!validInput) || (teamSize < MIN_PLAYERS) || (teamSize > MAX_PLAYERS)) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    } while ((!validInput) || (teamSize < MIN_PLAYERS) || (teamSize > MAX_PLAYERS));
    return teamSize;
}

//Accept player details from command line until given valid arguments
void receivePlayer(std::string& name, std::string& job)
{
    //Ask user for player's details
    printInsertPlayerMessage();
    std::string line = "";
    std::string delimiter = " ";
    bool validInput = true;
    bool validName = true;
    bool validJob = true;
    do {
        validInput = true;
        //Ask user for team size until correct size is entered, throw necessary errors
        try {
            std::getline(std::cin, line);
            name = line.substr(0, line.find(delimiter));
            std::string subString = line.substr(line.find(delimiter) + 1);
            job = subString.substr(0, subString.find(delimiter));
        }
        catch (std::exception&)  {
            validInput  = false;
        }
        //Validate input, if invalid print appropriate messages
        validName = checkName(name);
        validJob = checkJob(job);
        if ((!validInput) || (!validName) || (!validJob)) {
            printMessages(validName, validJob);
        }
    } while ((!validInput) || (!validName) || (!validJob)); 
}

//Validates the name from input
bool checkName(const std::string& givenName)
{
    //If the name is longer than 15 characters, the name is invalid
    if (givenName.size() > 15) {
        return false;
    }
    //If the characters in the name are not english letters, the name is invalid
    for (char const &letter : givenName) {
        if ((letter < 'A') || (letter > 'Z' && letter < 'a') || (letter > 'z')) {
            return false;
        }
    }
    return true;
}

//Validates the job from input
bool checkJob(const std::string& givenJob)
{
    if ((givenJob != "Fighter") && (givenJob != "Rogue") && (givenJob != "Wizard")) {
        return false;
    }
    return true;
}

//Prints relevant message if player input was invalid
void printMessages(const bool validName, const bool validJob)
{
    if (!validName) {
        printInvalidName();
    }
    else if (!validJob) {
        printInvalidClass();
    }
}