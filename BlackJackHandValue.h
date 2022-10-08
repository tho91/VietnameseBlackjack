

#ifndef SFML_PROJECT_BLACKJACKHANDVALUE_H
#define SFML_PROJECT_BLACKJACKHANDVALUE_H
#include "CardHand.h"
#include "Card.h"

class BlackJackHandValue {
private:
    CardHand ch;
    int totalScore;
public:
    BlackJackHandValue();
    BlackJackHandValue(CardHand cardHand);
    int handValue(CardHand cardHand);
    void sort(CardHand& cardHand);
    void swap(Card& c1, Card& c2);
    bool isTwoAce(CardHand cardHand);
    bool isBlackJack(CardHand cardHand);
    void clearScore();
};


#endif //SFML_PROJECT_BLACKJACKHANDVALUE_H
