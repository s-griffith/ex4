#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

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
     *      A new instance of Card.
    */
    Card() = default;

    /*
     * Copy Constructor of the Card class
    */
    Card(const Card&) = default;

    /*
     * Destructor of the Card class
    */
    virtual ~Card() = default;

    /*
     * Assignment Operator of the Card class
    */
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
     * Gets a string representing the card type:
     *
     * @return
     *      string
    */
    virtual std::string getName() const =0;
    
    /*
     * Overrides the operator << for printing card data:
     *
     * @param os - The output path
     * @param card - The card
     * @return
     *      os
    */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
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
    MonsterCards() = default;

    /*
     * Destructor of MonsterCards class
    */ 
    virtual ~MonsterCards() = default;

    /*
     * Copy constructor of MonsterCards class
    */
    MonsterCards(const MonsterCards&) = default;

    /*
     * Assignment Operator of MonsterCards class
    */
    MonsterCards& operator=(const MonsterCards& other) = default;

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
    virtual void printInfo(std::ostream &os) const override;

    int getForce() const;

    int getDamage() const;

    virtual std::string getName() const override; 

    int getLoot() const;


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
    int m_force = 0;    
    int m_loot = 0;
    int m_hpLossOnDefeat = 0;
};

#endif //EX2_Card_H
