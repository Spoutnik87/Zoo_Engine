#include "MainMenuState.h"
#include "Game.h"
#include "Context.h"

MainMenuState::MainMenuState() : State(State::StateId::MAIN_MENU) {}

MainMenuState::~MainMenuState() {}

void MainMenuState::setup() {}

void MainMenuState::update() {}

void MainMenuState::draw() {
    Context *context = Game::instance()->getContext();
    context->clear();
    context->setBackgroundColor(sf::Color::Cyan);
    context->display();
}