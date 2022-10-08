

#include "SFMLRank.h"

SFMLRank::SFMLRank() {

}

SFMLRank::SFMLRank(RankEnum rankSFML){
    if (!font.loadFromFile("Font/arial.ttf"))
        std::cout << "Font in sfml rank does not load !!!!!!!!!!!";
    loadText(rankSFML);
    textSFML.setString(text);
    textSFML.setFont(font);
    textSFML.setStyle(sf::Text::Bold);
    textSFML.setColor(sf::Color::Red);
    textSFML.setCharacterSize(35);
}


void SFMLRank::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(textSFML, states);
}

void SFMLRank::loadText(RankEnum rankSFML) {

    switch(rankSFML){
        case ACE: text = "A"; break;
        case TWO: text = "2"; break;
        case THREE: text = "3"; break;
        case FOUR: text = "4"; break;
        case FIVE: text = "5"; break;
        case SIX: text = "6"; break;
        case SEVEN: text = "7"; break;
        case EIGHT: text = "8"; break;
        case NINE: text = "9"; break;
        case TEN: text = "10"; break;
        case JACK: text = "J"; break;
        case QUEEN: text = "Q"; break;
        case KING: text = "K"; break;
        default:
            std::cout << "Something wrong in load text in SFMLRank";
    }
}

sf::Text SFMLRank::getText(sf::Text textSFML) {
    return this->textSFML;
}

