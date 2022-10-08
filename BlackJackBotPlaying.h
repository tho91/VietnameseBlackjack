

#ifndef SFML_PROJECT_BLACKJACKBOTPLAYING_H
#define SFML_PROJECT_BLACKJACKBOTPLAYING_H
#include "CardHand.h"
#include "BlackJackHandValue.h"
#include <ctime>

class BlackJackBotPlaying {
private:
    int randNum;
public:
    BlackJackBotPlaying();
    bool isBotLucky(int botScore);
};


#endif //SFML_PROJECT_BLACKJACKBOTPLAYING_H
