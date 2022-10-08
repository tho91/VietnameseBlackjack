#include "Deck.h"

Deck::Deck() {
    cardIndex=0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 14; j++)
        {
            deck->setSuit((Suits) static_cast<SuitEnum>(i));
            deck->setRank((Ranks) static_cast<RankEnum>(j));

            deck[j+(13*i)].setSuit(static_cast<SuitEnum>(i));
            deck[j+(13*i)].setRank(static_cast<RankEnum>(j));
        }
    }

}

bool Deck::empty() {
    return false;
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
    for(int i = 0; i < deck.DECK_SIZE; i++)
    {
        std::cout << i + 1 << ": " << deck.deck[i] <<std::endl;
    }
    return out;
}

Card Deck::dealCard() {
    int cardPos = cardIndex;
    cardIndex++;
    return deck[cardPos];
}

Card Deck::getCardAt(int cardPos) {
    return deck[cardPos];
}

void Deck::shuffle() {
//    srand(time(0));
    int min = 2, max = 10;
    int randNum = rand()% (max - min + 1) + min;
    while(randNum != 0) {
        for (int i = DECK_SIZE - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(deck[i], deck[j]);
        }
        randNum--;
    }
}

void Deck::swap(Card& card1, Card& card2) {
    Card temp;
    temp = card1;
    card1 = card2;
    card2 = temp;
}

int Deck::deckSize() {
    return DECK_SIZE;
}
