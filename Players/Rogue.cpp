#include "Rogue.h"

//Constructor
Rogue::Rogue(const std::string givenName) :
    Player(givenName)
{}

//Override Player method - adds double the given amount of coins to the rogue's purse
void Rogue::addCoins(const int increaseCoins)
{
    int newIncrease = (increaseCoins * 2);
    if (newIncrease >= 0) {
        m_coins += (newIncrease);
    }
}

