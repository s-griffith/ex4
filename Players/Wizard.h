#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard : public Player {
public:
    //Constructor
    Wizard(const std::string givenName);

    /*
    * Return the player's job: "Wizard"
    * @return
    *      string - the player's job
    */
    std::string getJob() const;

    /*
     * Override Player method - Increases the player's health points by double the given amount, until maxHP reached
     * @return
     *      void
    */
    void heal(const int increaseHP);

    /*
     * Here we are explicitly telling the compiler to use the default methods
     *      for the copy constructor, destructor and the override of the "=" operator
    */
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard& original) = default;
    ~Wizard() = default;
private:
};


#endif //EX4_WIZARD_H