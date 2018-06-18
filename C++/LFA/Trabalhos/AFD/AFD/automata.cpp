#include "automata.h"

Automata::Automata() {
    this->alphabet = new vector<char>();
    this->states = new vector<State*>();
    this->finalStates = new vector<State*>();
    this->initialState = NULL;
}

int Automata::addSymbol(char symbol) {
    if(this->containsSymbol(symbol)) return 0;

    this->alphabet->push_back(symbol);

    return 1;
}

int Automata::containsSymbol(char symbol) {
    for(int i = 0; i < (int)this->alphabet->size(); ++i) {
        if(this->alphabet->at(i) == symbol) {
            cerr << "The symbol "
                 << symbol
                 << " is already present in the alphabet!"
                 << endl;
            return 0;
        }
    }

    return 1;
}

int Automata::addState(string *stateName) {
    if(this->findState(stateName)) return 0;

    this->states->push_back(new State(stateName));

    return 1;
}

State *Automata::findState(string *stateName) {
    for(int i = 0; i < (int)this->states->size(); ++i) {
        if(*this->states->at(i)->getName() == *stateName) {
            return this->states->at(i);
        }
    }

    return NULL;
}

int Automata::setInitialState(string *stateName) {
    for(int i = 0; i < (int)this->states->size(); ++i) {
        if(*this->states->at(i)->getName() == *stateName) {
            this->initialState = this->states->at(i);
            return 1;
        }
    }

    cerr << "The state " << (*stateName) << " doesn't exist!" << endl;

    return 0;
}

int Automata::setStateFinal(string *stateName) {
    for(int i = 0; i < (int)this->states->size(); ++i) {
        if(*this->states->at(i)->getName() == *stateName) {
            this->finalStates->push_back(this->states->at(i));
            return 1;
        }
    }

    cerr << "The state " << (*stateName) << " doesn't exist!" << endl;

    return 0;
}

int Automata::isFinal(string *stateName) {
    for(int i = 0; i < (int)this->finalStates->size(); ++i) {
        if(*this->finalStates->at(i)->getName() == *stateName) {
            return 1;
        }
    }

    return 0;
}

int Automata::createTransition(string *fromStateName, string *toStateName, char symbol) {
    State *fromState = findState(fromStateName);
    State *toState = findState(toStateName);

    if(this->containsSymbol(symbol)) {
        if(fromState && toState) {
            fromState->addTransition(symbol, toState);
        }
    } else {
        cerr << "The symbol " << symbol << " doesn't exist!" << endl;
    }

    if(!fromState)
        cerr << "The state " << (*fromStateName) << " doesn't exist!" << endl;
    if(!toState)
        cerr << "The state " << (*toStateName) << " doesn't exist!" << endl;

    return 0;
}

int Automata::testSequence(char *word) {
    if(this->testSequenceFromState(word, this->initialState)) {
        cout << "ACEITA" << endl;
        return 1;
    }
    cout << "REJEITA" << endl;
    return 0;
}

int Automata::testSequenceFromState(char *word, State *state) {
    char symbol = word[0];

    if(!state) return 0;

    cout << "[" << *state->getName() << "] " << word << endl;

    if(!symbol && this->isFinal(state->getName())) return 1;
    if(!this->containsSymbol(symbol)) return 0;

    return this->testSequenceFromState(word+1, state->makeTransition(symbol));
}

void Automata::printGrammar() {
    int offset = 0;
    map<string*, char> *nonTerminals = new map<string*, char>();

    if(!this->initialState) {
        cerr << "The initial state doesn't exist!" << endl;
        return;
    }

    nonTerminals->insert(pair<string*, char>(this->initialState->getName(), 'S'));

    for(int i = 0; i < (int)this->states->size(); ++i) {
        if(*this->states->at(i)->getName() != *this->initialState->getName()) {
            nonTerminals->insert(pair<string*, char>(this->states->at(i)->getName(), 'A'+offset++));
        }
    }

    this->printGrammarLines(nonTerminals);

    delete nonTerminals;
}

void Automata::printGrammarLines(map<string*, char> *nonTerminals) {
    map<char, State*> *stateTransitions = NULL;
    map<string*, char>::iterator itr;
    map<char, State*>::iterator jtr;

    for(itr = nonTerminals->begin(); itr != nonTerminals->end(); ++itr) {
        string *stateName = itr->first;
        State *state = this->findState(stateName);
        stateTransitions = state->getTransitions();

        cout << itr->second << " ->";
        for(jtr = stateTransitions->begin(); jtr != stateTransitions->end();) {
            cout << " " << jtr->first << (nonTerminals->at(state->makeTransition(jtr->first)->getName())) << " ";

            if(++jtr != stateTransitions->end()) {
                cout << "|";
            }
        }

        if(this->isFinal(state->getName())) cout << "| @";
        cout << endl;
    }
}
