#include "Card.h"

Card::Card() {

}

Card::Card(Ranks rank, Suits suit) : rank(rank), suit(suit)
{

}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    out << card.rank.toString() << " of " << card.suit.toString();
    return out;
}

Ranks Card::getRank() {
    return rank;
}

void Card::setRank(const Ranks &rank) {
    Card::rank = rank;
}

const Suits &Card::getSuit(Suits suits) const {
    return suit;
}

void Card::setSuit(const Suits &suit) {
    Card::suit = suit;
}

int Card::getRankValue() const{
    switch(rank.getRank()){
        case ACE:
            return 1;
        case TWO:
            return 2;
        case THREE:
            return 3;
        case FOUR:
            return 4;
        case FIVE:
            return 5;
        case SIX:
            return 6;
        case SEVEN:
            return 7;
        case EIGHT:
            return 8;
        case NINE:
            return 9;
        case TEN:
            return 10;
        case JACK:
            return 11;
        case QUEEN:
            return 12;
        case KING:
            return 13;
    }
}

int Card::getSuitValue() const {
    switch(suit.getSuit())
    {
        case SPACE: return 1;
        case CLUB:  return 2;
        case DIAMOND: return 3;
        case HEART: return 4;
    }
}

//RankEnum Card::getRankEnum() {
//    switch(rank.getRank())
//    {
//        case 1: return ACE; break;
//        case 2: return TWO; break;
//        case 3: return THREE; break;
//        case 4: return FOUR; break;
//        case 5: return FIVE; break;
//        case 6: return SIX; break;
//        case 7: return SEVEN; break;
//        case 8: return EIGHT; break;
//        case 9: return NINE; break;
//        case 10: return ACE; break;
//        case 11: return ACE; break;
//        case 12: return ACE; break;
//        case 13: return ACE; break;
//        default:
//            std::cout << "getRankEnum is broke";
//
//    }
//
//}

SuitEnum Card::getSuitEnum() {
    return SPACE;
}

Suits Card::getSuit() {
    return suit;
}


