#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Exception.h"
#include "utilities.h"

#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <map>
#include <queue>
#include <list>
#include <vector>
#include <memory>

class Mtmchkin {
public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::queue<std::shared_ptr<Card>> m_deck;
    std::list<std::shared_ptr<Player>> m_players;
    std::vector<std::shared_ptr<Player>> m_winners;
    std::vector<std::shared_ptr<Player>> m_losers;
    int m_numRounds;
};

#endif /* MTMCHKIN_H_ */
