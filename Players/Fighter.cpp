#include "Fighter.h"

//Constructor
Fighter::Fighter(const std::string givenName) :
    Player(givenName)
{}

//Returns the player's job
std::string Fighter::getJob() const
{
    std::string job("Fighter");
    return job;
}

//Override Player method - Return the attack strength = player's force * 2 + player's level
int Player::getAttackStrength() const
{
    return (this->getLevel() + (m_force * 2));
}