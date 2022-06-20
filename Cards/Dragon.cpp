#include "Dragon.h"

//----------------------------------Dragon Class Member Functions----------------------------------

Dragon::Dragon()
{
    m_force = DRAGON_FORCE;
    m_loot = DRAGON_LOOT;
    m_hpLossOnDefeat = Player::DEFAULT_MAX_HP;
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