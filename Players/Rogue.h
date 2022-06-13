#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

class Rogue : public Player {
public:
    //Constructor
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

private:
};

#endif //EX4_ROGUE_H
