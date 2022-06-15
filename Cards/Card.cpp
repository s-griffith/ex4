#include <iostream>
#include "Card.h"

//----------------------------------Card Class Functions----------------------------------

Card::Card()
{
    m_name = "Card";
}

void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, m_name);
}

std::string Card::getName() const
{
    return m_name;
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
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
}

void MonsterCards::applyEncounter(Player& player) const 
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    }
    else {
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.getName(), m_name);
    }
}


//----------------------------------MonsterCards Class Functions----------------------------------

std::ostream& operator<<(std::ostream& os, const MonsterCards& card)
{
    card.MonsterCards::printInfo(os);
    return os;
}