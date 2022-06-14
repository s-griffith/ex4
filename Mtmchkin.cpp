#include "Mtmchkin.h"

//------------------------------------------Additional Functions-------------------------------------
template <class Derived> //----------------------------------------------------------------------------------------------not sure if this line is needed up here
std::unique_ptr<Card> creationFactory();
std::map<std::string, std::unique_ptr<Card>(*)()> createCardDictionary();
std::queue<std::shared_ptr<Card>> createDeck(std::ifstream& sourceFile);
std::list<std::shared_ptr<Player>> createPlayers();
int receiveTeamSize();
void receivePlayer(std::string& name, std::string& job);
bool checkName(const std::string& givenName);
bool checkJob(const std::string& givenJob);
void printMessages(const bool validName, const bool validJob);
std::unique_ptr<Card> castCard(const std::string& cardName);
//---------------------------------------------------------------------------------------------------


Mtmchkin::Mtmchkin(const std::string fileName)
{
    //Check if file name valid, throw appropriate error if not
    std::ifstream sourceFile(fileName);
    std::cout << "File name " << fileName << std::endl;
    if (!sourceFile || !sourceFile.is_open()) {
        throw DeckFileNotFound();
    }
    //Create card deck
    try {
        m_deck = std::move(createDeck(sourceFile));
    } catch (std::exception &e) {
        sourceFile.close();
        throw e;
    }
    //If the card deck is less than 5 cards, throw appropriate error
    if (m_deck.size() < 5) {
        throw DeckFileInvalidSize();
    }
    //Create players + initiate number of rounds in game
    m_players = std::move(createPlayers());
    m_numRounds = 0;
}

void Mtmchkin::playRound()
{
    if (!isGameOver()) {
        //Print that another round has started
        printRoundStartMessage(m_numRounds);
        for (std::shared_ptr<Player>& currentPlayer : m_players) {
            if (((*currentPlayer).getLevel() != Player::MAX_LEVEL) && (!(*currentPlayer).isKnockedOut())) {
                //Print player's turn
                printTurnStartMessage((*currentPlayer).getName());
                //Draw card
                std::string cardName = (*m_deck.front()).getName();
                std::shared_ptr<Card> currentCard = castCard(cardName); //make sure that it copies
                //Play card
                (*currentCard).applyEncounter(*currentPlayer);
                //Return card to back of deck
                m_deck.push(m_deck.front());
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
    if (isGameOver()) { //-----------------------------------------------------------------------------------------------Maybe needs to be inside if(), depends if this function is called on a game that is over and the message is required or not
        printGameEndMessage();
    }
}

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
    return m_numRounds;
}

//------------------------------------------Additional Functions-------------------------------------

//Factory function for creating cards according to the appropriate derived class
template <class Derived>
std::unique_ptr<Card> creationFactory()
{
    std::unique_ptr<Card> currentCard(new Derived);//-----------------------------------------------------------------Possible memory leak, internet says no but need to double-check
    //Move card (not copy)
    return currentCard;
}

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

//Create queue of cards
std::queue<std::shared_ptr<Card>> createDeck(std::ifstream& sourceFile)
{
    //Initiate card dictionary
    std::map<std::string, std::unique_ptr<Card>(*)()> cardDictionary = createCardDictionary();
    std::queue<std::shared_ptr<Card>> tmpDeck;
    std::string line;
    int lineCounter = 0;
    while (std::getline(sourceFile, line)) {
        lineCounter++;
        //Create card according to given name in file line
        if (cardDictionary.count(line)) {
            std::unique_ptr<Card> currentCard(cardDictionary[line]());
            tmpDeck.push(std::move(currentCard));
        }
        //If file has invalid name in one of the lines, throw appropriate error
        else {
            throw DeckFileFormatError(lineCounter);
        }
    }
    //Move queue (not copy)
    return std::move(tmpDeck);
}


//Create queue of shared pointers to players
std::list<std::shared_ptr<Player>> createPlayers()
{
    std::list<std::shared_ptr<Player>> tmpPlayers;
    //Print opening game message
    printStartGameMessage();
    //Receives and validates team size from user
    int teamSize = receiveTeamSize();
    std::string name;
    std::string job;
    for (int i = 0; i < teamSize; i++) {
        receivePlayer(name, job);
        //Create smart pointer to player according to job
        std::shared_ptr<Player> ptrNewPlayer;
        //-----------------------------------------------Possible memory leak, internet says no but need to double-check
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
    //Move queue (not copy)
    return std::move(tmpPlayers);
}

//Accept team size from command line until given valid argument
int receiveTeamSize()
{
    int teamSize;
    //Ask user for team size
    printEnterTeamSizeMessage();
    std::cin >> teamSize;
    //If input was invalid (not an int or not in valid team size range) ask for new input
    while ((!std::cin.good()) || (teamSize < 2) || (teamSize > 6)) { //--------------------------------------------------Maybe need static const values
        //Ask user for team size
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        //Clears error flags on cin & clears buffer before taking in new line
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> teamSize;
    }
    return teamSize;
}

//Accept player details from command line until given valid arguments
void receivePlayer(std::string& name, std::string& job)
{
    //Ask user for player's details
    printInsertPlayerMessage();
    std::cin >> name >> job;
    //Check input
    bool validName = checkName(name);
    bool validJob = checkJob(job);
    //If input was invalid (not a valid name or job) ask for new input
    while ((!validName) || (!validJob)) { // (!std::cin.good()) ||  //-------------------------------------------------------Needs to work with input Jimmy Wizard Wizard - need to check that (!std::cin.good()) doesn't throw error
        printMessages(validName, validJob);
        //Clears error flags on cin & clears buffer before taking in new line
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> name >> job;
        //Check input
        validName = checkName(name);
        validJob = checkJob(job);
    }
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
    if ((givenJob.compare("Fighter") != 0) && (givenJob.compare("Rogue") != 0) && (givenJob.compare("Wizard") != 0)) {
        return false;
    }
    return true;
}

//Prints relevant message
void printMessages(const bool validName, const bool validJob)
{
    if (!validName) {
        printInvalidName();
    }
    else if (!validJob) {
        printInvalidClass();
    }
    //Ask user for player's details again
    printInsertPlayerMessage();
}

std::unique_ptr<Card> castCard(const std::string& cardName) 
{
    //Initiate card dictionary
    std::map<std::string, std::unique_ptr<Card>(*)()> cardDictionary = createCardDictionary();
    std::unique_ptr<Card> ptrCurrentCard(cardDictionary[cardName]());
    return ptrCurrentCard;
}