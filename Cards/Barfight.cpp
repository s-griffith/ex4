#include "Barfight.h"
#include "../Players/Player.h"

//Constructor
Barfight::Barfight() : m_name("Barfight"), m_add(false) {}

//Apply Encounter Function
void Barfight::applyEncounter(Player& player) const
{
    bool isFighter = (player.m_name == "Fighter");
    if (!isFighter) {
        player.damage(HP_LOSS);
    }
    printBarfightMessage(isFighter);
}
