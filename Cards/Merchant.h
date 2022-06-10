#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

const int HEALTH_POTION_COST = 5;
const int HEALTH_POTION = 1;
const int FORCE_BOOST_COST = 10;
const int FORCE_BOOST = 1;

/*
 *  Merchant Card Class:
 *  This class represents a single Merchant card.
 *  Cards of this type allow players to buy boosts to their HP or force.
*/
class Merchant : public Card {
public:
    /*
     * Constructor of Merchant class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Merchant.
    */
    Merchant() = default;

    /*
     * Destructor of Merchant class
    */ 
    ~Merchant() = default;

    /*
     * Merchant has no logically changeable data, so we'll forbid the use of a copy constructor.
    */
    Merchant(const Merchant&) = delete;

    /*
     * Handling the player's applyEncounter with a Merchant card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;
};

#endif //EX4_MERCHANT_H
