#include "Merchant.h"

#include <iostream>

//On Piazza - they wrote that everything prints to std::cout
//Need to catch exceptions from getline and stoi functions. Check this.
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string initialInput;
    int cost = 0;
    int input = -1;
    bool inputValid = true;
    do {
        if (!inputValid || (input != 0 && input != 1 && input != 2)) {
            printInvalidInput();
        }
        try {
            std::getline(std::cin, initialInput);
            input = std::stoi(initialInput);
        } catch (std::exception&){
            inputValid = false;
        }
    }  while (!inputValid || (input != 0 && input != 1 && input != 2));

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