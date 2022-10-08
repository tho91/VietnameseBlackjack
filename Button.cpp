

#include "Button.h"

Button::Button() : Button("OK", sf::Color::White, sf::Color::Blue, {100, 50})
{

}

Button::Button(std::string text) : Button(text, sf::Color::White, sf::Color::Blue, {100, 50})
{

}

Button::Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size)
{
    font.loadFromFile("Font/arial.ttf");
    this->text.setFont(font);
    this->text.setFillColor(textColor);
    this->text.setString(text);
    this->text.setCharacterSize(25);

    background.setSize(size);
    background.setFillColor(color);



}

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(text);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(background.getGlobalBounds().contains(mpos))
    {
        enabledState(HOVERED);
    }
    else
    {
        disableState(HOVERED);
    }

}

void Button::update()
{
    if(isEnabled(HOVERED))
    {
        background.setFillColor(sf::Color::Yellow);
    }
    else
    {
        background.setFillColor(sf::Color::White);
    }

}

void Button::setPosition(float x, float y) {
    background.setPosition(x, y);
    sf::FloatRect tb = this->text.getGlobalBounds();
    sf::FloatRect bb = background.getGlobalBounds();

    this->text.setPosition(bb.left + bb.width/2 - tb.width/2, bb.top + bb.height/2 - tb.height);
}

sf::FloatRect Button::getGlobalBounds() {
    return background.getGlobalBounds();
}

void Button::setText(std::string text) {
    this->text.setString(text);
}

void Button::setColor(sf::Color color) {
    this->background.setFillColor(color);
}

void Button::setTextColor(sf::Color textColor) {
    this->text.setFillColor(textColor);
}

void Button::setSize(sf::Vector2f size) {
    this->background.setSize(size);
}
