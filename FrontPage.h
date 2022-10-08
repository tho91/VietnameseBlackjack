
#ifndef SFML_PROJECT_FRONTPAGE_H
#define SFML_PROJECT_FRONTPAGE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class FrontPage : public sf::Drawable, public sf::Transformable{
private:
    sf::Text gameName;
    sf::Text myName;
    sf::Text courseName;
    sf::Text crn;
    sf::Text semester;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
public:
    FrontPage();
    FrontPage(std::string myName, std::string courseName, std::string crn, std::string semester);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void loadImage();
    void setEverything(std::string myName, std::string courseName, std::string crn, std::string semester);
    void setPosition(float x, float y);
};


#endif //SFML_PROJECT_FRONTPAGE_H
