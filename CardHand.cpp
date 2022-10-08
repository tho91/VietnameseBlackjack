#include "CardHand.h"

CardHand::CardHand()
{

}



void CardHand::getCard(Card card) {
    cardInHand.push_back(card);
}


std::ostream& operator<<(std::ostream& out, const CardHand& cardInHand)
{
    for(int i = 0; i < 5; i++)
    {
        std::cout << cardInHand.cardInHand[i] << std::endl;
    }
    return out;
}

int CardHand::handSize() {
    return cardInHand.size();
}

Card &CardHand::cardPos(int index) {
    return cardInHand[index];
}

int CardHand::getRank(int index) {
    return cardInHand[index].getRankValue();
}

