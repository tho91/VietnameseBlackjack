#include "PokerScore.h"

PokerScore::PokerScore() {

}

void PokerScore::operator+=(const PokerScore::Scores& score) {
    this->addScore(score);
}

int PokerScore::size() {
    return scores.size();
}

PokerScore::Scores &PokerScore::operator[](unsigned int index) {
    return scores[index];
}


bool operator==(const PokerScore& p, PokerScore::Scores score)
{

}

std::ostream& operator<<(std::ostream& out, PokerScore& score)
{


//        std::cout << "ROYAL_FLUSH: " << ROYAL_FLUSH << std::endl;
//        std::cout << "STRAIGHT_FLUSH: " << STRAIGHT_FLUSH << std::endl;
//        std::cout << "FOUR_OF_A_KIND: " << FOUR_OF_A_KIND << std::endl;
//        std::cout << "FULL_HOUSE: " << FULL_HOUSE << std::endl;
//        std::cout << "FLUSH: " << FLUSH << std::endl;
//        std::cout << "STRAIGHT: " << STRAIGHT << std::endl;
//        std::cout << "THREE_OF_A_KIND: " << THREE_OF_A_KIND << std::endl;
//        std::cout << "TWO_PAIR: " << TWO_PAIR << std::endl;
//        std::cout << "ONE_PAIR: " << ONE_PAIR << std::endl;
//        std::cout << "HIGH_CARD: " << HIGH_CARD << std::endl;

    return out;
}

void PokerScore::addScore(PokerScore::Scores score) {
    scores.push_back(score);
}


