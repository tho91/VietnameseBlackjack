#include <iostream>
#include "CardHandScorer.h"
#include <SFML/Graphics.hpp>
#include "SFMLCard.h"
#include "SFMLPokerName.h"
#include <vector>
#include "FrontPage.h"
#include "Button.h"
#include "BlackJackInterface.h"
#include "StackDeck.h"
#include "BlackJackInstruction.h"
#include "BlackJackFaceDown.h"
#include "BlackJackWhoWin.h"
#include "BlackJackHandValue.h"
#include "BlackJackBotPlaying.h"
#include <stack>
#include <ctime>

int CARDSIZE_X = 100;
int CARDSIZE_Y  = 150;
int numberOfLoop = 10000;

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 900, 32), "Vietnamese Blackjack");
    window.setFramerateLimit(30);


//  Poker Card
    CardHandScorer chs;

    double royalFlush = 0, straightFlush = 0, fourKind = 0, fullHouse = 0,
            flush = 0, straight = 0, threeKind = 0, twoPair = 0,
            onePair = 0, highCard = 0;
    srand(time(nullptr));

    for(int i = 0; i < numberOfLoop; i++)
        {
            Deck deck;
            deck.shuffle();
            CardHand ch1;
            for (int i = 0; i < 5; i++) {
                ch1.getCard(deck.dealCard());
            }

            if(chs.isRoyalFlush(ch1))
                royalFlush++;
            if(chs.isStraightFlush(ch1))
                straightFlush++;
            if(chs.isFourKind(ch1))
                fourKind++;
            if(chs.isFullHouse(ch1))
                fullHouse++;
            if(chs.isFlush(ch1))
                flush++;
            if(chs.isStraigt(ch1))
                straight++;
            if(chs.isThreeKind(ch1))
                threeKind++;
            if(chs.isTwoPair(ch1))
                twoPair++;
            if(chs.isPair(ch1))
                onePair++;
            if(chs.isHighCard(ch1))
                highCard++;
        }
    std::string royalText = std::to_string(royalFlush/ numberOfLoop * 100) + "%";
    std::string sfText = std::to_string(straightFlush/ numberOfLoop * 100) + "%";
    std::string fkText = std::to_string(fourKind/ numberOfLoop * 100) + "%";
    std::string fhText = std::to_string(fullHouse/ numberOfLoop * 100) + "%";
    std::string fText = std::to_string(flush/ numberOfLoop * 100) + "%";
    std::string sText = std::to_string(straight/ numberOfLoop * 100) + "%";
    std::string tkText = std::to_string(threeKind/ numberOfLoop * 100) + "%";
    std::string tpText = std::to_string(twoPair/ numberOfLoop * 100) + "%";
    std::string opText = std::to_string(onePair/ numberOfLoop * 100) + "%";
    std::string hcText = std::to_string(highCard/ numberOfLoop * 100) + "%";

//  Royal Flush
    SFMLPokerName royalScore(royalText);
    royalScore.setPosition(300, 135);

    SFMLPokerName royal("Royal Flush: ");
    royal.setPosition(50, 135);

    SFMLCard royal1(ACE, DIAMOND);
    SFMLCard royal2(KING, DIAMOND);
    SFMLCard royal3(QUEEN, DIAMOND);
    SFMLCard royal4(JACK, DIAMOND);
    SFMLCard royal5(TEN, DIAMOND);

    royal1.setPosition(50, 20);
    royal2.setPosition(50 + CARDSIZE_X + 5, 20);
    royal3.setPosition(50 + CARDSIZE_X * 2 +10, 20);
    royal4.setPosition(50 + CARDSIZE_X * 3 +15, 20);
    royal5.setPosition(50 + CARDSIZE_X * 4 +20, 20);

