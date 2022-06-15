#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Card.h"
#include "../Players/Player.h"

/*
 *  Goblin Monster Class:
 *  This class represents a single Goblin card.
*/
class Goblin : public MonsterCards {
public:

    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_HP_LOSS = 10;

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

    /*
     * Gets a string representing the card type:
     *
     * @return
     *      string
    */
    std::string getName() const override;
};

#endif //EX4_GOBLIN_H
