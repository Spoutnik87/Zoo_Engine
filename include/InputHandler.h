#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include "Command.h"

using namespace std;

class InputHandler {
    public:
        InputHandler();
        Command* handleInput();

    private:
};

#endif
