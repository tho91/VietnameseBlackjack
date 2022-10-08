

#ifndef SFML_PROJECT_STACKDECK_H
#define SFML_PROJECT_STACKDECK_H
#include "Deck.h"
#include <stack>

class StackDeck : public std::stack<Card>{
private:
    Deck deck;
    std::stack<Card>  stackDeck;
public:
    StackDeck();
    int size();
};


#endif //SFML_PROJECT_STACKDECK_H
