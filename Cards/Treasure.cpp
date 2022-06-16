#include "Treasure.h"

//Handles a player's encounter with treasure during the game
void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(TREASURE_LOOT);
    printTreasureMessage();
}

//Returns the card name as a string
std::string Treasure::getName() const
{
    return "Treasure";
}