#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Rogue.h"

/*
 *  Pitfall Card Class:
 *  This class represents a single Pitfall card.
 *  Cards of this type represent a player's falling into a pit and its consequences.
*/
class Pitfall : public Card {
public:

    static const int HP_LOSS = 10;

    /*
     * Constructor of Pitfall class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Pitfall.
    */
    Pitfall() = default;

    /*
     * Destructor of Pitfall class
    */
    ~Pitfall() = default;

    /*
     * Pitfall has no logically changeable data, so we'll forbid the use of a copy constructor.
    */
    Pitfall(const Pitfall&) = default;

    /*
     * Handling the player's applyEncounter with a Pitfall card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Gets a string representing the card type:
     *
     * @return
     *      string
    */
    std::string getName() const override;

};

#endif //EX4_PITFALL_H
