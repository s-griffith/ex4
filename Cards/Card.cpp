#include <iostream>
#include "Card.h"

//----------------------------------Card Class Functions----------------------------------

void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, this->getName());
}

//----------------------------------Card Class Non-Member Function----------------------------------

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printInfo(os);
    return os;
}


//----------------------------------MonsterCards Class Functions----------------------------------

void MonsterCards::printInfo(std::ostream &os) const
{
    bool isDragon = false;
    printCardDetails(os, this->getName());
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
}

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


//----------------------------------MonsterCards Class Functions----------------------------------

std::ostream& operator<<(std::ostream& os, const MonsterCards& card)
{
    card.MonsterCards::printInfo(os);
    return os;
}