

#include "BlackJackHandValue.h"

BlackJackHandValue::BlackJackHandValue() {

}

int BlackJackHandValue::handValue(CardHand cardHand) {
    clearScore();
    sort(cardHand);
//    std::cout << "hand value begin\n";
//    two ace is biggest
    if(isTwoAce(cardHand))
    {
        return totalScore = 1000;
    }

//    blackjack is 2nd biggest
    if(isBlackJack(cardHand))
    {
        return totalScore = 500;
    }

//    5 card case bigger than 21 but smaller than blackjack and two ace
    if(cardHand.handSize() > 4)
    {
        for(int i = 0; i < cardHand.handSize(); i++)
        {
            if(cardHand.getRank(i) == JACK)
            {
                totalScore += 10;
            }
            else if(cardHand.getRank(i) == QUEEN){
                totalScore += 10;
            }
            else if(cardHand.getRank(i) == KING){
                totalScore += 10;
            }
            else{
                totalScore += cardHand.getRank(i);
            }
        }
        totalScore += 100;
    }


//    if player have 4 card then Ace = 1
    else if(cardHand.handSize() == 4)
    {
        for(int i = 0; i < cardHand.handSize(); i++)
        {
            if(cardHand.getRank(i) == JACK)
            {
                totalScore += 10;
            }
            else if(cardHand.getRank(i) == QUEEN){
                totalScore += 10;
            }
            else if(cardHand.getRank(i) == KING){
                totalScore += 10;
            }
            else{
                totalScore += cardHand.getRank(i);
            }
        }
    }

//   case 3 card or less Ace == 11
    else
    {
        for(int i = 0; i < cardHand.handSize(); i++)
        {
            if(cardHand.getRank(i) == ACE)
            {
                totalScore += 11;
            }
            else if(cardHand.getRank(i) == JACK){
                totalScore += 10;
            }
            else if(cardHand.getRank(i) == QUEEN){
                totalScore += 10;
            }
            else if(cardHand.getRank(i) == KING){
                totalScore += 10;
            }
            else{
                totalScore += cardHand.getRank(i);
            }
        }
    }
//    std::cout << "hand value end\n";
    return totalScore;
}

BlackJackHandValue::BlackJackHandValue(CardHand cardHand) : ch(cardHand){


}

void BlackJackHandValue::sort(CardHand &cardHand) {
    bool swapped;

    for(int i=0;i<cardHand.handSize();i++){
        swapped=false;
        for(int j=0; j < cardHand.handSize()-1;j++) {
            if (cardHand.getRank(j) > cardHand.getRank(j + 1)) {
                swap(cardHand.cardPos(j), cardHand.cardPos(j + 1));
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
//    std::cout << "sort working\n";
}

void BlackJackHandValue::swap(Card &c1, Card &c2) {
    Card temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
}

bool BlackJackHandValue::isTwoAce(CardHand cardHand) {
//    sort(cardHand);
//    std::cout << "two ace begin\n";

    bool flag = false;
    if(cardHand.cardPos(0).getRank().getRank() == ACE && cardHand.cardPos(1).getRank().getRank() == ACE && cardHand.handSize() == 2)
    {
        flag = true;
    }
//    std::cout << "two ace end\n";
    return flag;
}

bool BlackJackHandValue::isBlackJack(CardHand cardHand) {
//    sort(cardHand);
//    std::cout << "black jack begin\n";

    bool flag = false;
    if(cardHand.handSize() == 2 && cardHand.cardPos(0).getRank().getRank() == ACE &&
            (cardHand.cardPos(1).getRank().getRank() == TEN ||
            cardHand.cardPos(1).getRank().getRank() == JACK ||
            cardHand.cardPos(1).getRank().getRank() == QUEEN ||
            cardHand.cardPos(1).getRank().getRank() == KING))
    {
        flag = true;
    }
//    std::cout << "black jack end\n";

    return flag;
}

void BlackJackHandValue::clearScore() {
    totalScore = 0;
}
