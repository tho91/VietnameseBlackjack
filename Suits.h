#ifndef INC_8__POKER_SUITS_H
#define INC_8__POKER_SUITS_H
#include "SuitEnum.h"
#include <string>

class Suits {
private:
    SuitEnum suit;

public:
    Suits();
    Suits(SuitEnum suit);

    SuitEnum getSuit() const;

    void setSuit(SuitEnum suit);

    std::string toString() const;
};


#endif //INC_8__POKER_SUITS_H
