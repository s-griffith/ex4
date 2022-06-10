#include "Vampire.h"
#include "../Players/Player.h"

//Constructor
Vampire::Vampire() : m_name("Vampire"), m_force(VAMPIRE_FORCE), m_hpLossOnDefeat(VAMPIRE_HP_LOSS), m_loot(VAMPIRE_LOOT) 
{}

//Apply Encounter Function
void Vampire::applyEncounter(Player& player) const 
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.m_name, m_name);
    }
    else {
        player.m_force--;
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.m_name, m_name);
    }
}

