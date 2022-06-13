#include "Pitfall.h"
#include "../Players/Player.h"

//Constructor
Pitfall::Pitfall() 
{
    m_name = "Pitfall";
}

//Apply Encounter Function
void Pitfall::applyEncounter(Player& player) const
{
    bool isRogue = (player.getName() == "Rogue");
    if (!isRogue) {
        player.damage(HP_LOSS);
    }
    printPitfallMessage(isRogue);
}