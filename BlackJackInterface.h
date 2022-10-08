

#ifndef SFML_PROJECT_BLACKJACKINTERFACE_H
#define SFML_PROJECT_BLACKJACKINTERFACE_H
#include "BlackJackHandValue.h"
#include "Deck.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class BlackJackInterface : public sf::Drawable, public sf::Transformable{
private:

    sf::Texture texture;
    sf::Sprite table;
    sf::Text houseName;
    sf::Text botName;
    sf::Text houseScore;
    sf::Text botScore;
    sf::Font font;

public:

    BlackJackInterface();
    void loadImage();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void loadFont();
    void setPosition(float x, float y);

};


#endif //SFML_PROJECT_BLACKJACKINTERFACE_H
