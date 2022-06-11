#include "Rogue.h"

//Constructor
Rogue::Rogue(const std::string givenName) :
    Player(givenName)
{}

//Returns the player's job
std::string Rogue::getJob() const
{
    std::string job("Rogue");
    return job;
}

//Override Player method - adds double the given amount of coins to the rogue's purse
void addCoins(const int increaseCoins)
{
    int newIncrease = increaseCoins * 2;
    if (newIncrease >= 0) {
        m_coins += (newIncrease * 2);
    }
}

