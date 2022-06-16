#include "Goblin.h"

Goblin::Goblin()
{
    m_force = GOBLIN_FORCE;
    m_hpLossOnDefeat = GOBLIN_HP_LOSS;
    m_loot = GOBLIN_LOOT;
}

//Returns the name of the card as a string
std::string Goblin::getName() const
{
    return "Goblin";
}