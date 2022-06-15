#include "Pitfall.h"

//Constructor
Pitfall::Pitfall() 
{
    m_name = "Pitfall";
}

//Apply Encounter Function
void Pitfall::applyEncounter(Player& player) const
{
    bool isRogue = true;
    try {
        player = dynamic_cast<Rogue&>(player);
    } catch (std::bad_cast&) {
        isRogue = false;
    }
    if (!isRogue) {
        player.damage(HP_LOSS);
    }
    printPitfallMessage(isRogue);
}