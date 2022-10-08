#ifndef INC_8__POKER_CARDHANDSCORER_H
#define INC_8__POKER_CARDHANDSCORER_H
#include "CardHand.h"
#include "PokerScore.h"
#include "Card.h"
#include <string>

class CardHandScorer {
public:
    CardHandScorer();
    static PokerScore scorePoker(CardHand cardInHand);
    static void sort(CardHand& cardInHand);
    static void swap(Card& card1, Card& card2);


    static bool isPair(CardHand ch);
    static bool isTwoPair(CardHand ch);
    static bool isThreeKind(CardHand ch);
    static bool isFourKind(CardHand ch);
    static bool isFullHouse(CardHand ch);
    static bool isHighCard(CardHand ch);
    static bool isStraigt(CardHand ch);
    static bool isFlush(CardHand ch);
    static bool isStraightFlush(CardHand ch);
    static bool isRoyalFlush(CardHand ch);
};


#endif //INC_8__POKER_CARDHANDSCORER_H
