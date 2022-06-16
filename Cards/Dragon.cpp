#include "Dragon.h"

//Constructor
Dragon::Dragon()
{
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
        printWinBattle(player.getName(), this->getName());
    }
    else {
        player.damage(Player::DEFAULT_MAX_HP);
        printLossBattle(player.getName(), this->getName());
    }
}

//Print info function
void Dragon::printInfo(std::ostream &os) const
{
    bool isDragon = true;
    printCardDetails(os, this->getName());
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
    printEndOfCardDetails(os);
}

std::string Dragon::getName() const
{
    return "Dragon";
}

std::ostream& operator<<(std::ostream& os, const Dragon& card)
{
    card.Dragon::printInfo(os);
    return os;
}