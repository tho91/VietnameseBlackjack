

#include "SFMLPokerName.h"

SFMLPokerName::SFMLPokerName() {


}


void SFMLPokerName::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(handName);
}

void SFMLPokerName::loadText() {

}

void SFMLPokerName::loadFont() {
    if (!font.loadFromFile("Font/arial.ttf"))
        std::cout << "Font in poker text does not load !!!!!!!!!!!";

}

SFMLPokerName::SFMLPokerName(std::string text) {
    loadFont();
    this->text = text;
    handName.setString(text);
    handName.setFont(font);
    handName.setStyle(sf::Text::Bold);
    handName.setColor(sf::Color::Yellow);
    handName.setCharacterSize(25);
}

void SFMLPokerName::setPosition(float x, float y) {
    handName.setPosition(x, y);
}

void SFMLPokerName::setCharSize(int size) {
    handName.setCharacterSize(size);
}













//void SFMLPokerName::getCard() {
////    royalFlush.push_back()
//}
//
//void SFMLPokerName::royalHand() {
//    royalFlush.push_back(SFMLCard(ACE, DIAMOND));
//    royalFlush.push_back(SFMLCard(KING, DIAMOND));
//    royalFlush.push_back(SFMLCard(QUEEN, DIAMOND));
//    royalFlush.push_back(SFMLCard(JACK, DIAMOND));
//    royalFlush.push_back(SFMLCard(TEN, DIAMOND));
//}
//
//void SFMLPokerName::straightFlushHand() {
//    straightFlush.push_back(SFMLCard(EIGHT, HEART));
//    straightFlush.push_back(SFMLCard(SEVEN, HEART));
//    straightFlush.push_back(SFMLCard(SIX, HEART));
//    straightFlush.push_back(SFMLCard(FIVE, HEART));
//    straightFlush.push_back(SFMLCard(FOUR, HEART));
//}
//
//void SFMLPokerName::fourKindHand() {
//    fourKind.push_back(SFMLCard(JACK, HEART));
//    fourKind.push_back(SFMLCard(JACK, DIAMOND));
//    fourKind.push_back(SFMLCard(JACK, CLUB));
//    fourKind.push_back(SFMLCard(JACK, SPACE));
//    fourKind.push_back(SFMLCard(SIX, HEART));
//}
//
//void SFMLPokerName::fullHouseHand() {
//    fullHouse.push_back(SFMLCard(THREE, HEART));
//    fullHouse.push_back(SFMLCard(THREE, CLUB));
//    fullHouse.push_back(SFMLCard(THREE, DIAMOND));
//    fullHouse.push_back(SFMLCard(NINE, DIAMOND));
//    fullHouse.push_back(SFMLCard(NINE, HEART));
//}
//
//void SFMLPokerName::flushHand() {
//    flush.push_back(SFMLCard(FOUR, HEART));
//    flush.push_back(SFMLCard(JACK, HEART));
//    flush.push_back(SFMLCard(EIGHT, HEART));
//    flush.push_back(SFMLCard(TWO, HEART));
//    flush.push_back(SFMLCard(KING, HEART));
//
//}
//
//void SFMLPokerName::straightHand() {
//    straight.push_back(SFMLCard(NINE, HEART));
//    straight.push_back(SFMLCard(EIGHT, DIAMOND));
//    straight.push_back(SFMLCard(SEVEN, DIAMOND));
//    straight.push_back(SFMLCard(SIX, HEART));
//    straight.push_back(SFMLCard(FIVE, HEART));
//}
//
//void SFMLPokerName::threeKindHand() {
//    threeKind.push_back(SFMLCard(SEVEN, HEART));
//    threeKind.push_back(SFMLCard(SEVEN, CLUB));
//    threeKind.push_back(SFMLCard(SEVEN, DIAMOND));
//    threeKind.push_back(SFMLCard(SIX, HEART));
//    threeKind.push_back(SFMLCard(ACE, DIAMOND));
//}
//
//void SFMLPokerName::twoPairHand() {
//    twoPair.push_back(SFMLCard(FOUR, HEART));
//    twoPair.push_back(SFMLCard(FOUR, DIAMOND));
//    twoPair.push_back(SFMLCard(QUEEN, HEART));
//    twoPair.push_back(SFMLCard(QUEEN, DIAMOND));
//    twoPair.push_back(SFMLCard(KING, HEART));
//}
//
//void SFMLPokerName::OnePairHand() {
//    onePair.push_back(SFMLCard(ACE, HEART));
//    onePair.push_back(SFMLCard(ACE, DIAMOND));
//    onePair.push_back(SFMLCard(THREE, HEART));
//    onePair.push_back(SFMLCard(SEVEN, DIAMOND));
//    onePair.push_back(SFMLCard(QUEEN, HEART));
//}
//
//void SFMLPokerName::highCardHand() {
//    highCard.push_back(SFMLCard(THREE, HEART));
//    highCard.push_back(SFMLCard(NINE, DIAMOND));
//    highCard.push_back(SFMLCard(EIGHT, HEART));
//    highCard.push_back(SFMLCard(ACE, DIAMOND));
//    highCard.push_back(SFMLCard(FIVE, HEART));
//}
//
//
//
//SFMLCard SFMLPokerName::card(RankEnum rank, SuitEnum suit) {
//    card1.setCard(rank, suit);
//}

