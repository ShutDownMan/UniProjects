#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <map>

using namespace std;

class State {
private:
    string *name;
    map<char, State*> *transitions;

public:
    State(string *name);

    string *getName();

    map<char, State*> *getTransitions();

    int addTransition(char symbol, State *toState);

    State *makeTransition(char symbol);

    ~State();
};

#endif // STATE_H
