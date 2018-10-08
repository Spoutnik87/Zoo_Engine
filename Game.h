#ifndef GAME_H
#define GAME_H

#include "Logger.h"
#include "InputHandler.h"

class Game {
    public:
        Game();
        Logger* getLogger();
        InputHandler* getInputHandler();
        static Game* instance();

    private:
        static Game *game;
        Logger *logger;
        InputHandler *inputHandler;
};

#endif
