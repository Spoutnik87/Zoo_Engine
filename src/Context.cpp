#include "Context.h"
#include "Game.h"

Context::Context() {}

Context::~Context() {
    delete window;
}

void Context::open() {
    window = new sf::RenderWindow(sf::VideoMode(
        Game::instance()->getConfigurator()->getWindowX(),
        Game::instance()->getConfigurator()->getWindowY()), "ZooEngine");
}

void Context::clear() {
    window->clear();
}

void Context::close() {
    window->close();
}

void Context::display() {
    window->display();
}

bool Context::isOpen() {
    return window->isOpen();
}

void Context::processEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            close();
        }
    }
}

void Context::setBackgroundColor(sf::Color const &color) {
    window->clear(color);
}