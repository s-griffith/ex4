#include "Treasure.h"
#include "../Player.h"

//Constructor
Treasure::Treasure() : m_name("Treasure") {}

//Apply Encounter Function
void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(TREASURE_LOOT);
    printTreasureMessage();
}