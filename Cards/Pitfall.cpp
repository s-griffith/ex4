#include "Pitfall.h"

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

std::string Pitfall::getName() const
{
    return "Pitfall";
}