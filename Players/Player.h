#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include "../utilities.h"

/*
 *  Player:
 *  This class represents a single player in the game.
*/

class Player {
public:

    //Constant value for the maximum level a player can achieve
    //Default values for the maximum HP amount and the default force if the input from the user is not valid
    static const int MAX_LEVEL = 10;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;

    /*
     * C'tor of Player class
     *
     * @param name - The name of the player
     * @param HP - Starting amount of health points, between [0, maxHP], default is 100
     * @param force - Starting force, default is 5
     * @return
     *      A new instance of Player.
    */
    Player(const char* givenName, int givenMaxHP = DEFAULT_MAX_HP, int givenForce = DEFAULT_FORCE);


    /*
     * Prints the Player info
     *
     * @return
     *      void
    */
    void printInfo() const;


    /*
     * Increasing the player's level by one
     *
     * @return
     *      void
    */
    void levelUp();


    /*
     * Return the player's current level
     *
     * @return
     *      int - the current level
    */
    int getLevel() const;


    /*
     * Increases the player's force by the given amount
     *
     * @return
     *      void
    */
    void buff(const int increaseForce);


    /*
     * Increases the player's health points by the given amount, until maxHP reached
     *
     * @return
     *      void
    */
    void heal(const int increaseHP);


    /*
     * Decrease the player's health points by the given amount, until the value 0
     *
     * @return
     *      void
    */
    void damage(const int decreaseHP);


    /*
     * Checks if the player's health points has reached 0
     *
     * @return
     *      boolean value - return true if the HP is 0, otherwise return false
    */
    bool isKnockedOut() const;


    /*
     * Adds the given amount of coins to the player's purse
     *
     * @return
     *      void
    */
    void addCoins(const int increaseCoins);


    /*
     * Removes the requested amount of coins from the player's purse
     *
     * @return
     *      boolean value - return true if the payment was completed successfully, otherwise return false
    */
    bool pay(const int decreaseCoins);


    /*
     * Return the attack strength = player's force + player's level
     *
     * @return
     *      the calculated attach strength
    */
    int getAttackStrength() const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
     *      for the copy constructor, destructor and the override of the "=" operator
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    int m_maxHP;
};

#endif //EX2_PLAYER_H
