#include "Gang.h"
#include <iostream>

//------------------------------------------Additional Functions-----------------------------------
std::map<std::string, std::unique_ptr<MonsterCards>(*)()> createMonsterCardDictionary();
std::unique_ptr<MonsterCards> creationMonsterFactory();
//-------------------------------------------------------------------------------------------------

//------------------------------------------Gang Class Member Functions-----------------------------------

//Constructor of gang
Gang::Gang(const std::vector<std::string> &cards)
{
    //Initiate monster card dictionary
    std::map<std::string, std::unique_ptr<MonsterCards>(*)()> cardDictionary = createMonsterCardDictionary();
    //Add monster cards to card vector according to the list of card names (validated in Mtmchkin)
    for (const std::string &line : cards) {
        m_cards.push_back(std::move(cardDictionary[line]()));
    }
}

// Handling the player's applyEncounter with a Gang card
void Gang::applyEncounter(Player& player) const
{
    bool win = true;
    std::string monsterName;
    //Go through monsters in gang
    for (const std::unique_ptr<MonsterCards> &currentCard : m_cards) {
        monsterName = (*currentCard).getName();
        //If the player won the battle, win the loot!
        if (win) {
            win = (player.getAttackStrength() >= (*currentCard).getForce());
            if (win) {
                player.addCoins((*currentCard).getLoot());
            }
        }
        //Otherwise, receive damage and print battle loss details
        if (!win) {
            if (!(player.isKnockedOut())) {
                player.damage((*currentCard).getDamage());
            }
            printLossBattle(player.getName(), monsterName);
        }
    }
    //If player beat the game, print the winning battle information and increase player level
    if (win) {
        printWinBattle(player.getName(), (*this).getName());
        player.levelUp();
    }
}

//Prints the gang's information
void Gang::printInfo(std::ostream &os) const
{
    printCardDetails(std::cout, (*this).getName());
    for (const std::unique_ptr<MonsterCards> &currentCard : m_cards) {
        (*currentCard).printInfo(os);
    }
    printEndOfCardDetails(os);
}

// Gets a string representing the card type
std::string Gang::getName() const
{
    return "Gang";
}

//------------------------------------------Gang Class Non-Member Function-----------------------------------

// Sends to output the string representation of the gang
std::ostream& operator<<(std::ostream& os, const Gang& cards)
{
    cards.printInfo(os);
    return os;
}

//------------------------------------------Additional Functions-----------------------------------

//Factory function for creating cards according to the appropriate derived class
template <class Derived>
std::unique_ptr<MonsterCards> creationMonsterFactory()
{
    std::unique_ptr<MonsterCards> currentCard(new Derived);
    return currentCard;
}

//Create dictionary of cards: between their name (string) and a factory function to create the cards
std::map<std::string, std::unique_ptr<MonsterCards>(*)()> createMonsterCardDictionary() 
{
    std::map<std::string, std::unique_ptr<MonsterCards>(*)()> cardDictionary;
    cardDictionary["Dragon"] =  &creationMonsterFactory<Dragon>;
    cardDictionary["Goblin"] =  &creationMonsterFactory<Goblin>;
    cardDictionary["Vampire"] =  &creationMonsterFactory<Vampire>;
    return cardDictionary;
}