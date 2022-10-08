#ifndef INC_8__POKER_CARD_H
#define INC_8__POKER_CARD_H
#include "Ranks.h"
#include "Suits.h"
#include <iostream>
#include "RankEnum.h"

class Card {
protected:
    Ranks rank;
    Suits suit;

public:
    Card();
    Card(Ranks rank, Suits suit);

    Ranks getRank();
    Suits getSuit();
    void setRank(const Ranks &rank);

    const Suits &getSuit(Suits suits) const;

    void setSuit(const Suits &suit);

    friend std::ostream& operator<<(std::ostream& out, const Card& card);

    int getRankValue() const;
    int getSuitValue() const;
    RankEnum getRankEnum();
    SuitEnum getSuitEnum();
};


#endif //INC_8__POKER_CARD_H
