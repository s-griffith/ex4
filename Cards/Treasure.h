#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

const int TREASURE_LOOT = 10;

class Treasure : public Card {
public:
    Treasure();
    ~Treasure() = default;
    //Treasure has no internal fields, or data changes, so we'll forbid the use of a copy constructor
    Treasure(const int&) = delete;

    void applyEncounter(Player& player) const override;

    //It doesn't look like we need anything else here, but maybe check again later. For print, can use the regular print function in the Card class.
};

#endif //EX4_TREASURE_H
