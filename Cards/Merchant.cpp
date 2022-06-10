#include "Merchant.h"
#include "../Players/Player.h"

#include <iostream>

//Need access to output stream and input stream! How to make this work? On Piazza - they wrote that everything prints to std::cout
//Supposed to use getline and stoi; need input and output stream for that too.
//Will likely become clearer after creating Mtmchkin class
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.m_name, player.m_coins);
    int input;
    int cost;
    std::cin >> input;
    while (input != 0 && input != 1 && input != 2) {
        printInvalidInput();
        std::cin >> input;
    }
    switch(input) {
        case 0:
            cost = input;
            break;
        case 1:
            cost = HEALTH_POTION_COST;
            break;
        case 2:
            cost = FORCE_BOOST_COST;
            break;
    }
    if (!player.pay(cost)) {
        printMerchantInsufficientCoins(std::cout);
    }
    else {
        switch(input) {
            case 1:
                player.heal(HEALTH_POTION);
                break;
            case 2:
                player.buff(FORCE_BOOST);
                break;
        }
    }
    printMerchantSummary(std::cout, player.m_name, input, cost);
}