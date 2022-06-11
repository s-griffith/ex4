#include "Wizard.h"

//Constructor
Wizard::Wizard(const std::string givenName) :
    Player(givenName)
{}

//Returns the player's job
std::string Rogue::getJob() const
{
    std::string job("Wizard");
    return job;
}

// Override Player method - Increases the player's health points by double the given amount, until maxHP reached
void heal(const int increaseHP)
{
    int doubleIncrease = increaseHP * 2;
    if (doubleIncrease >= 0) {
        if ((m_hp + doubleIncrease) > m_maxHP) {
            m_hp = m_maxHP;
        }
        else {
            m_hp += doubleIncrease;
        }
    }
}