//    Straight Flush
    SFMLPokerName sfScore(sfText);
    sfScore.setPosition(300, 310);

    SFMLPokerName sf("Straight Flush: ");
    sf.setPosition(50, 310);

    SFMLCard sf1(EIGHT, DIAMOND);
    SFMLCard sf2(SEVEN, DIAMOND);
    SFMLCard sf3(SIX, DIAMOND);
    SFMLCard sf4(FIVE, DIAMOND);
    SFMLCard sf5(FOUR, DIAMOND);
    sf1.setPosition(50, CARDSIZE_Y + 45) ;
    sf2.setPosition(50 + CARDSIZE_X + 5, CARDSIZE_Y + 45);
    sf3.setPosition(50 + CARDSIZE_X * 2 +10, CARDSIZE_Y + 45);
    sf4.setPosition(50 + CARDSIZE_X * 3 +15, CARDSIZE_Y + 45);
    sf5.setPosition(50 + CARDSIZE_X * 4 +20, CARDSIZE_Y + 45);

//    Four Kind
    SFMLPokerName fkScore(fkText);
    fkScore.setPosition(300, 485);

    SFMLPokerName fk("Four Kind: ");
    fk.setPosition(50, 485);

    SFMLCard fk1(JACK, HEART);
    SFMLCard fk2(JACK, DIAMOND);
    SFMLCard fk3(JACK, CLUB);
    SFMLCard fk4(JACK, SPACE);
    SFMLCard fk5(SIX, HEART);
    fk1.setPosition(50, CARDSIZE_Y * 2 + 70) ;
    fk2.setPosition(50 + CARDSIZE_X + 5, CARDSIZE_Y * 2 + 70);
    fk3.setPosition(50 + CARDSIZE_X * 2 +10, CARDSIZE_Y * 2 + 70);
    fk4.setPosition(50 + CARDSIZE_X * 3 +15, CARDSIZE_Y * 2 + 70);
    fk5.setPosition(50 + CARDSIZE_X * 4 +20, CARDSIZE_Y * 2 + 70);

//    Fullhouse
    SFMLPokerName fhScore(fhText);
    fhScore.setPosition(300, 660);

    SFMLPokerName fh("Full House: ");
    fh.setPosition(50, 660);

    SFMLCard fh1(THREE, HEART);
    SFMLCard fh2(THREE, CLUB);
    SFMLCard fh3(THREE, DIAMOND);
    SFMLCard fh4(NINE, DIAMOND);
    SFMLCard fh5(NINE, HEART);
    fh1.setPosition(50, CARDSIZE_Y * 3 + 95) ;
    fh2.setPosition(50 + CARDSIZE_X + 5, CARDSIZE_Y * 3 + 95) ;
    fh3.setPosition(50 + CARDSIZE_X * 2 +10, CARDSIZE_Y * 3 + 95) ;
    fh4.setPosition(50 + CARDSIZE_X * 3 +15, CARDSIZE_Y * 3 + 95) ;
    fh5.setPosition(50 + CARDSIZE_X * 4 +20, CARDSIZE_Y * 3 + 95) ;

//    Flush
    SFMLPokerName fScore(fText);
    fScore.setPosition(300, 835);

    SFMLPokerName f("Flush: ");
    f.setPosition(50, 835);

    SFMLCard f1(FOUR, HEART);
    SFMLCard f2(JACK, HEART);
    SFMLCard f3(EIGHT, HEART);
    SFMLCard f4(TWO, HEART);
    SFMLCard f5(KING, HEART);
    f1.setPosition(50, CARDSIZE_Y * 4 + 120) ;
    f2.setPosition(50 + CARDSIZE_X + 5, CARDSIZE_Y * 4 + 120) ;
    f3.setPosition(50 + CARDSIZE_X * 2 +10, CARDSIZE_Y * 4 + 120) ;
    f4.setPosition(50 + CARDSIZE_X * 3 +15, CARDSIZE_Y * 4 + 120) ;
    f5.setPosition(50 + CARDSIZE_X * 4 +20, CARDSIZE_Y * 4 + 120) ;

