#include "Fighter.h"

//Constructor
Fighter::Fighter(const std::string givenName) :
    Player(givenName)
{}

//Override Player method - Return the attack strength = player's force * 2 + player's level
int Fighter::getAttackStrength() const
{
    return (this->getLevel() + (m_force * 2));
}