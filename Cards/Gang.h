#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"
#include <vector>
#include <memory>
#include <map>


class Gang : public Card {
public:

    /*
     * Constructor of Gang class
     *
     * Receives no parameters.
     * @return
     *      A new instance of Gang with the appropriate values.
    */
    Gang(const std::vector<std::string> &cards);

    /*
     * Destructor of Gang class
    */ 
    ~Gang() = default;

    /*
     * Copy constructor of Gang class
    */  
    Gang(const Gang&) = default;

    /*
     * Assignment Operator of Gang class
    */
    Gang& operator=(const Gang& other) = default;

    /*
     * Handling the player's applyEncounter with a Gang card:
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
    
    friend std::ostream& operator<<(std::ostream& os, const Gang& cards);

private:
    std::vector<std::unique_ptr<MonsterCards>> m_cards;
};

#endif //EX4_GANG_H