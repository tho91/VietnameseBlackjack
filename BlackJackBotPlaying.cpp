

#include "BlackJackBotPlaying.h"

BlackJackBotPlaying::BlackJackBotPlaying() {

}


bool BlackJackBotPlaying::isBotLucky(int botScore) {
    bool lucky = false;
    if(botScore == 16)
    {
        randNum = rand() % 1;
        if(randNum == 1)
        {
            lucky = true;
        }
    }
    else if(botScore == 17)
    {
        randNum = rand() % 2;
        if(randNum == 1)
        {
            lucky = true;
        }
    }
    else if(botScore == 18)
    {
        randNum = rand() % 6;
        if(randNum == 1)
        {
            lucky = true;
        }
    }
    return lucky;
}
