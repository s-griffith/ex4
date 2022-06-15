#include "Fairy.h"

//Apply Encounter Function
void Fairy::applyEncounter(Player& player) const
{   
    bool isWizard = true;
    try {
        player =  dynamic_cast<Wizard&>(player);
    } catch(const std::bad_cast&) {
        isWizard = false;
    }
    if (isWizard) {
        player.heal(HP_GAIN); //assuming player has a specific overridden function for wizards, bc hp needs to be doubled
    }
    printFairyMessage(isWizard);
}

std::string Fairy::getName() const
{
    return "Fairy";
}