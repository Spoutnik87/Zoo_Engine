#ifndef ZOOENGINE_GAMESTATE_H
#define ZOOENGINE_GAMESTATE_H

#include "State.h"

class GameState : public State {
    public:
        GameState();
        ~GameState();
        void setup();
        void update();
        void draw();
};


#endif