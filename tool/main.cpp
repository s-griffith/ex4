#include "../Mtmchkin.h"
#include <iostream>

int main() 
{
    std::string deck = "deck.txt";
    try {
        Mtmchkin game(deck);
        while(!game.isGameOver()) {
            game.playRound();
            game.printLeaderBoard();
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}