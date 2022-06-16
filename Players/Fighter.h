#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

/*
 *  Fighter Player Class:
 *  This class represents a single Fighter.
 *  Players of this type have double the force.
*/
class Fighter : public Player {
public:
    /*
     * Constructor of Fighter class
     *
     * @param name - the player's name
     * @return
     *      A new instance of Fighter
    */
    Fighter(const std::string givenName);

    /*
    * Return the player's job: "Fighter"
    * @return
    *      string - the player's job
    */
    std::string getJob() const override;

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
