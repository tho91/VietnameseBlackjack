

#include "SFMLSuit.h"

SFMLSuit::SFMLSuit() {

}

SFMLSuit::SFMLSuit(SuitEnum suitSFML) {
    loadImage(suitSFML);
}

void SFMLSuit::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(sprite, states);
}

void SFMLSuit::topPos(sf::FloatRect bounds) {
    sprite.setPosition(bounds.top, bounds.left);
}

void SFMLSuit::botPos(sf::FloatRect bounds) {
    sprite.setPosition(bounds.height, bounds.width);
}

void SFMLSuit::loadImage(SuitEnum suitSFML) {
    std::string text;
    if(suitSFML == DIAMOND)
        text = "Image/dia1.jpg";
    else if(suitSFML == SPACE)
        text = "Image/spade1.jpg";
    else if(suitSFML == CLUB)
        text = "Image/club1.jpg";
    else if(suitSFML == HEART)
        text = "Image/heart1.jpg";

    if (!texture.loadFromFile(text))
        std::cout << "Image does not load!!!!!!!!";
    sprite.setTexture(texture);
}


