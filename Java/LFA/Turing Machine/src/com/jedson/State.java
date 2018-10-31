package com.jedson;

import java.util.ArrayList;

class State {
    String name;
    private ArrayList<Transition> transitions;
    boolean isFinal;

    /**
     * inicializa estado a partir de um nome passado
     * @param name nome do estado
     */
    State(String name) {
        this.transitions = new ArrayList<>();
        this.name = name;
        this.isFinal = false;
    }

    /**
     * adiciona transição ao estado
     * @param readSymbol simbolo de leitura
     * @param stateTo estado de chegada
     * @param writeSymbol simbolo de escrita
     * @param moveDirection direção de movimento
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    void addTransition(Character readSymbol, State stateTo, Character writeSymbol, Integer moveDirection) {
        transitions.add(new Transition(readSymbol, stateTo, writeSymbol, moveDirection));
    }

    /**
     * retorna nome do estado
     * @return nome do estado
     */
    String getName() {
        return this.name;
    }

    /**
     * retorna transição a partir do simbolo de leitura
     * @param symbol simbolo de leitura usado na transição
     * @return transição correspondente ao simbolo de leitura passado
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    Transition getTransition(Character symbol) {
        /// para cada transição na lista de trasições
        for (Transition transition : this.transitions) {
            /// se simbolo de leitura da transição atual se igualar ao simbolo passado
            if(transition.readSymbol == symbol) {
                /// retorna transição atual
                return transition;
            }
        }
        return null;
    }
}
