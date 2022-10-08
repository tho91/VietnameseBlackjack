

#ifndef SFML_PROJECT_SFMLPOKERNAME_H
#define SFML_PROJECT_SFMLPOKERNAME_H
#include <SFML/Graphics.hpp>
#include "SFMLCard.h"
#include <vector>
#include "Deck.h"

class SFMLPokerName : public sf::Drawable, public sf::Transformable{
private:
    sf::Font font;
    sf::Text handName;
    sf::Text text2;
    std::string text;
public:
    SFMLPokerName();
    SFMLPokerName(std::string text);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void loadText();
    void loadFont();
    void setPosition(float x, float y);
    void setCharSize(int size);
};


#endif //SFML_PROJECT_SFMLPOKERNAME_H
