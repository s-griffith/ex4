#include "Vampire.h"

Vampire::Vampire() 
{
    m_force = VAMPIRE_FORCE;
    m_hpLossOnDefeat = VAMPIRE_HP_LOSS;
    m_loot = VAMPIRE_LOOT;
}

//Handles a player's encounter with a vampire during the game
void Vampire::applyEncounter(Player& player) const 
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), this->getName());
    }
    else {
        player.buff(-1);
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.getName(), this->getName());
    }
}

//Returns the name of the card as a string
std::string Vampire::getName() const
{
    return "Vampire";
}