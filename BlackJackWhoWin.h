

#ifndef SFML_PROJECT_BLACKJACKWHOWIN_H
#define SFML_PROJECT_BLACKJACKWHOWIN_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class BlackJackWhoWin {
private:
    std::string winnerText;
public:
    BlackJackWhoWin();
    std::string getWinnerName(int houseScore, int botScore);
};


#endif //SFML_PROJECT_BLACKJACKWHOWIN_H
