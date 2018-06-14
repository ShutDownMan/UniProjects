#include "state.h"

State::State(string *name) {
    this->transitions = new map<char, State*>();
    this->name = name;
}

string *State::getName() {
    return this->name;
}

map<char, State *> *State::getTransitions() {
    return this->transitions;
}

int State::addTransition(char symbol, State *toState) {
    if(this->transitions->find(symbol) != this->transitions->end()) {
        cerr << "The state ["
             << this->name
             << "] already has a transition with the symbol ("
             << symbol
             << ")!"
             << endl;
        return 0;
    }

    this->transitions->insert(pair<char, State*>(symbol, toState));

    return 1;
}

State *State::makeTransition(char symbol) {
    if(this->transitions->find(symbol) != this->transitions->end()) {
        return this->transitions->at(symbol);
    }

    return NULL;
}

State::~State() {
    cout << "The state "
         << this->name
         << " is being destroyed"
         << endl;
}
