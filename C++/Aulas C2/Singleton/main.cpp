#include <iostream>

#include "Logger.h"

int main() {
    Logger *logger = Logger::getInstance();

    logger->log(new string("real good o/"));

    delete logger;

    return 0;
}