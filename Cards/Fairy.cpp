#include "Fairy.h"

//Handles a player's encounter with a fairy during the game
void Fairy::applyEncounter(Player& player) const
{   
    bool isWizard = true;
    //Check if the player is a wizard:
    try {
        player =  dynamic_cast<Wizard&>(player);
    } catch(const std::bad_cast&) {
        isWizard = false;
    }
    if (isWizard) {
        player.heal(HP_GAIN);
    }
    printFairyMessage(isWizard);
}

//Returns the name of the card as a string
std::string Fairy::getName() const
{
    return "Fairy";
}