#include "Suits.h"

Suits::Suits() {

}

Suits::Suits(SuitEnum suit) : suit(suit)
{

}

SuitEnum Suits::getSuit() const {
    return suit;
}

void Suits::setSuit(SuitEnum suit) {
    Suits::suit = suit;
}

std::string Suits::toString() const
{
    std::string suitName[] = {"SPACE", "CLUB", "DIAMOND", "HEART"};
    return suitName[suit];
}
