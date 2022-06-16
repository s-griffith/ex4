#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"
#include "../Players/Player.h"

//Issue with this class: Dragon has no real need for hpLossOnDefeat. Making that an internal field though will change the entire implementation of everything else.

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
     * Handling the player's applyEncounter with a Dragon card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

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