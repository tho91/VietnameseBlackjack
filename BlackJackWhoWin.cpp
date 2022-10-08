

#include "BlackJackWhoWin.h"



BlackJackWhoWin::BlackJackWhoWin() {

}


std::string BlackJackWhoWin::getWinnerName(int houseScore, int botScore) {
    if(houseScore == 1000 && botScore < 1000 )
    {
        return winnerText = "HOUSE WIN";
    }
    if(botScore == 1000 && houseScore < 1000 )
    {
        return winnerText = "BOT WIN";
    }
    if(houseScore == 1000 && botScore == 1000)
    {
        winnerText = "TIE GAME";
    }

    if(houseScore == 500 && botScore < 500)
    {
        return winnerText = "HOUSE WIN";
    }
    if(botScore == 500 && houseScore < 500)
    {
        return winnerText = "BOT WIN";
    }
    if(botScore == 500 && houseScore == 500)
    {
        return winnerText = "TIE GAME";
    }

    if(houseScore > 100 && botScore < 100)
    {
        return winnerText = "HOUSE WIN";
    }
    if(botScore > 100 && houseScore < 100)
    {
        return winnerText = "BOT WIN";
    }


    if(houseScore > 21 || botScore > houseScore && botScore <= 21)
    {
        winnerText = "BOT WIN";
    }
    else if(houseScore > botScore && houseScore <= 21 || botScore > 21)
    {
         winnerText = "HOUSE WIN";
    }
    else
    {
        winnerText = "TIE GAME";
    }
    return winnerText;
}



