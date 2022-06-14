#include "Exception.h"
#include "utilities.h"

#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"

#include <iostream>

int main() {
    //-------------------------Printing & Construction Tests-------------------------
    std::cout << "-------------------------Printing & Construction Tests-------------------------" << std::endl;

    Fighter Waldo("Waldo");
    std::cout << Waldo << std::endl;
    Rogue Freddy("Freddy");
    std::cout << Freddy << std::endl;
    Wizard Tal("Tal");
    std::cout << Tal << std::endl;

    Barfight barfightCard;
    std::cout << barfightCard << std::endl;
    Dragon dragonCard;
    std::cout << dragonCard << std::endl;
    Fairy fairyCard;
    std::cout << fairyCard << std::endl;
    Goblin goblinCard;
    std::cout << goblinCard << std::endl;
    Merchant merchCard;
    std::cout << merchCard << std::endl;
    Pitfall pitfallCard;
    std::cout << pitfallCard << std::endl;
    Treasure treasureCard;
    std::cout << treasureCard << std::endl;
    Vampire vampCard;
    std::cout << vampCard << std::endl;

    //-------------------------Apply Encounter Tests-------------------------
    std::cout << "-------------------------Apply Encounter Tests-------------------------" << std::endl;

    dragonCard.applyEncounter(Waldo);
    fairyCard.applyEncounter(Freddy);
    fairyCard.applyEncounter(Tal);
    std::cout << "Ensure that a wizard's HP is doubled:" << std::endl;
    std::cout << Tal << std::endl;
    Waldo.heal(Player::DEFAULT_MAX_HP);

    goblinCard.applyEncounter(Waldo);
    treasureCard.applyEncounter(Tal);

    merchCard.applyEncounter(Freddy);
    std::cout << Freddy << std::endl;
    merchCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;

    pitfallCard.applyEncounter(Tal);
    pitfallCard.applyEncounter(Freddy);

    barfightCard.applyEncounter(Waldo);
    barfightCard.applyEncounter(Freddy);
    
    vampCard.applyEncounter(Tal);

    return 0;
}