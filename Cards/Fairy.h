#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

const int HP_GAIN = 10;

/*
 *  Fairy Card Class:
 *  This class represents a single Fairy card.
*/
class Fairy : public BoostCards {
public:
    /*
     * Constructor of Fairy class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Fairy.
    */
    Fairy();

    /*
     * Destructor of Fairy class
    */    
    ~Fairy() = default;

    /*
     * Fairy has no logically changeable data, so we'll forbid the use of a copy constructor.
    */
    Fairy(const Fairy&) = delete;

    /*
     * Handling the player's applyEncounter with a Fairy card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
};

#endif //EX4_FAIRY_H
