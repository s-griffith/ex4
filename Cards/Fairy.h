#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"
#include "../Players/Player.h"
#include "../Players/Wizard.h"


/*
 *  Fairy Card Class:
 *  This class represents a single Fairy card.
*/
class Fairy : public Card {
public:

    static const int HP_GAIN = 10;

    /*
     * Constructor of Fairy class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Fairy.
    */
    Fairy() = default;

    /*
     * Destructor of Fairy class
    */    
    ~Fairy() = default;

    /*
     * Copy Constructor of Fairy class
    */
    Fairy(const Fairy&) = default;

    /*
     * Assignment Operator of Fairy class
    */
    Fairy& operator=(const Fairy& other) = default;

    /*
     * Handling the player's applyEncounter with a Fairy card:
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

#endif //EX4_FAIRY_H
