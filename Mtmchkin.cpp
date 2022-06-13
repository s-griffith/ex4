#include "Mtmchkin.h"

//Left to do: Leaderboard (maybe array of pointers? rank for each player?)

//------------------------------------------Additional Functions-------------------------------------
Card* creationFactory();
std::queue<Card> createDeck(const std::ifstream& sourceFile);
std::queue<std::shared_ptr<Player>> createPlayers();
int receiveTeamSize();
void receivePlayer(std::string *name, std::string *job);
bool checkName(const std::string& givenName);
bool checkJob(const std::string& givenJob);
void printMessages(const bool validName, const bool validJob);
//---------------------------------------------------------------------------------------------------


Mtmchkin::Mtmchkin(const std::string fileName)
{
    //Check if file name valid
    std::ifstream sourceFile(fileName);
    if (!sourceFile) {
        throw DeckFileNotFound();
    }
    m_deck = std::move(createDeck(sourceFile));
    if (m_deck.size() < 5) {
        throw DeckFileInvalidSize();
    }
    m_players = std::move(createPlayers());
    m_numRounds = 0;
}

void Mtmchkin::playRound()
{
    if (!isGameOver()) {
        //Print that another round has started
        printRoundStartMessage();
        for (std::shared_ptr<Player>& currentPlayer : m_players) {
            if (((*currentPlayer).getLevel() != Player::MAX_LEVEL) && (!(*currentPlayer).isKnockedOut())) {
                //Print player's turn
                printTurnStartMessage((*currentPlayer).getName());
                //Draw card
                Card currentCard = m_deck.front();
                m_deck.pop();
                //Play card
                currentCard.applyEncounter(*currentPlayer);
                //Return card to back of deck
                m_deck.push(currentCard);
            }
            if ((*currentPlayer).getLevel() == Player::MAX_LEVEL) {
                m_winners.push_back(currentPlayer);
            }
            else if ((*currentPlayer).isKnockedOut()) {
                m_losers.insert(m_losers.begin(), currentPlayer);
            }
        }
        m_numRounds++;
    }
    if (isGameOver()) { //Maybe needs to be inside if(), depends if this function is called on a game that is over and the message is required or not
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderboardStartMessage();
    int playerCounter = 1;
    //Prints winners
    for (const std::shared_ptr<Player>& currentPlayer : m_winners) {
        printPlayerLeaderboard(playerCounter, (*currentPlayer))
        playerCounter++;
    }
    //Prints current players by their turn
    for (const std::shared_ptr<Player>& currentPlayer : m_players) {
        if (((*currentPlayer).getLevel() != Player::MAX_LEVEL) && (!(*currentPlayer).isKnockedOut())) {
            printPlayerLeaderboard(playerCounter, (*currentPlayer))
            playerCounter++;
        }
    }
    //Prints losers
    for (const std::shared_ptr<Player>& currentPlayer : m_losers) {
        printPlayerLeaderboard(playerCounter, (*currentPlayer))
        playerCounter++;
    }
}

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

int Mtmchkin::getNumberOfRounds() const
{
    return m_numRounds;
}

//------------------------------------------Additional Functions-------------------------------------

template <class Derived>
Card* creationFactory()
{
    Card* currentCard = new Derived;
    if (!currentCard) {
        delete currentCard;
        throw std::bad_alloc();
    }
    return currentCard;
}

std::queue<Card> createDeck(const std::ifstream& sourceFile)
{
    //Initiate card dictionary
    std::map<std::string, Card*(*)()> cardDictionary;
    cardDictionary["Barfight"] = &creationFactory<Barfight>;
    cardDictionary["Dragon"] =  &creationFactory<Dragon>;
    cardDictionary["Fairy"] =  &creationFactory<Fairy>;
    cardDictionary["Goblin"] =  &creationFactory<Goblin>;
    cardDictionary["Merchant"] =  &creationFactory<Merchant>;
    cardDictionary["Pitfall"] =  &creationFactory<Pitfall>;
    cardDictionary["Treasure"] =  &creationFactory<Treasure>;
    cardDictionary["Vampire"] =  &creationFactory<Vampire>;

    std::queue<Card> cardDeck;
    std::string line;
    int lineCounter = 0;
    while (std::getline(sourceFile, line)) {
        lineCounter++;
        if (cardDictionary.contains(line)) {
            Card* currentCard = cardDictionary[line]();
            cardDeck.push(*currentCard);
            delete currentCard;
        }
        else {
            throw DeckFileFormatError(lineCounter);
        }
    }
    return std::move(cardDeck);
}


std::queue<std::shared_ptr<Player>> createPlayers()
{
    std::queue<std::shared_ptr<Player>> tmpPlayers;
    //Print opening game message
    printStartGameMessage();
    //Receives and validates team size from user
    int teamSize = receiveTeamSize();
    std::string name;
    std::string job;
    for (int i = 0; i < teamSize; i++) {
        receivePlayer(name, job);

        //Create player according to job
        switch (*job) {
            case "Fighter":
                std::shared_ptr<Player> ptrNewPlayer(new Fighter(name));
                break;
            case "Rogue":
                std::shared_ptr<Player> ptrNewPlayer(new Rogue(name));
                break;
            case "Wizard":
                std::shared_ptr<Player> ptrNewPlayer(new Wizard(name));
                break;
        }
        tmpPlayers.push(ptrNewPlayer);
    }
    return std::move(tmpPlayers);
}

int receiveTeamSize()
{
    int teamSize;
    //Ask user for team size
    printEnterTeamSizeMessage();
    std::cin >> teamSize;
    //If input was invalid (not an int or not in valid team size range) ask for new input
    while ((!std::cin.good()) || (teamSize < 2) || (teamSize > 6)) {
        //Ask user for team size
        printInvalidTeamSize();
        printEnterTeamSizeMessage();

        //Clears error flags on cin
        std::cin.clear();
        //Clears buffer before taking in new line
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cin >> teamSize;
    }
    return teamSize;
}

void receivePlayer(std::string& name, std::string& job)
{
    //Ask user for player's details
    printInsertPlayerMessage();
    std::cin >> name >> job;
    //Check input
    bool validName = checkName(name);
    bool validJob = checkJob(job);
    //If input was invalid (not a valid name or job) ask for new input
    while ((!std::cin.good()) || (!validName) || (!validJob)) {
        printMessages(validName, validJob);
        //Clears error flags on cin
        std::cin.clear();
        //Clears buffer before taking in new line
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cin >> name >> job;
        //Check input
        validName = checkName(name);
        validJob = checkJob(job);
    }
}

//Validates the name from input
bool checkName(const std::string& givenName)
{
    if (givenName.size() > 15) {
        return false;
    }
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
    //Ask user for player's details
    printInsertPlayerMessage();
}