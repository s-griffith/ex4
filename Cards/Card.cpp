#include <iostream>
#include "Card.h"

//----------------------------------Card Class Functions----------------------------------

//Prints general card details
void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, this->getName());
    printEndOfCardDetails(os);
}

//An empty function that prevents the Card class from being abstract
void Card::applyEncounter(Player& player) const
{}

//----------------------------------Card Class Non-Member Function----------------------------------

//Overrides the << operator to allow seamless printing
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}


//----------------------------------MonsterCards Class Functions----------------------------------

//Prints the details specific to monster cards
void MonsterCards::printInfo(std::ostream &os) const
{
    bool isDragon = false;
    printCardDetails(os, this->getName());
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
    printEndOfCardDetails(os);
}

//Handles a player's encounter with a monster during the game
void MonsterCards::applyEncounter(Player& player) const 
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), this->getName());
    }
    else {
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.getName(), this->getName());
    }
}

int MonsterCards::getForce() const
{
    return m_force;
}

int MonsterCards::getDamage() const
{
    return m_hpLossOnDefeat;
}

std::string MonsterCards::getName() const
{
    return "MonsterCards";
}

//----------------------------------MonsterCards Class Non-Member Function----------------------------------

//Overrides the << operator to allow seamless printing
std::ostream& operator<<(std::ostream& os, const MonsterCards& card)
{
    card.MonsterCards::printInfo(os);
    return os;
}