//    Straight
    SFMLPokerName sScore(sText);
    sScore.setPosition(300 + CARDSIZE_X * 7, 135);

    SFMLPokerName s("Straight: ");
    s.setPosition(50 + CARDSIZE_X * 7, 135);

    SFMLCard s1(NINE, HEART);
    SFMLCard s2(EIGHT, DIAMOND);
    SFMLCard s3(SEVEN, DIAMOND);
    SFMLCard s4(SIX , HEART);
    SFMLCard s5(FIVE, HEART);
    s1.setPosition(50 + CARDSIZE_X * 7, 20);
    s2.setPosition(50 + CARDSIZE_X * 8 + 5, 20);
    s3.setPosition(50 + CARDSIZE_X * 9 +10, 20);
    s4.setPosition(50 + CARDSIZE_X * 10 +15, 20);
    s5.setPosition(50 + CARDSIZE_X * 11 +20, 20);

//    Three Kind
    SFMLPokerName tkScore(tkText);
    tkScore.setPosition(300  + CARDSIZE_X * 7, 310);

    SFMLPokerName tk("Three Kind: ");
    tk.setPosition(50 + CARDSIZE_X * 7, 310);

    SFMLCard tk1(SEVEN, HEART);
    SFMLCard tk2(SEVEN, CLUB);
    SFMLCard tk3(SEVEN, DIAMOND);
    SFMLCard tk4(SIX, HEART);
    SFMLCard tk5(ACE, DIAMOND);
    tk1.setPosition(50 + CARDSIZE_X * 7, CARDSIZE_Y + 45) ;
    tk2.setPosition(50 + CARDSIZE_X * 8 + 5, CARDSIZE_Y + 45);
    tk3.setPosition(50 + CARDSIZE_X * 9 +10, CARDSIZE_Y + 45);
    tk4.setPosition(50 + CARDSIZE_X * 10 +15, CARDSIZE_Y + 45);
    tk5.setPosition(50 + CARDSIZE_X * 11 +20, CARDSIZE_Y + 45);

//    Two Pair
    SFMLPokerName tpScore(tpText);
    tpScore.setPosition(300  + CARDSIZE_X * 7, 485);

    SFMLPokerName tp("Two Pair: ");
    tp.setPosition(50 + CARDSIZE_X * 7, 485);

    SFMLCard tp1(FOUR, HEART);
    SFMLCard tp2(FOUR, DIAMOND);
    SFMLCard tp3(QUEEN, HEART);
    SFMLCard tp4(QUEEN, DIAMOND);
    SFMLCard tp5(KING, HEART);
    tp1.setPosition(50 + CARDSIZE_X * 7, CARDSIZE_Y * 2 + 70) ;
    tp2.setPosition(50 + CARDSIZE_X * 8 + 5, CARDSIZE_Y * 2 + 70);
    tp3.setPosition(50 + CARDSIZE_X * 9 +10, CARDSIZE_Y * 2 + 70);
    tp4.setPosition(50 + CARDSIZE_X * 10 +15, CARDSIZE_Y * 2 + 70);
    tp5.setPosition(50 + CARDSIZE_X * 11 +20, CARDSIZE_Y * 2 + 70);

//    One Pair
    SFMLPokerName opScore(opText);
    opScore.setPosition(300  + CARDSIZE_X * 7, 660);

    SFMLPokerName op("One Pair: ");
    op.setPosition(50 + CARDSIZE_X * 7, 660);

    SFMLCard op1(ACE, HEART);
    SFMLCard op2(ACE, DIAMOND);
    SFMLCard op3(THREE, HEART);
    SFMLCard op4(SEVEN, DIAMOND);
    SFMLCard op5(QUEEN, HEART);
    op1.setPosition(50 + + CARDSIZE_X * 7, CARDSIZE_Y * 3 + 95) ;
    op2.setPosition(50 + + CARDSIZE_X * 8 + 5, CARDSIZE_Y * 3 + 95) ;
    op3.setPosition(50 + + CARDSIZE_X * 9 +10, CARDSIZE_Y * 3 + 95) ;
    op4.setPosition(50 + + CARDSIZE_X * 10 +15, CARDSIZE_Y * 3 + 95) ;
    op5.setPosition(50 + + CARDSIZE_X * 11 +20, CARDSIZE_Y * 3 + 95) ;


