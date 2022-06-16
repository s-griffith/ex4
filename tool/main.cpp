#include "../Mtmchkin.h"
#include <iostream>

int main(int argc, char **argv) 
{
    Mtmchkin game(argv[1]);
    while(!game.isGameOver()) {
        game.playRound();
        game.printLeaderBoard();
    }
    game.printLeaderBoard();
    return 0;
}