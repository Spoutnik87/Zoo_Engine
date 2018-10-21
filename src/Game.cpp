#include <iostream>
#include "Game.h"
#include "Logger.h"
#include "InputHandler.h"
#include "ResourceManager.h"
#include "Configurator.h"
#include "MainMenuState.h"

Game *Game::game;

Game::Game() {
    if (game == NULL) {
        game = this;
        logger = new Logger();
        resourceManager = new ResourceManager();
        inputHandler = new InputHandler();
        configurator = new Configurator();
        context = new Context();
        currentState = new MainMenuState();
        logger->info("Initialisation de 'Game'.");
    } else {
        game->getLogger()->warn("Une instance de 'Game' existe déjà.");
    }
}

Game::~Game() {
    delete logger;
    delete resourceManager;
    delete inputHandler;
    delete configurator;
    delete context;
}

void Game::run() {
    context->open();

    currentState->setup();

    float t = 0.0;
    float dt = 0.01;
    float currentTime = sf::Time().asSeconds();
    float accumulator = 0.0;

    // Boucle de jeu à temps fixe + interpolation.
    while (context->isOpen()) {
        context->processEvents();

        Command* command = game->getInputHandler()->handleInput();

        float newTime = sf::Time().asSeconds();
        float frameTime = newTime - currentTime;
        if (frameTime > 0.25) {
            frameTime = 0.25;
        }
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt) {
            //previousState = currentState;
            //integrate(currentState, t, dt);
            t += dt;
            accumulator -= dt;
        }

        const double alpha = accumulator / dt;

        //State state = currentState * alpha + previousState * ( 1.0 - alpha );

        //render(state);

        currentState->update();
        currentState->draw();

    }
}

Logger* Game::getLogger() {
    return logger;
}

InputHandler* Game::getInputHandler() {
    return inputHandler;
}

ResourceManager* Game::getResourceManager() {
    return resourceManager;
}

Configurator* Game::getConfigurator() {
    return configurator;
}

Context* Game::getContext() {
    return context;
}

State* Game::getCurrentState() {
    return currentState;
}

Game* Game::instance() {
    return game;
}