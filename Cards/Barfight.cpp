#include "Barfight.h"

//Handles a player's encounter with a barfight card during the game
void Barfight::applyEncounter(Player& player) const
{
    bool isFighter = true;
    //Check if the player given is a fighter:
    try {
        player = dynamic_cast<Fighter&>(player);
    }
    catch (std::bad_cast&) {
        isFighter = false;
    }
    if (!isFighter) {
        player.damage(HP_LOSS);
    }
    printBarfightMessage(isFighter);
}

//Returns the card name as a string
std::string Barfight::getName() const
{
    return "Barfight";
}