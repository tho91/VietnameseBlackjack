

#include "BlackJackInstruction.h"

BlackJackInstruction::BlackJackInstruction() {
    loadImage();
}

void BlackJackInstruction::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(sprite);
}

void BlackJackInstruction::loadImage() {
    if (!texture.loadFromFile("Image/instruction.PNG"))
        std::cout << "Instruction does not load !!!!!!!!!!!";
    sprite.setTexture(texture);
}
