

#ifndef SFML_PROJECT_SFMLSUIT_H
#define SFML_PROJECT_SFMLSUIT_H
#include "Suits.h"
#include <SFML/Graphics.hpp>
#include "iostream"

class SFMLSuit : public sf::Drawable, public sf::Transformable{
private:
    Suits suitSFML;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    SFMLSuit();
    SFMLSuit(SuitEnum suitSFML);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void topPos(sf::FloatRect bounds);
    void botPos(sf::FloatRect bounds);
    void loadImage(SuitEnum suitSFML);
};


#endif //SFML_PROJECT_SFMLSUIT_H
