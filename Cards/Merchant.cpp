#include "Merchant.h"

//--------------------------Helper Function--------------------------
int receiveInput();
//--------------------------------------------------------------------


//----------------------------------Merchant Class Member Functions----------------------------------

//Handles a player's encounter with a merchant during the game
void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int cost = 0;
    int input = receiveInput();
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
        //input = 0;
        cost = 0; //same comment as in noGang git file.............................................................................................
        printMerchantInsufficientCoins(std::cout);
    }
    printMerchantSummary(std::cout, player.getName(), input, cost);
}

//Returns the name of the card as a string
std::string Merchant::getName() const
{
    return "Merchant";
}

//----------------------------------Merchant Class Helper Function----------------------------------

//Requests input from the user in a loop until valid input is received.
int receiveInput()
{
    bool validInput = true;
    int input = 0;
    std::string initialInput = "0";
    do {
        validInput = true;
        //Receieve input from the user:
        try {
            std::getline(std::cin, initialInput);
            input = std::stoi(initialInput);
        }
        catch (std::exception&){
            validInput = false;
        }
        //Check if the input is valid:
        if (!validInput || (input != 0 && input != 1 && input != 2)) {
            printInvalidInput();
        }
    }  while (!validInput || (input != 0 && input != 1 && input != 2));
    return input;    
}