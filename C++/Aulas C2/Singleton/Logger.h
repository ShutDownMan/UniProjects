//
// Created by Jedson on 8/7/2018.
//

#ifndef SINGLETON_SINGLETON_H
#define SINGLETON_SINGLETON_H

#include <iostream>

using namespace std;

class Logger {
private:
    static Logger *instance;
    Logger();

public:
    static Logger *getInstance();
    void log(string *message);
    ~Logger();
};


#endif //SINGLETON_SINGLETON_H
