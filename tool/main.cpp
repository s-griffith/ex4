#include "../Mtmchkin.h"
#include <iostream>

/* 
 * The main initializes a game using the cards in the file deck.txt.
 * The rounds are played until all players have either won or lost.
 * Any exceptions thrown throughout gameplay are printed to the screen.
*/
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