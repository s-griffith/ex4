#include "Treasure.h"

//Apply Encounter Function
void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(TREASURE_LOOT);
    printTreasureMessage();
}

std::string Treasure::getName() const
{
    return "Treasure";
}