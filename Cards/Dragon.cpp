#include "Dragon.h"
#include "../Players/Player.h"

//Constructor
Dragon::Dragon() : m_name("Dragon"), m_force(DRAGON_FORCE), m_loot(DRAGON_LOOT) {}

//Apply Encounter Function
void Dragon::applyEncounter(Player& player) const
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.m_name, m_name);
    }
    else {
        player.damage(player.m_maxHP);
        printLossBattle(player.m_name, m_name);
    }
}
