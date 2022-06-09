#include <iostream>
#include "Card.h"
#include "../utilities.h"
#include "../Players/Player.h"

//Change Functions used after implement the different types of cards. Need to see more what each one does/has.

//Constructor for Card
Card::Card()
{
    m_name = "Card";
}

//Encounter a card - play the card according to its type.
void Card::applyEncounter(Player& player) const
{
    if (m_effect == CardType::Battle) {
        bool win = (player.getAttackStrength() >= m_stats.force);
        printBattleResult(win);
        if (win) {
            player.levelUp();
            player.addCoins(m_stats.loot);
        }
        else {
            player.damage(m_stats.hpLossOnDefeat);
        }
    }
    else if (m_effect == CardType::Treasure) {
        player.addCoins(m_stats.loot);
    }
    //Checks if the player has enough coins to pay. Performs the required actions accordingly.
    else {
        if (player.pay(m_stats.cost)) {
            if (m_effect == CardType::Heal) {
                player.heal(m_stats.heal);
            }
            else {
                player.buff(m_stats.buff);
            }
        }
    }
}

//Print general card information: name
void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, m_name);
}

void MonsterCards::printInfo(std::ostream &os) const
{
    bool isDragon = (m_name == "Dragon");
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
}