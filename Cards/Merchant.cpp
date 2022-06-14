#include "Merchant.h"

#include <iostream>

//On Piazza - they wrote that everything prints to std::cout
//Need to catch exceptions from getline and stoi functions. Check this.
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string initialInput;
    int cost;
    std::getline(std::cin, initialInput);
    int input = std::stoi(initialInput);
    while (input != 0 && input != 1 && input != 2) {
        printInvalidInput();
        std::getline(std::cin, initialInput);
        int input = std::stoi(initialInput);    
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
        cost = 0;
        input = 0;
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
    printMerchantSummary(std::cout, player.getName(), input, cost);
}