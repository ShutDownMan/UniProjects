#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <vector>
#include <map>
#include "state.h"

using namespace std;

class Automata {
private:
    vector<char> *alphabet;
    vector<State*> *states;
    vector<State*> *finalStates;
    State* initialState;

public:
    Automata();

    int addSymbol(char symbol);

    int containsSymbol(char symbol);

    int addState(string *stateName);

    State *findState(string *stateName);

    int setInitialState(string *stateName);

    int setStateFinal(string *stateName);

    int isFinal(string *stateName);

    int createTransition(string *fromStateName, string *toStateName, char symbol);

    int testSequence(char *word);

    int testSequenceFromState(char *word, State *state);

    void printGrammar();

    void printGrammarLines(map<string *, char> *nonTerminals);

    ~Automata();
};

#endif // AUTOMATA_H
