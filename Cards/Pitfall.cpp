#include "Pitfall.h"
#include "../Players/Player.h"

//Constructor
Pitfall::Pitfall() : m_name("Pitfall"), m_add(false) {}

//Apply Encounter Function
void Pitfall::applyEncounter(Player& player) const
{
    bool isRogue = (player.m_name == "Rogue");
    if (!isRogue) {
        player.damage(HP_LOSS);
    }
    printPitfallMessage(isRogue);
}