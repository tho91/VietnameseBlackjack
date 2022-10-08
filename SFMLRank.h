

#ifndef SFML_PROJECT_SFMLRANK_H
#define SFML_PROJECT_SFMLRANK_H
#include "Ranks.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SFMLRank : public sf::Drawable, public sf::Transformable{
private:
    sf::Font font;
    Ranks rankSFML;
    sf::Text textSFML;
    std::string text;
public:
    SFMLRank();
    SFMLRank(RankEnum rankSFML);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void loadText(RankEnum rank);
    sf::Text getText(sf::Text textSFML);
};


#endif //SFML_PROJECT_SFMLRANK_H
