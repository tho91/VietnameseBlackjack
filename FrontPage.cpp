

#include "FrontPage.h"

FrontPage::FrontPage() {

}

FrontPage::FrontPage(std::string myName, std::string courseName, std::string crn, std::string semester) {
    setEverything(myName, courseName, crn, semester);
    loadImage();
    gameName.setString("Vietnamese Blackjack");
    gameName.setCharacterSize(100);
    gameName.setFont(font);
    gameName.setColor(sf::Color::Red);
}

void FrontPage::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(myName);
    window.draw(courseName);
    window.draw(crn);
    window.draw(semester);
    window.draw(sprite);
    window.draw(gameName);
}

void FrontPage::loadImage() {
    if (!texture.loadFromFile("Image/interfacesmall.PNG"))
        std::cout << "interface does not load!!!!!!!!";
    sprite.setTexture(texture);
}

void FrontPage::setEverything(std::string myName, std::string courseName, std::string crn, std::string semester) {
    if (!font.loadFromFile("Font/arial.ttf"))
        std::cout << "Font does not load !!!!!!!!!!!";
    this->myName.setString(myName);
    this->myName.setFont(font);
    this->myName.setColor(sf::Color::Red);
    this->myName.setStyle(sf::Text::Bold);
    this->myName.setCharacterSize(30);

    this->courseName.setString(courseName);
    this->courseName.setFont(font);
    this->courseName.setColor(sf::Color::Red);
    this->courseName.setStyle(sf::Text::Bold);
    this->courseName.setCharacterSize(30);

    this->crn.setString(crn);
    this->crn.setFont(font);
    this->crn.setColor(sf::Color::Red);
    this->crn.setStyle(sf::Text::Bold);
    this->crn.setCharacterSize(30);

    this->semester.setString(semester);
    this->semester.setFont(font);
    this->semester.setColor(sf::Color::Red);
    this->semester.setStyle(sf::Text::Bold);
    this->semester.setCharacterSize(30);
}

void FrontPage::setPosition(float x, float y) {
    myName.setPosition(x , y);
    courseName.setPosition(x, y + 50);
    crn.setPosition(x, y + 100);
    semester.setPosition(x, y + 150);
    gameName.setPosition(x + 150, 50);
    sprite.setPosition(x + 300,y);
}
