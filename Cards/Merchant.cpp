#include "Merchant.h"

#include <iostream>

//On Piazza - they wrote that everything prints to std::cout
//Need to catch exceptions from getline and stoi functions. Check this.
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string initialInput = "0";
    int cost = 0;
    int input = 0;
    bool validInput = true;
    do {
        validInput = true;
        try {
            std::getline(std::cin, initialInput);
            input = std::stoi(initialInput);
        } catch (std::exception&){
            validInput = false;
        }
        if (!validInput || (input != 0 && input != 1 && input != 2)) {
            printInvalidInput();
        }
    }  while (!validInput || (input != 0 && input != 1 && input != 2));

    if (input == 1 && player.pay(HEALTH_POTION_COST)) {
        player.heal(HEALTH_POTION);
        cost = HEALTH_POTION_COST;
    }
    else if (input == 2 && player.pay(FORCE_BOOST_COST)) {
        player.buff(FORCE_BOOST);
        cost = FORCE_BOOST_COST;
    }
    else if (input == 0) {
        cost = input;
    }
    else {
        input = 0;
        cost = input;
        printMerchantInsufficientCoins(std::cout);
    }
    printMerchantSummary(std::cout, player.getName(), input, cost);
}

std::string Merchant::getName() const
{
    return "Merchant";
}