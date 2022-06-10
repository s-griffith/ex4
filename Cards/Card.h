#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

//Check if they want us to create operator << for printing

/*
 *  Card Class:
 *  This class represents a single card in the game.
*/
class Card {
public:
    /*
     * C'tor of Card class
     *
     * Receives no parameters.
     * @return
     *      A general instance of Card, with the name "Card."
    */
    Card();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const=0;

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(std::ostream &os) const;

    /*
     * Overrides the operator << for printing card data:
     *
     * @param os - The output path
     * @param card - The card
     * @return
     *      os
    */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

protected:
    /*
     * An internal field that holds the name of the type of card
    */    
    std::string m_name;
};

/*
 *  Monster Cards Class:
 *  This class represents a single type of Monster card: Vampire, Goblin, or Dragon.
*/
class MonsterCards : public Card {
public:
    /*
     * Constructor of MonsterCards class
     *
     * Receives no parameters.
     * @return
     *      A new instance of MonsterCards with no appropriated values.
    */
    MonsterCards() = default; //Check that there is no pre-set default monster card

    /*
     * Destructor of MonsterCards class
    */ 
    virtual ~MonsterCards() = default;

    /*
     * Copy constructor of MonsterCards class
    */
    MonsterCards(const MonsterCards&) = default;

    /*
     * Handling the player's applyEncounter with a general MonsterCards card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const override;

    /*
     * Prints the basic information associated with a MonsterCards card:
     *
     * @param std::ostream &os - The output path/file.
     * @return
     *      void
    */
    void printInfo(std::ostream &os) const override;

    /*
     * Overrides the operator << for printing monster card data:
     *
     * @param os - The output path
     * @param card - The card
     * @return
     *      os
    */
    friend std::ostream& operator<<(std::ostream& os, const MonsterCards& card);

protected:
    /*
     * The internal fields associated with a MonsterCards card:
     * m_force: The force a monster has during battle
     * m_loot: The coins won by a player after defeating the monster in battle
     * m_hpLossOnDefeat: The HP damage done by a monster if the player is defeated in battle
    */
    int m_force;    
    int m_loot;
    int m_hpLossOnDefeat;
};

#endif //EX2_Card_H
