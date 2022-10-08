

#include "StackDeck.h"

StackDeck::StackDeck() {
    deck.shuffle();
    for(int i = 0; i < deck.deckSize(); i++)
    {
        stackDeck.push(deck.getCardAt(i));
    }
}

int StackDeck::size() {
    return stackDeck.size();
}
