#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Card.h"
#include "../Players/Player.h"

/*
 *  Vampire Monster Class:
 *  This class represents a single Vampire card.
*/
class Vampire : public MonsterCards {
public:

    const int VAMPIRE_FORCE = 10;
    const int VAMPIRE_LOOT = 2;
    const int VAMPIRE_HP_LOSS = 10;

    /*
     * Constructor of Vampire class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Vampire with the appropriate values.
    */
    Vampire();

    /*
     * Destructor of Vampire class
    */      
    ~Vampire() = default;

    /*
     * Copy constructor of Vampire class
    */  
    Vampire(const Vampire&) = default;

    /*
     * Handling the player's applyEncounter with a Vampire card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
};

#endif //EX4_VAMPIRE_H
