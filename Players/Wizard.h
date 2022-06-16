#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

/*
 *  Wizard Player Class:
 *  This class represents a single Wizard.
 *  Players of this type heal twice as fast.
*/
class Wizard : public Player {
public:

    /*
     * Constructor of Wizard class
     *
     * @param name - the player's name
     * @return
     *      A new instance of Wizard
    */
    Wizard(const std::string givenName);

    /*
    * Return the player's job: "Wizard"
    * @return
    *      string - the player's job
    */
    std::string getJob() const override;

    /*
     * Override Player method - Increases the player's health points by double the given amount, until maxHP reached
     * @return
     *      void
    */
    void heal(const int increaseHP) override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
     *      for the copy constructor, destructor and the override of the "=" operator
    */
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard& original) = default;
    ~Wizard() = default;
};


#endif //EX4_WIZARD_H
