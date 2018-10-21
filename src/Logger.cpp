#include <iostream>
#include <string>
#include "Logger.h"

using namespace std;

Logger::Logger() {}

Logger::~Logger() {}

void Logger::log(string message) {
    cout << message << endl;
}

void Logger::info(string message) {
    log(message);
}

void Logger::debug(string message) {
    log(message);
}

void Logger::warn(string message) {
    log(message);
}

void Logger::error(string message) {
    log(message);
}
