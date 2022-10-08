

#ifndef SFML_PROJECT_BLACKJACKFACEDOWN_H
#define SFML_PROJECT_BLACKJACKFACEDOWN_H
#include <SFML/Graphics.hpp>
#include <iostream>

class BlackJackFaceDown : public sf::Transformable, public sf::Drawable{
private:
    sf::Texture texture;
    sf::Sprite s1, s2, s3, s4, s5;

public:
    BlackJackFaceDown();
    void loadImage();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
};


#endif //SFML_PROJECT_BLACKJACKFACEDOWN_H
