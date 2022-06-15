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

#include "Mtmchkin.h"

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


//Fighter Tests
   /* barfightCard.applyEncounter(Waldo);
    goblinCard.applyEncounter(Waldo);
    std::cout << Waldo << std::endl;
    Waldo.pay(10);
    std::cout << Waldo << std::endl;
    merchCard.applyEncounter(Waldo);
    treasureCard.applyEncounter(Waldo);
    std::cout << Waldo << std::endl;
    vampCard.applyEncounter(Waldo);
    std::cout << Waldo << std::endl;
    int attackStrength = Waldo.getAttackStrength();
    std::cout << "Waldo's attack strength: " << attackStrength << std::endl;
    dragonCard.applyEncounter(Waldo); */

//Rogue Tests
   /* goblinCard.applyEncounter(Freddy);
    std::cout << Freddy << std::endl;
    Freddy.pay(10);
    std::cout << Freddy << std::endl;
    merchCard.applyEncounter(Freddy);
    treasureCard.applyEncounter(Freddy);
    std::cout << Freddy << std::endl;
    vampCard.applyEncounter(Freddy);
    std::cout << Freddy << std::endl;
    pitfallCard.applyEncounter(Freddy);
    dragonCard.applyEncounter(Freddy); */

    vampCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;
    vampCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;
    Tal.pay(5);
    std::cout << Tal << std::endl;
    merchCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;
    treasureCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;
    fairyCard.applyEncounter(Tal);
    vampCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;
    dragonCard.applyEncounter(Tal);

  /*  dragonCard.applyEncounter(Waldo);
    fairyCard.applyEncounter(Freddy);

    goblinCard.applyEncounter(Tal);
        std::cout << Tal << std::endl;
    fairyCard.applyEncounter(Tal);
    std::cout << "Ensure that a wizard's HP is doubled:" << std::endl;
    std::cout << Tal << std::endl;
    Waldo.heal(Player::DEFAULT_MAX_HP);

    goblinCard.applyEncounter(Waldo); 
    goblinCard.applyEncounter(Freddy);
    std::cout << "Ensure that he gets double the loot: " << Freddy << std::endl;
    treasureCard.applyEncounter(Tal);

    merchCard.applyEncounter(Freddy);
    std::cout << Freddy << std::endl;
    merchCard.applyEncounter(Tal);
    std::cout << Tal << std::endl;

    pitfallCard.applyEncounter(Tal);
    pitfallCard.applyEncounter(Freddy);

    barfightCard.applyEncounter(Waldo);
    barfightCard.applyEncounter(Freddy);

    std::cout << Tal << std::endl;

    vampCard.applyEncounter(Tal);*/

    return 0;
}