//    High Card
    SFMLPokerName hcScore(hcText);
    hcScore.setPosition(300 + CARDSIZE_X * 7, 835);

    SFMLPokerName hc("High Card: ");
    hc.setPosition(50 + CARDSIZE_X * 7, 835);

    SFMLCard hc1(THREE, HEART);
    SFMLCard hc2(NINE, DIAMOND);
    SFMLCard hc3(EIGHT, HEART);
    SFMLCard hc4(ACE, DIAMOND);
    SFMLCard hc5(JACK, HEART);
    hc1.setPosition(50 + + CARDSIZE_X * 7, CARDSIZE_Y * 4 + 120) ;
    hc2.setPosition(50 + + CARDSIZE_X * 8 + 5, CARDSIZE_Y * 4 + 120) ;
    hc3.setPosition(50 + + CARDSIZE_X * 9 +10, CARDSIZE_Y * 4 + 120) ;
    hc4.setPosition(50 + + CARDSIZE_X * 10 +15, CARDSIZE_Y * 4 + 120) ;
    hc5.setPosition(50 + + CARDSIZE_X * 11 +20, CARDSIZE_Y * 4 + 120) ;


//  convert deck to stackDeck
    std::stack<Card> stackDeck;
    Deck deckBJ;
    deckBJ.shuffle();
    for(int i = 0; i < deckBJ.deckSize(); i++)
    {
        stackDeck.push(deckBJ.getCardAt(i));
    }



    BlackJackHandValue bjs1;

    CardHand house, bot;

    for(int i = 0; i < 2; i++)
    {
        house.getCard(stackDeck.top());
        stackDeck.pop();
        bot.getCard(stackDeck.top());
        stackDeck.pop();
    }


    int houseScore = bjs1.handValue(house);
    int botScore = bjs1.handValue(bot);


    BlackJackBotPlaying luckyBot;

//    bot thinking
    bool botQuit = false;
    while(botScore <= 21 && !botQuit)
    {
        if(luckyBot.isBotLucky(botScore) || botScore < 16)
        {
//            std::cout <<"bot score: " << botScore << std::endl;
            bot.getCard(stackDeck.top());
            stackDeck.pop();
        }
        else
        {
            botQuit = true;
        }
        botScore = 0;
        botScore = bjs1.handValue(bot);
    }
    std::cout <<"house score: " << houseScore << std::endl;
    std::cout <<"bot score: " << botScore << std::endl;

    std::cout <<"house card: " << std::endl;
    for(int i = 0; i < house.handSize(); i++)
    {
        std::cout << house.cardPos(i) << std::endl ;
    }

    std::cout <<"bot card: " << std::endl;
    for(int i = 0; i < bot.handSize(); i++)
    {
        std::cout << bot.cardPos(i) << std::endl ;
    }


//    std::stack<SFMLCard> houseStack;
//    for(int i = 0; i < house.handSize(); i++)
//    {
////        houseStack.push(SFMLCard(static_cast<RankEnum>(house.cardPos(i).getRank().getRank()),
////                static_cast<SuitEnum>(house.cardPos(i).getSuit().getSuit())));
//
//    }

//    std::vector<SFMLCard> vCard;
//    for(int i = 0; i < ch2.handSize(); i++)
//    {
//        vCard.push_back(SFMLCard(static_cast<RankEnum>(ch2.cardPos(i).getRank().getRank()),
//                static_cast<SuitEnum>(ch2.cardPos(i).getSuit().getSuit())));
//
//    }

