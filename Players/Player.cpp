#include "Player.h"
#include "../utilities.h"

//--------------------------------Helper Functions--------------------------------
int validateHP(int givenMaxHP);
int validateForce(int givenForce);
//--------------------------------------------------------------------------------


//Constructor for player
Player::Player(const std::string givenName)
{
    m_name = givenName;
    m_level = STARTING_LEVEL;
    m_force = DEFAULT_FORCE;
    m_hp = DEFAULT_MAX_HP;
    m_coins = DEFAULT_COINS;
    m_maxHP = DEFAULT_MAX_HP;
}

//Increases the player's level, until maximum level (10) is reached
void Player::levelUp()
{
    if (m_level < MAX_LEVEL) {
        m_level++;
    }
}

//Returns the player's current level
int Player::getLevel() const
{
    return m_level;
}

//Returns the number of coins the player has
int Player::getCoins() const
{
    return m_coins;
}

//Returns the name of the player
std::string Player::getName() const
{
    return m_name;
}

//Increases player's force by requested amount
void Player::buff(const int increaseForce)
{
    if (increaseForce >= 0) {
        m_force += increaseForce;
    }
}

//Increases player's Health Points by requested amount, until maximum is reached
void Player::heal(const int increaseHP)
{
    if (increaseHP >= 0) {
        if ((m_hp + increaseHP) > m_maxHP) {
            m_hp = m_maxHP;
        }
        else {
            m_hp += increaseHP;
        }
    }
}

//Decreases player's Health Points by requested amount, until the value is 0
void Player::damage(const int decreaseHP)
{
    if (decreaseHP >= 0) {
        if ((m_hp - decreaseHP) < 0) {
            m_hp = 0;
        }
        else {
            m_hp -= decreaseHP;
        }
    }
}

//Checks if the player's Health Points has reached 0
//Return true if it has, otherwise return false
bool Player::isKnockedOut() const
{
    if (m_hp == 0) {
        return true;
    }
    return false;
}

//Increases the player's coins by the requested amount
void Player::addCoins(const int increaseCoins)
{
    if (increaseCoins >= 0) {
        m_coins += increaseCoins;
    }
}

//Decreases the player's coins by the requested amount.
//Return true if the payment was completed successfully, otherwise return false.
bool Player::pay(const int decreaseCoins)
{
    if (decreaseCoins <= 0) {
        return true;
    }
    if (m_coins - decreaseCoins >= 0) {
        m_coins -= decreaseCoins;
        return true;
    }
    return false;
}

//Returns the players attack strength: the player's level + the player's force
int Player::getAttackStrength() const
{
    return (m_level + m_force);
}

//Print players details
std::ostream& operator<<(std::ostream& os, const Player& currentPlayer)
{
    printPlayerDetails(os, currentPlayer.m_name, currentPlayer.getJob(), currentPlayer.m_level,
                       currentPlayer.m_force, currentPlayer.m_hp, currentPlayer.m_coins);
    return os;
}

//--------------------------------Helper Functions--------------------------------

//Validates the given maximum Health Point value from input
int validateHP(int givenMaxHP)
{
    if (givenMaxHP <= 0) {
        return Player::DEFAULT_MAX_HP;
    }
    return givenMaxHP;
}


//Validates the force from input
int validateForce(int givenForce)
{
    if (givenForce <= 0) {
        return Player::DEFAULT_FORCE;
    }
    return givenForce;
}

