#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

//Check if they want us to create operator << for printing

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

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
     * C'tor to the "default card" - Treasure card that gives 0 coins - Check if still need this default card!!
    */
    Card(): m_effect(CardType::Treasure), m_stats() {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;


protected:
    std::string m_name;

};

/*
 * Numeric stats of a card. !!! Added this for now - may want to change this and/or check that we're allowed to use this!!!!
 */
struct CardStats{
    int force;  // The force of the monster
    int loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int hpLossOnDefeat; // The amount of hp you lose when losing the battle

    int cost; // The cost of a "Buff/Heal" card
    int heal; // The amount of HP you get when buying a "HEAL" card
    int buff; // The amount of force you get when buying a "BUFF" card


    /*
     *C'tor of CardStats:
     *
     * @param force - The force of the card (monster).
     * @param hpLoss - HP loss when losing the battle.
     * @param cost - The cost of the card when is type is "Buff" or "Heal".
     * @param heal - The amount of HP is given when buying a "Heal" card.
     * @param buff - The amount of force is given when buying a "Buff" card.
     * @param loot - The profit from winning a battle or when getting a "Treasure" card.
     * @return
     *      New instance of CardStats.
    */
    explicit CardStats(int force = 0, int hpLoss = 0, int cost = 0, int heal = 0, int buff = 0, int loot = 0) {
        this->force = force; //only relevant to the battleCards class
        this->hpLossOnDefeat = hpLoss;
        this->cost = cost; //only relevant to the merchant class
        this->heal = heal;
        this->buff = buff; //only relevant to the merchant class
        this->loot = loot;
    }
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


//Might not need the bool and/or this class at all
class BoostCards : public Card {
public:
    //which functions?

protected:
    bool m_add; //true: adds 10 hp, false: subtracts 10 hp
};


#endif //EX2_Card_H