//    std::stack<SFMLCard> botStack;
//    for(int i = 0; i < bot.handSize(); i++)
//    {
//        botStack.push(SFMLCard(static_cast<RankEnum>(bot.cardPos(i).getRank().getRank()),
//                static_cast<SuitEnum>(bot.cardPos(i).getSuit().getSuit())));
//
//    }







    BlackJackInstruction instructionImage;



    FrontPage frontPage("Thien Ho", "CS3A", "CRN: 76408", "Fall 2021");
    frontPage.setPosition(100, 400);

    Button pokerButton("Poker Analysis", sf::Color::Yellow, sf::Color::Blue, {200, 50});
    pokerButton.setPosition(100, 800);

    Button frontPageButton("FRONT PAGE", sf::Color::Yellow, sf::Color::Blue, {210, 50});
    frontPageButton.setPosition(1300, 0);

    Button gameStartButton("START GAME", sf::Color::Yellow, sf::Color::Blue, {210, 50});
    gameStartButton.setPosition(window.getSize().x/2 - 100, window.getSize().y /2 - 250 );

    Button openCardButton("OPEN", sf::Color::Yellow, sf::Color::Blue, {100, 50});
    openCardButton.setPosition(window.getSize().x/2 - 100, window.getSize().y /2);

    Button hitButton("HIT", sf::Color::Yellow, sf::Color::Blue, {100, 50});
    hitButton.setPosition(window.getSize().x/2 + 50, window.getSize().y /2);

    Button instructionButton("INSTRUCTION", sf::Color::Yellow, sf::Color::Blue, {200, 60});
    instructionButton.setPosition(window.getSize().x -200, window.getSize().y - 60);

    Button backToGameButton("BACK TO GAME", sf::Color::Yellow, sf::Color::Blue, {200, 60});
    backToGameButton.setPosition(window.getSize().x -200, window.getSize().y - 120);

    std::vector<SFMLCard> houseVector, botVector;
    for(int i = 0; i < bot.handSize(); i++)
    {
        botVector.push_back(SFMLCard(static_cast<RankEnum>(house.cardPos(i).getRank().getRank()),
                                 static_cast<SuitEnum>(house.cardPos(i).getSuit().getSuit())));
        botVector[i].setPosition(600 + i*100, 100);
    }



    bool intro = false;
    bool pokerFlag = false;
    bool gameFlag = false;
    bool faceDown = true;
    bool instruc = false;

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
                if (pokerButton.getGlobalBounds().contains(mpos))
                {
                    intro = true;
                    pokerFlag = true;
                    gameFlag = false;
                }

                if(frontPageButton.getGlobalBounds().contains(mpos))
                {
                    intro = false;
                    pokerFlag = false;
                    gameFlag = false;
                }

                if(gameStartButton.getGlobalBounds().contains(mpos))
                {
                    gameFlag = true;
                    intro = false;
                    pokerFlag = false;
                }

                if(houseScore < 21)
                {
                    if(hitButton.getGlobalBounds().contains(mpos))
                    {
                        house.getCard(stackDeck.top());
                        stackDeck.pop();
                        houseScore = bjs1.handValue(house);
                        std::cout <<"house score: " << houseScore << std::endl;

                    }
                }



                if(instructionButton.getGlobalBounds().contains(mpos))
                {
                    gameFlag = true;
                    intro = false;
                    pokerFlag = false;
                    instruc = true;
                }

                if(backToGameButton.getGlobalBounds().contains(mpos))
                {
                    gameFlag = true;
                    intro = false;
                    pokerFlag = false;
                    instruc = false;
                    faceDown = true;
                }

                if(houseScore >14)
                {
                    if (openCardButton.getGlobalBounds().contains(mpos))
                    {
                        faceDown = false;
                    }
                }

            }

        }



        window.clear(sf::Color::Cyan);




//      Intro Window
        if (!intro)
        {
            window.draw(frontPage);
            window.draw(pokerButton);
            window.draw(gameStartButton);
        }


