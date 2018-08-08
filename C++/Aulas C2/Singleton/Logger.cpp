//
// Created by Jedson on 8/7/2018.
//

#include "Logger.h"

Logger *Logger::instance = nullptr;

Logger::Logger() {

}

Logger *Logger::getInstance() {
    if(instance) instance = new Logger();;
    return instance;
}

void Logger::log(string *message) {
    cout << *message << endl;
}

Logger::~Logger() {
    instance = nullptr;
}
