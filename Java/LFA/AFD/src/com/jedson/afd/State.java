package com.jedson.afd;

import java.util.LinkedHashMap;

/**
 * Classe estado para autômato, possui lógica do estado
 */
public class State {
    /**
     * nome do estado
     */
    private String name;
    /**
     * tranições a partir do estado
     */
    private LinkedHashMap<Character, State> transitions;

    /**
     * Construtor inicializa estado com nome passado
     * @param stateName nome do estado
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    public State(String stateName) {
        this.name = stateName;
        this.transitions = new LinkedHashMap<>();
    }

    /**
     * getter do nome do estado
     * @return nome do estado
     */
    public String getName() {
        return name;
    }

    /**
     * addTransition adiciona nova transição partindo do estado
     * @param symbol simbolo usado na transição
     * @param toState estado de chegada
     * @pre-condition lista transitions tem que estar inicializada
     * @post-condition adiciona transição à lista
     */
    public void addTransition(Character symbol, State toState) {
        /// se transição já não existe
        if(!this.transitions.containsKey(symbol)) {
            /// adiciona a lista
            this.transitions.put(symbol, toState);
        } else {
            /// printa erro
            System.out.println(String.format("The state [%s] already has a transition with the symbol '%c'!", this.name, symbol));
        }
    }

    /**
     * makeTransition faz transição dado um símbolo
     * @param symbol simbolo usado na transição
     * @return estado chegada, se existir
     * @pre-condition lista transitions tem que estar inicializada
     * @post-condition nenhuma
     */
    public State makeTransition(Character symbol) {
        /// se existe transição com o simbolo passado
        if(this.transitions.containsKey(symbol)) {
            /// retorna estado chegada
            return this.transitions.get(symbol);
        }

        /// senão, retorna nulo
        return null;
    }

    /**
     * getTransitions getter de transitions
     * @return lista de transuções do estado
     */
    public LinkedHashMap<Character, State> getTransitions() {
        return this.transitions;
    }
}
