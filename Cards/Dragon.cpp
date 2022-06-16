#include "Dragon.h"

//----------------------------------Dragon Class Member Functions----------------------------------

Dragon::Dragon()
{
    m_force = DRAGON_FORCE;
    m_loot = DRAGON_LOOT;
}

//Handles a player's encounter with a dragon during the game
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

//Prints Dragon card information
void Dragon::printInfo(std::ostream &os) const
{
    bool isDragon = true;
    printCardDetails(os, this->getName());
    printMonsterDetails(os, m_force, m_hpLossOnDefeat, m_loot, isDragon);
    printEndOfCardDetails(os);
}

//Returns the name of the card as a string
std::string Dragon::getName() const
{
    return "Dragon";
}

//----------------------------------Dragon Class Non-Member Function----------------------------------

//Overrides operator << for seamless printing
std::ostream& operator<<(std::ostream& os, const Dragon& card)
{
    card.Dragon::printInfo(os);
    return os;
}