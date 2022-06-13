#include "Fairy.h"
#include "../Players/Player.h"

//Constructor
Fairy::Fairy()
{
    m_name = "Fairy";
}

//Apply Encounter Function
void Fairy::applyEncounter(Player& player) const
{
    bool isWizard = (player.getName() == "Wizard");
    if (isWizard) {
        player.heal(HP_GAIN); //assuming player has a specific overridden function for wizards, bc hp needs to be doubled
    }
    printFairyMessage(isWizard);
}
