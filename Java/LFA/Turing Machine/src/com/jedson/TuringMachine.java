package com.jedson;

import java.util.ArrayList;

class TuringMachine {
    private ArrayList<State> states;
    private ArrayList<Character> alphabet;
    private State initialState;

    /**
     * construtor da máquina de turing
     */
    TuringMachine() {
        this.states = new ArrayList<>();
        this.alphabet = new ArrayList<>();
        initialState = null;
    }

    /**
     * adiciona estado a máquina
     *
     * @param stateName nome do estado a ser adicionado
     * @return estado adicionado
     * @pre-condition nenhuma
     * @post-condition estado é adicionado a lista da máquina
     */
    private State addState(String stateName) {
        /// procura se estado com mesmo nome já existe
        State foundState = searchState(stateName);

        /// se não
        if (foundState == null) {
            /// cria novo estado e adiciona a lista
            foundState = new State(stateName);
            this.states.add(foundState);
        } else {
            System.out.print("Error in addState\n");
            System.out.printf("The state [%s] already exists!\n", stateName);
        }

        /// retorna estado criado
        return foundState;
    }

    /**
     * procura por estado na lista de estados da máquina
     * @param stateName nome do estado a ser procurado
     * @return estado encontrado
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    private State searchState(String stateName) {
        /// para cada estado na lista
        for (State state : states) {
            /// se nome do estado atual se iguala ao nome passado
            if (state.name.equals(stateName)) {
                /// retorna estado atual
                return state;
            }
        }
        /// se não foi encontrado, retorna nulo
        return null;
    }

    /**
     * inicializa estado inicial da máquina
     */
    void setInitialState() {
        this.initialState = addState("q0");
    }

    /**
     * procura e coloca como estado final o estado passado
     * @param stateName nome do estado
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    void setFinalState(String stateName) {
        /// adiciona por estado na lista
        State foundState = addState(stateName);

        foundState.isFinal = true;
    }

    /**
     * adiciona simbolo ao alfabeto da máquina
     * @param symbol simbolo a ser adicionado
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    void addSymbolToAlphabet(Character symbol) {
        if (!this.alphabet.contains(symbol)) {
            this.alphabet.add(symbol);
        } else {
            System.out.print("Error in addSymbolToAlphabet\n");
            System.out.printf("The symbol [%c] has already been added!\n", symbol);
        }
    }

    /**
     * adiciona transição a máquina
     * @param stateFrom estado de saida
     * @param readSymbol simbolo de leitura
     * @param stateTo estado de chegada
     * @param writeSymbol simbolo de escrita
     * @param moveDirection direção de movimento
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    void addTransition(String stateFrom, Character readSymbol, String stateTo, Character writeSymbol, Integer moveDirection) {
        State foundStateFrom = addState(stateFrom);
        State foundStateTo = addState(stateTo);

        if (alphabet.contains(readSymbol) && alphabet.contains(writeSymbol) && isValidMove(moveDirection)) {
            foundStateFrom.addTransition(readSymbol, foundStateTo, writeSymbol, moveDirection);
        } else {
            System.out.print("Error in addTransition\n");
            System.out.printf("The transition [%s, %c, %s, %c, %c] could not be added!\n", stateFrom, readSymbol, stateTo, writeSymbol, moveDirection);
        }
    }

    /**
     * testa se direção de movimento é válida
     * @param moveDir direção de movimento a ser testada
     * @return se é valida
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    private boolean isValidMove(Integer moveDir) {
        return moveDir == 1 || moveDir == -1;
    }

    /**
     * testa sequência passada na máquina
     * @param sequence sequência a ser testada
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    void testSequence(String sequence) {
        /// se sequência é aceita partindo do estado inicial
        if (this.testSequenceFromState(sequence, 1, this.initialState)) {
            /// printa aceita
            System.out.println("ACEITA");
        } else {
            /// printa rejeita
            System.out.println("REJEITA");
        }
    }

    /**
     * testa sequência na máquina a partir de um estado e uma posição da cabeça
     * @param sequence sequência a ser testada
     * @param headposition posição da cabeça de leitura/escrita da máquina
     * @param currentState estado atual
     * @return se sequência é aceita pela máquina
     */
    private boolean testSequenceFromState(String sequence, Integer headposition, State currentState) {
        Character symbol = null;

        /// se estado partida é nulo
        if (currentState == null) return false;

        /// simbolo atual
        symbol = sequence.charAt(headposition);
        /// printa estado atual da sequência
        System.out.println(String.format("%s[%s]%s", sequence.substring(0, headposition), currentState.getName(), sequence.substring(headposition)));

        /// se alfabeto não contém simbolo
        if (!this.alphabet.contains(symbol)) return false;

        Transition transition = currentState.getTransition(symbol);
        if (transition == null) {
            return currentState.isFinal;
        }

        /// testa proxima sequência a partir do simbolo lido e estado atual
        sequence = sequence.substring(0, headposition) + transition.writeSymbol + sequence.substring(headposition+1);
        return this.testSequenceFromState(sequence, headposition + transition.moveDirection, transition.stateTo);
    }

}