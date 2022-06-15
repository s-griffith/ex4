#include "Barfight.h"

//Constructor
Barfight::Barfight()
{
    m_name = "Barfight";
}

//Apply Encounter Function
void Barfight::applyEncounter(Player& player) const
{
    bool isFighter = true;
    try {
        player = dynamic_cast<Fighter&>(player);
    } catch (std::bad_cast) {
        isFighter = false;
    }
    if (!isFighter) {
        player.damage(HP_LOSS);
    }
    printBarfightMessage(isFighter);
}
