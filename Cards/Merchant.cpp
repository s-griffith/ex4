#include "Merchant.h"

//----------------------------------Merchant Class Member Functions----------------------------------

//Handles a player's encounter with a merchant during the game
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string initialInput = "0";
    int cost = 0;
    int input = 0;
    bool validInput = true;
    do {
        validInput = true;
        //Receieve input from the user:
        try {
            std::getline(std::cin, initialInput);
            input = std::stoi(initialInput);
        } catch (std::exception&){
            validInput = false;
        }
        //Check if the input is valid:
        if (!validInput || (input != 0 && input != 1 && input != 2)) {
            printInvalidInput();
        }
    }  while (!validInput || (input != 0 && input != 1 && input != 2));
    //Act according to the input received:
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

//Returns the name of the card as a string
std::string Merchant::getName() const
{
    return "Merchant";
}