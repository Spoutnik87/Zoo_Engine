#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Command.h"

class InputHandler {
    public:
        InputHandler();
        ~InputHandler();
        Command* handleInput();

    private:
};

#endif
