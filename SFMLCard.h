
#ifndef SFML_PROJECT_SFMLCARD_H
#define SFML_PROJECT_SFMLCARD_H
#include <SFML/Graphics.hpp>
#include "SFMLBackground.h"
#include "SFMLRank.h"
#include "SFMLSuit.h"

class SFMLCard : public sf::Drawable{
private:
    SFMLBackground background;
    SFMLSuit suitSFMLCard1;
    SFMLSuit suitSFMLCard2;
    SFMLRank rankSFMLCard;
public:
    SFMLCard();
    SFMLCard(RankEnum rank, SuitEnum suit);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    SFMLCard setCard(RankEnum rank, SuitEnum suit);

};


#endif //SFML_PROJECT_SFMLCARD_H
