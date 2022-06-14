#include "Barfight.h"

//Constructor
Barfight::Barfight()
{
    m_name = "Barfight";
}

//Apply Encounter Function
void Barfight::applyEncounter(Player& player) const
{
    bool isFighter = (player.getJob() == "Fighter");
    if (!isFighter) {
        player.damage(HP_LOSS);
    }
    printBarfightMessage(isFighter);
}
