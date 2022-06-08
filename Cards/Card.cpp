#include <iostream>
#include "Card.h"
#include "../utilities.h"
#include "../Players/Player.h"

//Change Functions used after implement the different types of cards. Need to see more what each one does/has.

//Constructor for Card
Card::Card(CardType type, const CardStats& stats)
{
    m_effect = type;
    m_stats = stats;
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

//Print card information based on its type.
void Card::printInfo() const
{
    switch (m_effect) {
        case CardType::Battle: 
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
    }
}