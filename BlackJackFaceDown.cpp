

#include "BlackJackFaceDown.h"

BlackJackFaceDown::BlackJackFaceDown() {
    loadImage();
}


void BlackJackFaceDown::loadImage() {
    if (!texture.loadFromFile("Image/cardbacksmall.png"))
        std::cout << "face down does not load !!!!!!!!!!!";
    s1.setTexture(texture);
    s2.setTexture(texture);
    s3.setTexture(texture);
    s4.setTexture(texture);
    s5.setTexture(texture);
}

void BlackJackFaceDown::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(s1);
    window.draw(s2);
    window.draw(s3);
    window.draw(s4);
    window.draw(s5);
}

void BlackJackFaceDown::setPosition(float x, float y) {
    s1.setPosition(x, y);
    s2.setPosition(x + 100, y);
    s3.setPosition(x + 200, y);
    s4.setPosition(x + 300, y);
    s5.setPosition(x + 400, y);
}
