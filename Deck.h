#ifndef INC_8__POKER_DECK_H
#define INC_8__POKER_DECK_H
#include "Card.h"
#include "ostream"
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <ctime>

class Deck {
private:
    int cardIndex;
    const int DECK_SIZE =52;
    Card deck[52];
public:

    Deck();
    bool empty();
    Card dealCard();
    Card getCardAt(int index);
    void shuffle();
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
    void swap(Card& card1, Card& card2);
    int deckSize();


};


#endif //INC_8__POKER_DECK_H
