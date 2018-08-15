package com.jedson.afd;

import java.util.*;

/**
 * Classe autômato possui uma lista de estados e funções para leitura de palavra e print da gramática
 */
public class Automata {
    /**
     * alphabet é uma lista de carácteres que representam os simbolos do alfabeto do autômato
     */
    private ArrayList<Character> alphabet;
    /**
     * states é a lista de estados do autômato
     */
    private ArrayList<State> states;
    /**
     * finalStates é a lista de estados finais
     */
    private ArrayList<State> finalStates;
    /**
     * initialState é o estado inicial do autômato
     */
    private State initialState;

    /**
     * Construtor inicializa as listas
     */
    public Automata() {
        this.alphabet = new ArrayList<>();
        this.states = new ArrayList<>();
        this.finalStates = new ArrayList<>();
        this.initialState = null;
    }

    /**
     * addSymbol adiciona simbolo ao alfabeto
     * @param symbol simbolo a ser adicionado
     * @pre-condition alfabeto tem que estar inicializado
     * @post-condition simbolo é adicionado ao alfabeto
     */
    public void addSymbol(Character symbol) {
        /// se simbolo já não existe
        if(!this.alphabet.contains(symbol)) {
            /// adiciona na lista
            this.alphabet.add(symbol);
        } else {
            /// printa erro
            System.out.println(String.format("symbol '%c' is already in the alphabet!", symbol));
        }
    }

    /**
     * addState adiciona estado a lista de estados
     * @param stateName nome do estado
     * @post-condition lista tem que estar inicializada
     * @pre-condition estado é adicionado a lista
     */
    public void addState(String stateName) {
        /// se estado já não existe
        if(this.findStateByName(stateName) == null) {
            /// adiciona estado
            this.states.add(new State(stateName));
        } else {
            /// printa erro
            System.out.println(String.format("There is already a state [%s]!", stateName));
        }
    }

    /**
     * findStateByName procura estado por nome dado
     * @param stateName nome do estado
     * @return estado encontrado ou NULL
     * @pre-condition lista tem que estar inicializada
     * @post-condition nenhuma
     */
    public State findStateByName(String stateName) {
        /// para cada estado na lista
        for (State state : this.states) {
            /// se nome dp estado se iguala ao nome passado
            if(state.getName().equals(stateName))
                return state; //< retorna estado
        }
        /// estado não encontrado
        return null;
    }

    /**
     * setInitialState atribui estado passado como inicial
     * @param stateName nome do estado
     * @pre-condition lista de estados tem que estar incializada
     * @post-condition atribui estado achado como inicial
     */
    public void setInitialState(String stateName) {
        /// procura estado por nome
        State state = this.findStateByName(stateName);

        /// se estado foi encontrado
        if(state != null) {
            /// atribui como estado inicial
            this.initialState = state;
        } else {
            /// printa erro
            System.out.println(String.format("There is no state [%s]!", stateName));
        }
    }

    /**
     * setFinalState atribui estado como estado final
     * @param stateName nome do estado
     * @pre-condition lista de estados finais tem que estar inicializada
     * @post-condition estado é atribuido como final
     */
    public void setFinalState(String stateName) {
        /// procura estado por nome
        State state = this.findStateByName(stateName);

        /// se estado foi encontrado
        if(state != null) {
            /// atribui como final
            this.finalStates.add(state);
        } else {
            /// printa erro
            System.out.println(String.format("There is no state [%s]!", stateName));
        }
    }

    /**
     * isFinalState testa se estado é estado final
     * @param stateName nome do estado
     * @return verdadeiro se estado é final
     * @pre-condition lista de estado finais tem que estar inicializada
     * @post-condition nenhuma
     */
    public boolean isFinalState(String stateName) {
        /// para cada estado na lista de estados finais
        for (State state : this.finalStates) {
            /// se nome do estado atual se iguala ao nome passado
            if(state.getName().equals(stateName))
                return true; //< estado é final
        }

        /// estado não é final
        return false;
    }

