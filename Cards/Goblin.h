#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"


/*
 *  Goblin Monster Class:
 *  This class represents a single Goblin card.
*/
class Goblin : public MonsterCards {
public:

    const int GOBLIN_FORCE = 6;
    const int GOBLIN_LOOT = 2;
    const int GOBLIN_HP_LOSS = 10;

    /*
     * Constructor of Goblin class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Goblin with the appropriate values.
    */
    Goblin();

    /*
     * Destructor of Goblin class
    */
    ~Goblin() = default;

    /*
     * Copy constructor of Vampire class
    */
    Goblin(const Goblin&) = default;

    //Goblin has nothing special when encountered, so it can use the general Battle class applyEncounter.
};

#endif //EX4_GOBLIN_H
