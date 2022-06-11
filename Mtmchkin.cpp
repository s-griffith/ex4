#include "Mtmchkin.h"

//Left to do: Leaderboard (maybe array of pointers? rank for each player?)
//              Exceptions: DeckFileFormatError where to add?

//------------------------------------------Additional Functions-------------------------------------
Queue<Card>& createDeck(const std::ifstream& sourceFile);
Queue<Player>& createPlayers();
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
    m_deck = createDeck(sourceFile);
    if (m_deck.size() < 5) {
        throw DeckFileInvalidSize();
    }
    m_players = createPlayers();
    m_numRounds = 0;
}

void Mtmchkin::playRound()
{
    if (!isGameOver()) {
        //Print that another round has started
        printRoundStartMessage();
        for (Player& currentPlayer : m_players) {
            if ((currentPlayer.getLevel() != Player::MAX_LEVEL) && (!currentPlayer.isKnockedOut())) {
                //Print player's turn
                printTurnStartMessage(currentPlayer.getName());
                //Draw card
                Card* currentCard = &(m_deck.front()); //make sure we can point to a reference
                m_deck.popFront();
                //Play card
                currentCard.applyEncounter(currentPlayer);
                //Return card to back of deck
                m_deck.pushBack(*currentCard);
            }
        }
    }
    if (isGameOver()) { //Maybe needs to be inside if(), depends if this function is called on a game that is over and the message is required or not
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const //Temp print, needs to be in different player order by their ranking
{
    printLeaderboardStartMessage();
    int playerCounter = 1;
    for (Player& currentPlayer : m_players) {
        printPlayerLeaderboard(playerCounter, currentPlayer)
    }
}

bool Mtmchkin::isGameOver() const
{
    bool gameOver = true;
    for (Player& currentPlayer : m_players) {
        if ((currentPlayer.getLevel() != Player::MAX_LEVEL) && (!currentPlayer.isKnockedOut())) {
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

Queue<Card>& createDeck(const std::ifstream& sourceFile)
{
    Queue<Card> cardDeck;
    std::string line;
    while (std::getline(sourceFile, line)) {
        Card* currentCard;
        //More elegant than switch-case if we have time:
        // https://stackoverflow.com/questions/954548/how-to-pass-a-function-pointer-that-points-to-constructor
        switch (line) {
            case "Barfight":
                currentCard = new Barfight();
            case "Dragon":
                currentCard = new Dragon();
            case "Fairy":
                currentCard = new Fairy();
            case "Goblin":
                currentCard = new Goblin();
            case "Merchant":
                currentCard = new Merchant();
            case "Pitfall":
                currentCard = new Pitfall();
            case "Treasure":
                currentCard = new Treasure();
            case "Vampire":
                currentCard = new Vampire();
            //What to do if the line holds invalid card name? https://piazza.com/class/l0tbx31evh31vr?cid=1041
        }
        cardDeck.pushback(*currentCard);
        delete currentCard;
    }
    return cardDeck;
}

Queue<Player>& createPlayers()
{
    Queue<Player> tmpPlayers;
    //Print opening game message
    printStartGameMessage();
    //Receives and validates team size from user
    int teamSize = receiveTeamSize();
    std::string* name;
    std::string* job;
    for (int i = 0; i < teamSize; i++) {
        receivePlayer(name, job);

        //Create player according to job
        switch (*job) {
            case "Fighter":
                Fighter newPlayer(*name);
                break;
            case "Rogue":
                Rogue newPlayer(*name);
                break;
            case "Wizard":
                Wizard newPlayer(*name);
                break;
        }
        tmpPlayers.pushback(newPlayer);
    }
    return tmpPlayers;
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

void receivePlayer(std::string *name, std::string *job)
{
    //Ask user for player's details
    printInsertPlayerMessage();
    std::cin >> (*name) >> (*job);
    //Check input
    bool validName = checkName(*name);
    bool validJob = checkJob(*job);
    //If input was invalid (not an int or not in valid team size range) ask for new input
    while ((!std::cin.good()) || (!validName) || (!validJob)) {
        printMessages(validName, validJob);

        //Clears error flags on cin
        std::cin.clear();
        //Clears buffer before taking in new line
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cin >> (*name) >> (*job);

        //Check input
        validName = checkName(*name);
        validJob = checkJob(*job);
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

//Validates the name from input
bool checkJob(const std::string& givenJob)
{
    if ((givenJob.compare("Fighter") != 0) && (givenJob.compare("Rogue") != 0) && (givenJob.compare("Wizard") != 0)) {
        return false;
    }
    return true;
}

void printMessages(const bool validName, const bool validJob)
{
    if (!validName) {
        printInvalidName();
    }
    else if (!validJob) {
        printInvalidClass();
    }
    //Ask user for team size
    printInsertPlayerMessage();
}