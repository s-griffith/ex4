#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player {
public:
    //Constructor
    Fighter(const std::string givenName);

    /*
    * Override Player method - Return the attack strength = player's force * 2 + player's level
    * @return
    *      the calculated attach strength
    */
    int getAttackStrength() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
     *      for the copy constructor, destructor and the override of the "=" operator
    */
    Fighter(const Fighter&) = default;
    Fighter& operator=(const Fighter& original) = default;
    ~Fighter() = default;
};


#endif //EX4_FIGHTER_H
