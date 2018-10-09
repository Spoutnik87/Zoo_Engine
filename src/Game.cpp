#include "Game.h"
#include "Logger.h"
#include "InputHandler.h"

Game* Game::game;

Game::Game() {
    if (game == NULL) {
        game = this;
        *logger = Logger();
        *inputHandler = InputHandler();
        logger->info("Initialisation de 'Game'.");
    }
    else {
        game->getLogger()->warn("Une instance de 'Game' existe déjà.");
    }
}

Logger* Game::getLogger() {
    return logger;
}

InputHandler* Game::getInputHandler() {
    return inputHandler;
}

Game* Game::instance() {
    return game;
}