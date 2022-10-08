#include "CardHandScorer.h"

PokerScore CardHandScorer::scorePoker(CardHand cardInHand) {
    PokerScore score;
    if(isHighCard(cardInHand))
        score.addScore(PokerScore::HIGH_CARD);
    if(isPair(cardInHand))
        score.addScore(PokerScore::ONE_PAIR);
    if(isTwoPair(cardInHand))
        score.addScore(PokerScore::TWO_PAIR);
    if(isThreeKind(cardInHand))
        score.addScore(PokerScore::THREE_OF_A_KIND);
    if(isStraigt(cardInHand))
        score.addScore(PokerScore::STRAIGHT);
    if(isFlush(cardInHand))
        score.addScore(PokerScore::FLUSH);
    if(isFullHouse(cardInHand))
        score.addScore(PokerScore::FULL_HOUSE);
    if(isFourKind(cardInHand))
        score.addScore(PokerScore::FOUR_OF_A_KIND);
    if(isStraightFlush(cardInHand))
        score.addScore(PokerScore::STRAIGHT_FLUSH);
    if(isRoyalFlush(cardInHand))
        score.addScore(PokerScore::ROYAL_FLUSH);

    return score;
}

//sort function for card hand before checking the score
void CardHandScorer::sort(CardHand& cardInHand) {
    bool swapped;

    for(int i=0;i<cardInHand.handSize();i++){
        swapped=false;
        for(int j=0; j < cardInHand.handSize()-1;j++) {
            if (cardInHand.getRank(j) > cardInHand.getRank(j + 1)) {
                swap(cardInHand.cardPos(j), cardInHand.cardPos(j + 1));
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}

void CardHandScorer::swap(Card &card1, Card &card2) {
    Card temp;
    temp = card1;
    card1 = card2;
    card2 = temp;
}

CardHandScorer::CardHandScorer() {

}



//true when rank value of one card equal to the next.
bool CardHandScorer::isPair(CardHand ch) {
    sort(ch);
    for(int i = 0; i < ch.handSize()-1; i++)
    {
        if(ch.cardPos(i).getRankValue() == ch.cardPos(i+1).getRankValue())
        {
            return true;
        }
    }
    return false;
}

//has a count for max value to check for 2 pair
bool CardHandScorer::isTwoPair(CardHand ch) {
    sort(ch);
    int maxNumVal = 0;
    for(int i = 0; i < ch.handSize(); i++)
    {
        for(int j = i + 1; j < ch.handSize(); j++)
        {
            if(ch.cardPos(i).getRankValue() == ch.cardPos(j).getRankValue())
            {
                maxNumVal++;
            }
        }
    }
    if(maxNumVal == 2)
        return true;
    else
        return false;
}

//three of a kind is true when three consecutive value is the same
bool CardHandScorer::isThreeKind(CardHand ch) {
    sort(ch);
    if(!isPair(ch))
    return false;
    for(int i = 0; i < 3; i++)
    {
        if(ch.cardPos(i).getRankValue() == ch.cardPos(i+1).getRankValue()
        && ch.cardPos(i).getRankValue() == ch.cardPos(i+2).getRankValue())
        {
            return true;
        }
    }
    return false;
}

//fourkind is true when 4 consecutive value is the same
bool CardHandScorer::isFourKind(CardHand ch) {
    sort(ch);
    for(int i = 0; i < 2; i++)
    {
        if(ch.cardPos(i).getRankValue() == ch.cardPos(i+1).getRankValue()
        && ch.cardPos(i).getRankValue() == ch.cardPos(i+2).getRankValue()
        && ch.cardPos(i).getRankValue() == ch.cardPos(i+3).getRankValue())
        {
            return true;
        }

    }
    return false;
}


bool CardHandScorer::isFullHouse(CardHand ch) {
    sort(ch);
    if(ch.cardPos(0).getRankValue() == ch.cardPos(1).getRankValue()
    && ch.cardPos(0).getRankValue() == ch.cardPos(2).getRankValue())
    {
        if(ch.cardPos(3).getRankValue() == ch.cardPos(4).getRankValue())
            return true;
    }

    if(ch.cardPos(0).getRankValue() == ch.cardPos(1).getRankValue())
    {
        if(ch.cardPos(2).getRankValue() == ch.cardPos(3).getRankValue()
        && ch.cardPos(2).getRankValue() == ch.cardPos(4).getRankValue())
            return true;
    }
    return false;
}

//all hand has high card
bool CardHandScorer::isHighCard(CardHand ch) {
    return true;
}

//straight is true when 5 card value increment by 1
//special case for ACE TEN JACK QUEEN KING
bool CardHandScorer::isStraigt(CardHand ch) {
    sort(ch);
    bool straight = true;
    if(isPair(ch))
        return false;
    for(int i = 0; i < ch.handSize()-1; i++)
    {
        if(ch.cardPos(i).getRankValue() != ch.cardPos(i+1).getRankValue()-1){
            straight = false;
        }
    }
    return straight;
}

//flush is false if suit of one card is different from the next.
bool CardHandScorer::isFlush(CardHand ch) {
    sort(ch);
    int s = 0, c = 0, d = 0, h = 0;
    bool flush = false;
//    if(ch.cardPos(0).getSuitValue() == ch.cardPos(1).getSuitValue()
//    && ch.cardPos(1).getSuitValue() == ch.cardPos(2).getSuitValue()
//    && ch.cardPos(2).getSuitValue() == ch.cardPos(3).getSuitValue()
//    && ch.cardPos(3).getSuitValue() == ch.cardPos(4).getSuitValue())
//        return true;

    for(int i = 0; i < ch.handSize(); i++)
    {
       if(ch.cardPos(i).getSuitValue() == 1) s++;
        if(ch.cardPos(i).getSuitValue() == 2) c++;
        if(ch.cardPos(i).getSuitValue() == 3) d++;
        if(ch.cardPos(i).getSuitValue() == 4) h++;

    }
//    std::cout <<"s:"<<  s << " c:" << c <<" d:" << d << " h:" << h;

    if(s == 5 || c == 5 || d == 5 || h == 5)
    {
//        std::cout << "flush is true";
        flush = true;
    }
//    std::cout << "flush :" << flush << " FLUSH FLUSH FLUSH";
    return flush;
}

//straightflush is true when it has flush and straight
bool CardHandScorer::isStraightFlush(CardHand ch) {
    sort(ch);
    if(isFlush(ch) && isStraigt(ch))
    {
        return true;
    }
    return false;
}

//royal flush is true when it has flush and straight from ten to ace
bool CardHandScorer::isRoyalFlush(CardHand ch) {
    sort(ch);
    if(ch.cardPos(0).getRankValue() == ACE && isStraightFlush(ch))
    {
                return true;
    }
    return false;
}


