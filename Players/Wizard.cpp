#include "Wizard.h"

//Constructor of Wizard
Wizard::Wizard(const std::string givenName) :
    Player(givenName)
{}

//Returns the player's job
std::string Wizard::getJob() const
{
    return "Wizard";
}

//Override Player method - Increases the player's health points by double the given amount, until maxHP reached
void Wizard::heal(const int increaseHP)
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