//      Game Window
        if(gameFlag)
            {
                BlackJackInterface bjInterface;
                bjInterface.setPosition(window.getSize().x/2, 225);
                window.draw(bjInterface);
                window.draw(hitButton);
                window.draw(openCardButton);
                window.draw(frontPageButton);
                window.draw(instructionButton);
                SFMLPokerName hScore(std::to_string(houseScore));
                hScore.setPosition(window.getSize().x/2 - 350, 625);
                window.draw(hScore);


                for(int i = 0; i < botVector.size(); i++)
                {
                    window.draw(botVector.at(i));
                }

                for(int i = 0; i < house.handSize(); i++)
                {
                    houseVector.push_back(SFMLCard(static_cast<RankEnum>(house.cardPos(i).getRank().getRank()),
                                                 static_cast<SuitEnum>(house.cardPos(i).getSuit().getSuit())));
                    houseVector[i].setPosition(600 + i*100, 700);
                    window.draw(houseVector[i]);
                }


//           Instruction Window
            if(instruc)
            {
                window.draw(instructionImage);
                window.draw(backToGameButton);
            }



                if(faceDown && !instruc)
                {
                    BlackJackFaceDown fd;
                    fd.setPosition(500, 100);
                    window.draw(fd);

                }

//              open bot card and show who win
                if(!faceDown)
                {
                    SFMLPokerName bScore(std::to_string(botScore));
                    bScore.setPosition(window.getSize().x/2 - 350, 225);
                    window.draw(bScore);

                    BlackJackWhoWin whoWin;
                    SFMLPokerName winnerText(whoWin.getWinnerName(houseScore, botScore));
                    winnerText.setCharSize(50);
                    winnerText.setPosition(window.getSize().x/2 - 150, window.getSize().y/2 - 100);
                    window.draw(winnerText);
                }


        }

//      Poker Analysis
        if (pokerFlag) {
            window.draw(frontPageButton);

            window.draw(royal1);
            window.draw(royal2);
            window.draw(royal3);
            window.draw(royal4);
            window.draw(royal5);
            window.draw(royal);
            window.draw(royalScore);

            window.draw(sf1);
            window.draw(sf2);
            window.draw(sf3);
            window.draw(sf4);
            window.draw(sf5);
            window.draw(sf);
            window.draw(sfScore);

            window.draw(fk1);
            window.draw(fk2);
            window.draw(fk3);
            window.draw(fk4);
            window.draw(fk5);
            window.draw(fk);
            window.draw(fkScore);


            window.draw(fh1);
            window.draw(fh2);
            window.draw(fh3);
            window.draw(fh4);
            window.draw(fh5);
            window.draw(fh);
            window.draw(fhScore);


            window.draw(f1);
            window.draw(f2);
            window.draw(f3);
            window.draw(f4);
            window.draw(f5);
            window.draw(f);
            window.draw(fScore);


            window.draw(s1);
            window.draw(s2);
            window.draw(s3);
            window.draw(s4);
            window.draw(s5);
            window.draw(s);
            window.draw(sScore);


            window.draw(tk1);
            window.draw(tk2);
            window.draw(tk3);
            window.draw(tk4);
            window.draw(tk5);
            window.draw(tk);
            window.draw(tkScore);


            window.draw(tp1);
            window.draw(tp2);
            window.draw(tp3);
            window.draw(tp4);
            window.draw(tp5);
            window.draw(tp);
            window.draw(tpScore);


            window.draw(op1);
            window.draw(op2);
            window.draw(op3);
            window.draw(op4);
            window.draw(op5);
            window.draw(op);
            window.draw(opScore);


            window.draw(hc1);
            window.draw(hc2);
            window.draw(hc3);
            window.draw(hc4);
            window.draw(hc5);
            window.draw(hc);
            window.draw(hcScore);

        }

        window.display();
    }
    return 0;
}


