#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"
#include "../Players/Player.h"
#include <iostream>

/*
 *  Merchant Card Class:
 *  This class represents a single Merchant card.
 *  Cards of this type allow players to buy boosts to their HP or force.
*/
class Merchant : public Card {
public:

    static const int HEALTH_POTION_COST = 5;
    static const int HEALTH_POTION = 1;
    static const int FORCE_BOOST_COST = 10;
    static const int FORCE_BOOST = 1;

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
     * Copy Constructor of Merchant class
    */
    Merchant(const Merchant&) = default;

    /*
     * Assignment Operator of Merchant class
    */
    Merchant& operator=(const Merchant& other) = default;

    /*
     * Handling the player's applyEncounter with a Merchant card:
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

#endif //EX4_MERCHANT_H
