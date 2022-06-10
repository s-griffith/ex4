#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

const int HP_LOSS = 10;

/*
 *  Barfight Card Class:
 *  This class represents a single Barfight card.
 *  Cards of this type represent a player's involvement in a bar fight and its consequences.
*/
class Barfight : public Card {
public:
    /*
     * Constructor of Barfight class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Barfight.
    */
    Barfight();

    /*
     * Destructor of Barfight class
    */    
    ~Barfight() = default;

    /*
     * Barfight has no logically changeable data, so we'll forbid the use of a copy constructor.
    */    
    Barfight(const Barfight&) = delete;

    /*
     * Handling the player's applyEncounter with a Barfight card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
};

#endif //EX4_BARFIGHT_H
