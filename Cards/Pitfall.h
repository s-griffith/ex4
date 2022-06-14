#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"
#include "../Players/Player.h"

/*
 *  Pitfall Card Class:
 *  This class represents a single Pitfall card.
 *  Cards of this type represent a player's falling into a pit and its consequences.
*/
class Pitfall : public Card {
public:

    const int HP_LOSS = 10;

    /*
     * Constructor of Pitfall class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Pitfall.
    */
    Pitfall();

    /*
     * Destructor of Pitfall class
    */
    ~Pitfall() = default;

    /*
     * Pitfall has no logically changeable data, so we'll forbid the use of a copy constructor.
    */
    Pitfall(const Pitfall&) = delete;

    /*
     * Handling the player's applyEncounter with a Pitfall card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

};

#endif //EX4_PITFALL_H
