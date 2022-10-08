#ifndef INC_8__POKER_POKERSCORE_H
#define INC_8__POKER_POKERSCORE_H
#include <vector>
#include "CardHand.h"
#include <iostream>


class PokerScore {
public:
    enum Scores{

        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

        FOUR_OF_A_KIND, //four cards of the same ranking

        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

        FLUSH, //five cards of the same suit

        STRAIGHT, //five cards in consecutive ranking

        THREE_OF_A_KIND, //three cards of the same rank

        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

        ONE_PAIR, //two cards of the same rank

        HIGH_CARD //highest card in the player’s hand

    };
private:
    std::vector<Scores> scores;
public:
    PokerScore();

    friend bool operator==(const PokerScore& p, Scores score);
    void operator+=(const Scores& score);
    int size();
    Scores& operator[](unsigned int index);
    friend std::ostream& operator<<(std::ostream& out, PokerScore& score);
    void addScore(Scores score);

};


#endif //INC_8__POKER_POKERSCORE_H
