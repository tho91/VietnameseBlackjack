

#ifndef SFML_PROJECT_HOUSE_H
#define SFML_PROJECT_HOUSE_H
#include "Deck.h"
#include <vector>
#include "SFMLCard.h"

class House {
private:
    std::vector<SFMLCard> houseCard;

public:
    House();
    void getCard();

};


#endif //SFML_PROJECT_HOUSE_H
