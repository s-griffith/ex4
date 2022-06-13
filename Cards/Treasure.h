#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

/*
 *  Treasure Card Class:
 *  This class represents a single Treasure card.
 *  Cards of this type give 10 coins when encountered by a player.
*/
class Treasure : public Card {
public:

    const int TREASURE_LOOT = 10;

    /*
     * Constructor of Treasure class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Treasure.
    */
    Treasure();

    /*
     * Destructor of Treasure class
    */    
    ~Treasure() = default;

    /*
     * Treasure has no logically changeable data, so we'll forbid the use of a copy constructor.
    */  
    Treasure(const int&) = delete;

    /*
     * Handling the player's applyEncounter with a Treasure card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

};

#endif //EX4_TREASURE_H
