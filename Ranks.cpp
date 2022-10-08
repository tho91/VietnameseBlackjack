#include "Ranks.h"

Ranks::Ranks() {

}

Ranks::Ranks(RankEnum rank) : rank(rank)
{

}

std::string Ranks::toString() const
{
    std::string rankName[] = {"ACE", "TWO","THREE", "FOUR", "FIVE", "SIX",
                              "SEVEN", "EIGHT", "NINE", "TEN", "JACK",
                              "QUEEN", "KING"};
    return rankName[rank-1];
}

std::string Ranks::toChar() const
{
    if(rank > 1 && rank < 11)
    {
        return std::to_string((int)rank);
    }
    else
    {
        return ""+toString()[0];
    }
}


int Ranks::getRank() const {
    return rank;
}

void Ranks::setRank(RankEnum rank) {
    Ranks::rank = rank;
}

int Ranks::rankValue() const {
    int rValue[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    return rValue[rank-1];
}

