#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automata.h"

#include <conio.h>

#define MAXSTR 256

using namespace std;

void initializeAutomata(Automata *automata, const char *fileName);

void readAlphabet(Automata *automata, FILE *f);

void readStates(Automata *automata, FILE *f);

void readInitialState(Automata *automata, FILE *f);

void readFinalStates(Automata *automata, FILE *f);

void readTransitions(Automata *automata, FILE *f);

int main(int argc, char const *argv[]) {
    Automata *automata = new Automata();

    if(argc > 1)
        initializeAutomata(automata, argv[1]);

    automata->testSequence((char*)"ab00cb");
    automata->testSequence((char*)"abbac");

    automata->printGrammar();

    return 0;
}

void initializeAutomata(Automata *automata, const char *fileName) {
    FILE *f = fopen(fileName, "r+");

    // TODO: Ler alfabeto
    readAlphabet(automata, f);

    // TODO: Ler estados
    readStates(automata, f);

    // TODO: Colocar atributos dos estados
    readInitialState(automata, f);
    readFinalStates(automata, f);

    // TODO: Atribuir transições
    readTransitions(automata, f);

    fclose(f);
}

void readAlphabet(Automata *automata, FILE *f) {
    char symbolsStr[MAXSTR] = {0};
    char symbol;
    int offset, n;

    fscanf(f, " alfabeto={ %[^}] }", symbolsStr);

    for(offset = n = 0; offset < (int)strlen(symbolsStr); offset += n) {
        sscanf(symbolsStr+offset, "%c ,%n", &symbol, &n);
        automata->addSymbol(symbol);
    }
}

void readStates(Automata *automata, FILE *f) {
    char statesStr[MAXSTR] = {0}, aux[MAXSTR] = {0};
    int offset, n;

    fscanf(f, " estados={ %[^}] }", statesStr);

    for(offset = n = 0; offset < (int)strlen(statesStr); offset += n) {
        sscanf(statesStr+offset, "%[^,],%n", (char*)&aux, &n);

        string *stateName = new string(aux);
        automata->addState(stateName);
    }
}

void readInitialState(Automata *automata, FILE *f) {
    char str[MAXSTR] = {0};

    fscanf(f, " inicial=%s", (char*)str);

    string *initialStateName = new string(str);
    automata->setInitialState(initialStateName);

    delete initialStateName;
}

void readFinalStates(Automata *automata, FILE *f) {
    char statesStr[MAXSTR] = {0}, aux[MAXSTR] = {0};
    int offset, n;

    fscanf(f, " finais={ %[^}] }", statesStr);

    for(offset = n = 0; offset < (int)strlen(statesStr); offset += n) {
        sscanf(statesStr+offset, "%[^,],%n", (char*)&aux, &n);

        string *stateName = new string(aux);
        automata->setStateFinal(stateName);

        delete stateName;
    }
}

void readTransitions(Automata *automata, FILE *f) {
    char stateFrom[MAXSTR] = {0}, stateTo[MAXSTR] = {0};
    char symbol = 0;

    while(!feof(f)) {
        fscanf(f, " (%[^,],%c)= %s", (char*)stateFrom, &symbol, (char*)stateTo);

        string *stateFromName = new string(stateFrom);
        string *toStateName = new string(stateTo);

        automata->createTransition(stateFromName, toStateName, symbol);

        delete stateFromName;
        delete toStateName;
    }
}
