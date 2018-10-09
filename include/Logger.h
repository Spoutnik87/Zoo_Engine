#ifndef LOGGER_H
#define LOGGER_H

#include <string>

using namespace std;

class Logger {
    public:
        Logger();
        void info(string message);
        void debug(string message);
        void warn(string message);
        void error(string message);

    private:
        void log(string message);
};

#endif