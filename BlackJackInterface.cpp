

#include "BlackJackInterface.h"

void BlackJackInterface::loadImage() {
    if (!texture.loadFromFile("Image/table.jpg"))
        std::cout << "Table does not load !!!!!!!!!!!";
    table.setTexture(texture);


}

BlackJackInterface::BlackJackInterface() {
    loadImage();
    loadFont();
    houseName.setString("HOUSE");
    houseName.setFont(font);
    houseName.setStyle(sf::Text::Bold);
    houseName.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    houseName.setCharacterSize(35);

    botName.setString("BOT");
    botName.setFont(font);
    botName.setStyle(sf::Text::Bold);
    botName.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    botName.setCharacterSize(35);

    houseScore.setString("HOUSE SCORE:");
    houseScore.setFont(font);
    houseScore.setStyle(sf::Text::Bold);
    houseScore.setColor(sf::Color::Red);
    houseScore.setCharacterSize(35);

    botScore.setString("BOT SCORE:");
    botScore.setFont(font);
    botScore.setStyle(sf::Text::Bold);
    botScore.setColor(sf::Color::Red);
    botScore.setCharacterSize(35);


}


void BlackJackInterface::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(table);
    window.draw(houseName, states);
    window.draw(botName, states);
    window.draw(botScore, states);
    window.draw(houseScore, states);
}

void BlackJackInterface::loadFont() {
    if (!font.loadFromFile("Font/arial.ttf"))
        std::cout << "Font in blackjack interface does not load !!!!!!!!!!!";
}

void BlackJackInterface::setPosition(float x, float y) {
    botName.setPosition(x, y);
    houseName.setPosition(x, y + 400);
    botScore.setPosition(x - 700, y );
    houseScore.setPosition(x - 700, y +400);
}



