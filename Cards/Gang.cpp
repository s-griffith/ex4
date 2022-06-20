#include "Gang.h"
#include <iostream>

Gang::Gang(const std::vector<MonsterCards> &cards) : m_cards(cards)
{}


void Gang::applyEncounter(Player& player) const
{
    bool win = true;
    for (const MonsterCards &currentCard : m_cards) {
        if (win) {
            win = (player.getAttackStrength() >= currentCard.getForce());
            currentCard.applyEncounter(player);
        }
        if (!win) {
            player.damage(currentCard.getDamage());
        }
    }
    if (win) {
        player.levelUp();
    }
}

void Gang::printInfo(std::ostream &os) const
{
    printCardDetails(std::cout, (*this).getName());
    for (const MonsterCards &currentCard : m_cards) {
        currentCard.printInfo(os);
    }
    printEndOfCardDetails(os);
}

std::string Gang::getName() const 
{
    return "Gang";
}

std::ostream& operator<<(std::ostream& os, const Gang& cards)
{
    cards.printInfo(os);
    return os;
}