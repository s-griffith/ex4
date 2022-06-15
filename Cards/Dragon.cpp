#include "Dragon.h"

//Constructor
Dragon::Dragon()
{
    m_name = "Dragon";
    m_force = DRAGON_FORCE;
    m_loot = DRAGON_LOOT;
}

//Apply Encounter Function
void Dragon::applyEncounter(Player& player) const
{
    bool win = (player.getAttackStrength() >= m_force);
    if (win) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_name);
    }
    else {
        player.damage(Player::DEFAULT_MAX_HP);
        printLossBattle(player.getName(), m_name);
    }
}

//Print info function
void Dragon::printInfo(std::ostream &os) const
{
    bool isDragon = true;
    printCardDetails(os, m_name);
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
}