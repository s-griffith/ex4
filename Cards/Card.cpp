#include <iostream>
#include "Card.h"
#include "../utilities.h"
#include "../Players/Player.h"

//----------------------------------Card Class Functions----------------------------------

//Constructor for Card
Card::Card()
{
    m_name = "Card";
}

//Encounter a card - play the card according to its type.
void Card::applyEncounter(Player& player) const
{
    //Checks if the player has enough coins to pay. Performs the required actions accordingly.
    if (player.pay(m_stats.cost)) {
        if (m_effect == CardType::Heal) {
            player.heal(m_stats.heal);
        }
        else {
            player.buff(m_stats.buff);
        }
    }
}

//Print general card information: name
void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, m_name);
}


//----------------------------------MonsterCards Class Functions----------------------------------

void MonsterCards::printInfo(std::ostream &os) const
{
    bool isDragon = (m_name == "Dragon");
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
}

void MonsterCards::applyEncounter(Player& player) const 
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.m_name, m_name);
    }
    else {
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.m_name, m_name);
    }
}