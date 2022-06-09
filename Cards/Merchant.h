#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    //functions: applyencounter, print?
private:
    int m_cost;
    int m_heal;
    int m_buff;
};

#endif //EX4_MERCHANT_H
