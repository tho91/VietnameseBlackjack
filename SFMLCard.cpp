

#include "SFMLCard.h"

SFMLCard::SFMLCard() {

}

SFMLCard::SFMLCard(RankEnum rank, SuitEnum suit)
: rankSFMLCard(rank), suitSFMLCard1(suit), suitSFMLCard2(suit) {
    background.setFillColor(sf::Color::White);
    background.setSize({80, 120});
    suitSFMLCard2.rotate(180);
}

void SFMLCard::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background);
    window.draw(rankSFMLCard);
    window.draw(suitSFMLCard1);
    window.draw(suitSFMLCard2);
}

void SFMLCard::setPosition(float x, float y) {
    background.setPosition(x, y);
    sf::FloatRect backgroundBound = background.getGlobalBounds();
    suitSFMLCard1.setPosition(backgroundBound.left + 2, backgroundBound.top + 2);
    suitSFMLCard2.setPosition(x + backgroundBound.width -2,  y + backgroundBound.height -2);
    rankSFMLCard.setPosition(x + backgroundBound.width /2 - 10, y + backgroundBound.height /2 -25);
}

SFMLCard SFMLCard::setCard(RankEnum rank, SuitEnum suit) {
    this->rankSFMLCard = rank;
    this->suitSFMLCard1 = suit;
    this->suitSFMLCard2 = suit;
}
