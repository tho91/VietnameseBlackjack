#ifndef INC_8__POKER_RANKS_H
#define INC_8__POKER_RANKS_H
#include "RankEnum.h"
#include <string>

class Ranks {
private:
    RankEnum rank;

public:
    Ranks();
    Ranks(RankEnum rank);

    int getRank() const;

    void setRank(RankEnum rank);

    std::string toString() const;
    std::string toChar() const;
    int rankValue() const;
    
};


#endif //INC_8__POKER_RANKS_H
