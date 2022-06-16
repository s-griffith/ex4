#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

/*
 *  Rogue Player Class:
 *  This class represents a single Rogue.
 *  Players of this type receive double the loot.
*/
class Rogue : public Player {
public:

    /*
     * C'tor of Rogue class
     *
     * @param name - The name of the player
     * @return
     *      A new instance of Rogue.
    */
    Rogue(const std::string givenName);

    /*
     * Return the player's job: "Rogue"
     * @return
     *      string - the player's job
    */
    std::string getJob() const override;

    /*
    * Override Player method - adds double the given amount of coins to the rogue's purse
    * @return
    *      void
    */
    void addCoins(const int increaseCoins) override;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    *      for the copy constructor, the override of the "=" operator and the destructor
    */
    Rogue(const Rogue&) = default;
    Rogue& operator=(const Rogue& original) = default;
    ~Rogue() = default;
};

#endif //EX4_ROGUE_H
