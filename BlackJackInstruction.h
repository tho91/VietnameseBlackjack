
#ifndef SFML_PROJECT_BLACKJACKINSTRUCTION_H
#define SFML_PROJECT_BLACKJACKINSTRUCTION_H
#include <SFML/Graphics.hpp>
#include <iostream>

class BlackJackInstruction : public sf::Drawable {
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    BlackJackInstruction();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void loadImage();

};


#endif //SFML_PROJECT_BLACKJACKINSTRUCTION_H
