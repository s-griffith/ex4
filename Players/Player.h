#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <iostream>
#include <string>

/*
 *  Player:
 *  This class represents a single player in the game.
*/

class Player {
public:

    //Constant value for the maximum level a player can achieve
    //Default values for the maximum HP amount and the default force
    //Starting values for the number of coins and player level
    static const int MAX_LEVEL = 10;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int STARTING_COINS = 10;
    static const int STARTING_LEVEL = 1;
    static const int DEFAULT_COINS = 10;

    /*
     * C'tor of Player class
     *
     * @param name - The name of the player
     * @param HP - Starting amount of health points, between [0, maxHP], default is 100
     * @param force - Starting force, default is 5
     * @return
     *      A new instance of Player.
    */
    Player(const std::string givenName);

    /*
     * Increasing the player's level by one
     * @return
     *      void
    */
    void levelUp();

    /*
     * Return the player's current level
     * @return
     *      int - the current level
    */
    int getLevel() const;

    /*
     * Return the player's job: pure virtual method
     * @return
     *      string - the player's job
    */
    virtual std::string getJob() const = 0;

    /*
    * Return the number of coins the player has
    * @return
    *      int - the current number of coins
    */
    int getCoins() const;

    /*
    * Return the name of the player
    * @return
    *      string - the name of the player
    */
    std::string getName() const;

    /*
     * Increases the player's force by the given amount
     * @return
     *      void
    */
    void buff(const int increaseForce);

    /*
     * Increases the player's health points by the given amount, until maxHP reached
     * @return
     *      void
    */
    virtual void heal(const int increaseHP);

    /*
     * Decrease the player's health points by the given amount, until the value 0
     * @return
     *      void
    */
    void damage(const int decreaseHP);

    /*
     * Checks if the player's health points has reached 0
     * @return
     *      boolean value - return true if the HP is 0, otherwise return false
    */
    bool isKnockedOut() const;

    /*
     * Adds the given amount of coins to the player's purse
     * @return
     *      void
    */
    virtual void addCoins(const int increaseCoins);

    /*
     * Removes the requested amount of coins from the player's purse
     * @return
     *      boolean value - return true if the payment was completed successfully, otherwise return false
    */
    bool pay(const int decreaseCoins);

    /*
     * Return the attack strength = player's force + player's level
     * @return
     *      the calculated attach strength
    */
    virtual int getAttackStrength() const;

    /*
    * Print the player's details using print method in 'utilities.h'
    * @return
    *      reference to ostream for chaining
    */
    friend std::ostream& operator<<(std::ostream& os, const Player& currentPlayer);

    /*
     * Here we are explicitly telling the compiler to use the default methods
     *      for the copy constructor, destructor and the override of the "=" operator
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

protected:
    int m_force;
    int m_hp;
    int m_coins;
    int m_maxHP;
private:
    std::string m_name;
    int m_level;
};

#endif //EX4_PLAYER_H
