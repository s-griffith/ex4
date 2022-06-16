#include "Fighter.h"

Fighter::Fighter(const std::string givenName) :
    Player(givenName)
{}

//Returns the player's job as a string
std::string Fighter::getJob() const
{
    return "Fighter";
}

//Override Player method - Return the attack strength = player's force * 2 + player's level
int Fighter::getAttackStrength() const
{
    return (this->getLevel() + (m_force * 2));
}