#ifndef GAME_H
#define GAME_H

#include "Logger.h"
#include "InputHandler.h"
#include "ResourceManager.h"
#include "Configurator.h"
#include "Context.h"
#include "State.h"

class Game {
    public:
        Game();
        ~Game();
        void run();
        Logger* getLogger();
        InputHandler* getInputHandler();
        ResourceManager* getResourceManager();
        Configurator* getConfigurator();
        Context* getContext();
        State* getCurrentState();
        static Game* instance();

    private:
        static Game *game;
        Logger *logger;
        InputHandler *inputHandler;
        ResourceManager *resourceManager;
        Configurator *configurator;
        Context *context;
        State *currentState;
};

#endif
