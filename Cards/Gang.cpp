#include "Gang.h"
#include <iostream>

std::map<std::string, std::unique_ptr<MonsterCards>(*)()> createMonsterCardDictionary();
std::unique_ptr<MonsterCards> creationMonsterFactory();

Gang::Gang(const std::vector<std::string> &cards)
{
    std::map<std::string, std::unique_ptr<MonsterCards>(*)()> cardDictionary = createMonsterCardDictionary();
    for (const std::string &line : cards) {
        m_cards.push_back(std::move(cardDictionary[line]()));
    }
}


void Gang::applyEncounter(Player& player) const
{
    bool win = true;
    for (const std::unique_ptr<MonsterCards> &currentCard : m_cards) {
        if (win) {
            win = (player.getAttackStrength() >= (*currentCard).getForce());
            (*currentCard).applyEncounter(player);
        }
        if (!win) {
            player.damage((*currentCard).getDamage());
        }
    }
    if (win) {
        player.levelUp();
    }
}

void Gang::printInfo(std::ostream &os) const
{
    printCardDetails(std::cout, (*this).getName());
    for (const std::unique_ptr<MonsterCards> &currentCard : m_cards) {
        (*currentCard).printInfo(os);
    }
    printEndOfCardDetails(os);
}

std::string Gang::getName() const 
{
    return "Gang";
}

std::ostream& operator<<(std::ostream& os, const Gang& cards)
{
    cards.printInfo(os);
    return os;
}

//Factory function for creating cards according to the appropriate derived class
template <class Derived>
std::unique_ptr<MonsterCards> creationMonsterFactory()
{
    std::unique_ptr<MonsterCards> currentCard(new Derived);
    //Move card (not copy)
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