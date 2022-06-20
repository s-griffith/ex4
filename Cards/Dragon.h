#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"
#include "../Players/Player.h"

/*
 *  Dragon Monster Class:
 *  This class represents a single Dragon card.
*/
class Dragon : public MonsterCards {
public:

    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;

    /*
     * Constructor of Dragon class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Dragon with the appropriate values.
    */
    Dragon();

    /*
     * Destructor of Dragon class
    */ 
    ~Dragon() = default;

    /*
     * Copy constructor of Dragon class
    */  
    Dragon(const Dragon&) = default;

    /*
     * Assignment Operator of Dragon class
    */
    Dragon& operator=(const Dragon& other) = default;

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo(std::ostream &os) const override;
    
    /*
     * Gets a string representing the card type:
     *
     * @return
     *      string
    */
    std::string getName() const override;
    
    friend std::ostream& operator<<(std::ostream& os, const Dragon& card);


};

#endif //EX4_DRAGON_H