#ifndef ZOOENGINE_MAINMENUSTATE_H
#define ZOOENGINE_MAINMENUSTATE_H

#include "State.h"

class MainMenuState : public State {
    public:
        MainMenuState();
        ~MainMenuState();
        void setup();
        void update();
        void draw();
};


#endif