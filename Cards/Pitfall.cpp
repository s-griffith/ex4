#include "Pitfall.h"

//Handle's a player's encounter with a pitfall card during the game
void Pitfall::applyEncounter(Player& player) const
{
    bool isRogue = true;
    //Check if the player is a rogue:
    try {
        player = dynamic_cast<Rogue&>(player);
    }
    catch (std::bad_cast&) {
        isRogue = false;
    }
    if (!isRogue) {
        player.damage(HP_LOSS);
    }
    printPitfallMessage(isRogue);
}

//Returns the card name as a string
std::string Pitfall::getName() const
{
    return "Pitfall";
}