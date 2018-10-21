#include <SFML/Window/Keyboard.hpp>
#include "InputHandler.h"
#include "Command.h"
#include "Game.h"

InputHandler::InputHandler() {}

InputHandler::~InputHandler() {}

Command* InputHandler::handleInput() {
    // UP KEY PRESSED
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        
    }
    // RIGHT KEY PRESSED 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

    }
    // DOWN KEY PRESSED 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        
    }
    // LEFT KEY PRESSED 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        
    }
    // SPACE KEY PRESSED 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        
    }
    return NULL;
}