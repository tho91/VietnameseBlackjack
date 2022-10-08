#ifndef INC_8__POKER_CARDHAND_H
#define INC_8__POKER_CARDHAND_H
#include "Deck.h"
#include <vector>
#include <iostream>
#include "Card.h"


class CardHand {
private:
    std::vector<Card> cardInHand;
public:
    CardHand();
    friend std::ostream& operator<<(std::ostream& out, const CardHand& cardInHand);
    void getCard(Card card);
    int handSize();
    int getRank(int index);
    Card& cardPos(int index);

};


#endif //INC_8__POKER_CARDHAND_H
