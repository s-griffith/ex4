#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Card.h"

//Issue with this class: Dragon has no real need for hpLossOnDefeat. Making that an internal field though will change the entire implementation of everything else.

/*
 *  Dragon Monster Class:
 *  This class represents a single Dragon card.
*/
class Dragon : public MonsterCards {
public:

    const int DRAGON_FORCE = 25;
    const int DRAGON_LOOT = 1000;

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
};

#endif //EX4_DRAGON_H