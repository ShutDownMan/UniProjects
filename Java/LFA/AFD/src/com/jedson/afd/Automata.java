package com.jedson.afd;

import java.util.*;

public class Automata {
    private ArrayList<Character> alphabet;
    private ArrayList<State> states;
    private ArrayList<State> finalStates;
    private State initialState;

    public Automata() {
        this.alphabet = new ArrayList<>();
        this.states = new ArrayList<>();
        this.finalStates = new ArrayList<>();
        this.initialState = null;
    }

    public void addSymbol(Character symbol) {
        if(!this.alphabet.contains(symbol)) {
            this.alphabet.add(symbol);
        } else {
            System.out.println(String.format("symbol '%c' is already in the alphabet!", symbol));
        }
    }

    public void addState(String stateName) {
        if(this.findStateByName(stateName) == null) {
            this.states.add(new State(stateName));
        } else {
            System.out.println(String.format("There is already a state [%s]!", stateName));
        }
    }

    public State findStateByName(String stateName) {
        for (State state : this.states) {
            if(state.getName().equals(stateName))
                return state;
        }
        return null;
    }

    public void setInitialState(String stateName) {
        State state = this.findStateByName(stateName);

        if(state != null) {
            this.initialState = state;
        } else {
            System.out.println(String.format("There is no state [%s]!", stateName));
        }
    }

    public void setFinalState(String stateName) {
        State state = this.findStateByName(stateName);

        if(state != null) {
            this.finalStates.add(state);
        } else {
            System.out.println(String.format("There is no state [%s]!", stateName));
        }
    }

    public boolean isFinalState(String stateName) {
        for (State state : this.finalStates) {
            if(state.getName().equals(stateName))
                return true;
        }

        return false;
    }

    public void createTransition(String stateFrom, Character symbol, String stateTo) {
        State fromState = this.findStateByName(stateFrom);
        State toState = this.findStateByName(stateTo);

        if(this.alphabet.contains(symbol)) {
            if(fromState != null && toState != null) {
                fromState.addTransition(symbol, toState);
            }
        } else {
            System.out.println(String.format("There is no symbol '%c' in the alphabet!", symbol));
        }

        if(fromState == null) {
            System.out.println(String.format("There is no state [%s]!", stateFrom));
        }
        if(toState == null) {
            System.out.println(String.format("There is no state [%s]!", stateTo));
        }
    }

    public void testSequence(String sequence) {
        if(this.testSequenceFromState(sequence, this.initialState)) {
            System.out.println("ACEITA");
        } else {
            System.out.println("REJEITA");
        }
    }

    public boolean testSequenceFromState(String sequence, State stateFrom) {
        Character symbol = null;

        if(stateFrom == null) return false;

        if(sequence.length() > 0) {
            symbol = sequence.charAt(0);
            System.out.println(String.format("[%s] %s", stateFrom.getName(), sequence));
        }


        if(symbol == null && this.isFinalState(stateFrom.getName())) return true;
        if(!this.alphabet.contains(symbol)) return false;

        return this.testSequenceFromState(sequence.substring(1), stateFrom.makeTransition(symbol));
    }

    public void printGrammar() {
        int offset = 0;
        LinkedHashMap<String, Character> nonTerminals = new LinkedHashMap<>();

        if(this.initialState == null) {
            System.out.println("The initial state doesn't exist!");
            return;
        }

        nonTerminals.put(this.initialState.getName(), 'S');

        for(int i = 0; i < this.states.size(); ++i) {
            if(!this.states.get(i).getName().equals(this.initialState.getName())) {
                nonTerminals.put(this.states.get(i).getName(), (char) ('A'+offset++));
            }
        }

        this.printGrammarLines(nonTerminals);
    }

    private void printGrammarLines(LinkedHashMap<String, Character> nonTerminals) {
        int i;

        for (Map.Entry<String, Character> nonTerminal : nonTerminals.entrySet()) {
            i = 0;
            String stateName = nonTerminal.getKey();
            Character nonTerminalSymbol = nonTerminal.getValue();
            State state = this.findStateByName(stateName);
            LinkedHashMap<Character, State> transitions = state.getTransitions();

            System.out.print(String.format("%c ->", nonTerminalSymbol));
            for (Map.Entry<Character, State> transition : transitions.entrySet()) {
                Character transitionSymbol = transition.getKey();
                State transitionState = transition.getValue();

                System.out.print(String.format(" %c%c ", transitionSymbol, nonTerminals.get(transitionState.getName())));
                if(i++ < transitions.size()-1) {
                    System.out.print("|");
                }
            }
            if(this.isFinalState(stateName)) {
                System.out.print("| @");
            }
            System.out.println();
        }
    }

}