    /**
     * cria transição de um estado a outro por um simbolo
     * @param stateFrom estado de partida
     * @param symbol simbolo usado na transição
     * @param stateTo estado de chegada
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    public void createTransition(String stateFrom, Character symbol, String stateTo) {
        /// procura por estados de partida e chegada na lista
        State fromState = this.findStateByName(stateFrom);
        State toState = this.findStateByName(stateTo);

        /// se simbolo existe no alfabeto
        if(this.alphabet.contains(symbol)) {
            /// se estados existem
            if(fromState != null && toState != null) {
                /// adiciona transição ao estado de partida
                fromState.addTransition(symbol, toState);
            }
        } else {
            /// printa que simbolo não existe no alfabeto
            System.out.println(String.format("There is no symbol '%c' in the alphabet!", symbol));
        }

        /// se estado de partida não existe
        if(fromState == null) {
            /// printa que estado de partida não existe
            System.out.println(String.format("There is no state [%s]!", stateFrom));
        }
        if(toState == null) {
            /// printa que estado de chegada não existe
            System.out.println(String.format("There is no state [%s]!", stateTo));
        }
    }

    /// testSequence testa palavra no autômato
    /// param sequence, palavra a ser testada
    /// precondição nenhuma
    /// póscondição nenhuma

    /**
     * testSequence testa palavra no autômato
     * @param sequence palavra a ser testada
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    public void testSequence(String sequence) {
        /// se sequência é aceita partindo do estado inicial
        if(this.testSequenceFromState(sequence, this.initialState)) {
            /// printa aceita
            System.out.println("ACEITA");
        } else {
            /// printa rejeita
            System.out.println("REJEITA");
        }
    }

    /**
     * testSequenceFromState testa sequência a partir de um estado
     * @param sequence sequência a ser testada
     * @param stateFrom estado de partida
     * @return verdadeiro se sequência foi aceita
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    public boolean testSequenceFromState(String sequence, State stateFrom) {
        Character symbol = null;

        /// se estado partida é nulo
        if(stateFrom == null) return false;

        /// se sequência tem tamanho maior que 0
        if(sequence.length() > 0) {
            /// simbolo atual
            symbol = sequence.charAt(0);
            /// printa estado atual da sequência
            System.out.println(String.format("[%s] %s", stateFrom.getName(), sequence));
        }

        /// se simbolo é nulo (sequencia acabou) e estado atual é final
        if(symbol == null && this.isFinalState(stateFrom.getName())) return true;
        /// se palavra não contém ssimbolo
        if(!this.alphabet.contains(symbol)) return false;

        /// testa proxima sequência a partir do estado feita a
        return this.testSequenceFromState(sequence.substring(1), stateFrom.makeTransition(symbol));
    }

    /**]
     * printGrammar printa a gramática do automato finito na saida padrão
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    public void printGrammar() {
        int offset = 0;
        LinkedHashMap<String, Character> nonTerminals = new LinkedHashMap<>();

        /// se estado inicial não está atribuido
        if(this.initialState == null) {
            /// printa erro
            System.out.println("The initial state doesn't exist!");
            return;
        }

        /// adiciona estado inicial na lista de não terminal
        nonTerminals.put(this.initialState.getName(), 'S');

        /// para cada estado na lista
        for (State state : this.states) {
            /// se estado atual não é inicial
            if (!state.getName().equals(this.initialState.getName())) {
                /// adiciona na lista como não terminal
                nonTerminals.put(state.getName(), (char) ('A' + offset++));
            }
        }

        /// printa linhas da gramática
        this.printGrammarLines(nonTerminals);
    }

    /**
     * printGrammarLines printa na saida padrão as linhas da gramática do autômato
     * @param nonTerminals lista de símbolos não terminais
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    private void printGrammarLines(LinkedHashMap<String, Character> nonTerminals) {
        int i;

        /// para cada não terminal na lista
        for (Map.Entry<String, Character> nonTerminal : nonTerminals.entrySet()) {
            i = 0;
            /// procura estado e pega suas transições
            String stateName = nonTerminal.getKey();
            Character nonTerminalSymbol = nonTerminal.getValue();
            State state = this.findStateByName(stateName);
            LinkedHashMap<Character, State> transitions = state.getTransitions();

            System.out.print(String.format("%c ->", nonTerminalSymbol));
            /// para cada transição do estado
            for (Map.Entry<Character, State> transition : transitions.entrySet()) {
                Character transitionSymbol = transition.getKey();
                State transitionState = transition.getValue();

                /// printa terminal + não terminal
                System.out.print(String.format(" %c%c ", transitionSymbol, nonTerminals.get(transitionState.getName())));
                if(i++ < transitions.size()-1) {
                    System.out.print("|");
                }
            }
            /// se estado é final
            if(this.isFinalState(stateName)) {
                /// printa palavra vazia
                System.out.print("| @");
            }
            System.out.println();
        }
    }

}
