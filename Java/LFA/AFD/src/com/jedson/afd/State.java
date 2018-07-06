package com.jedson.afd;

import java.util.LinkedHashMap;

public class State {
    private String name;
    private LinkedHashMap<Character, State> transitions;

    public State(String stateName) {
        this.name = stateName;
        this.transitions = new LinkedHashMap<>();
    }

    public String getName() {
        return name;
    }

    public void addTransition(Character symbol, State toState) {
        if(!this.transitions.containsKey(symbol)) {
            this.transitions.put(symbol, toState);
        } else {
            System.out.println(String.format("The state [%s] already has a transition with the symbol '%c'!", this.name, symbol));
        }
    }

    public State makeTransition(Character symbol) {
        if(this.transitions.containsKey(symbol)) {
            return this.transitions.get(symbol);
        }

        return null;
    }

    public LinkedHashMap<Character, State> getTransitions() {
        return this.transitions;
    }
}
