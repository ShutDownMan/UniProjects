package com.jedson.afd;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

/**
 * Classe para leitura e inicialização do autômato
 */
public class FileScanner {

    /**
     * initializeAutomata lê arquivo de entrada inicializa automato na memória
     * @param automata automato a ser inicializado
     * @param fileName nome do arquivo
     * @return verdadeiro se automato foi inicializado corretamente
     * @pre-condition autômato tem que estar inicializado
     * @post-condition autômato é inicializado
     */
    public static boolean initializeAutomata(Automata automata, String fileName) {
        Path filePath = Paths.get(fileName);
        Scanner fileScanner;

        /// tenta abrir o arquivo
        try {
            fileScanner = new Scanner(filePath);
        } catch (Exception e) {
            /// printa erro
            System.out.println(String.format("Erro na abertura do arquivo (%s);", fileName));
            return false;
        }

        /// lê alfabeto e adiciona ao autômato
        readAlphabet(automata, fileScanner);

        /// lê estados e adiciona ao autômato
        readStates(automata, fileScanner);

        /// lê estados iniciais e finais e adiciona ao autômato
        readInitialState(automata, fileScanner);
        readFinalStates(automata, fileScanner);

        /// lê transições e adiciona ao autômato
        readTransitions(automata, fileScanner);

        /// fecha arquivo
        fileScanner.close();

        return true;
    }

    /**
     * readAlphabet lê alfabeto do arquivo de entrada e adiciona ao autômato
     * @param automata autômato a ser modificado
     * @param fileScanner arquivo a ser lido
     * @pre-condition autômato tem que estar inicializado e arquivo aberto
     * @post-condition alfabeto é adicionado ao autômato
     */
    private static void readAlphabet(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String[] symbols;

        /// pega substring entre "{}" e divide pelas virgulas
        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        symbols = line.split(",");

        /// para cada string em symbols
        for (int i = 0; i < symbols.length; i++) {
            symbols[i] = symbols[i].trim();
            /// se symbolo contém apenas um caráctere
            if(symbols[i].length() == 1) {
                /// simbolo é adicionado
                automata.addSymbol(symbols[i].charAt(0));
                System.out.println(String.format("Symbol '%c' has been added!", symbols[i].charAt(0)));
            } else {
                /// simbolo inválido
                System.out.println(String.format("Symbol [%s] is Invalid!", symbols[i]));
            }
        }
    }

    /**
     * readStates lê estados do arquivo de entrada e adiciona ao autômato
     * @param automata autômato a ser modificado
     * @param fileScanner arquivo a ser lido
     * @pre-condition autômato tem que estar inicializado e arquivo aberto
     * @post-condition estados são adicionados ao autômato
     */
    private static void readStates(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String[] stateNames;

        /// pega substring entre "{}" e divide pelas virgulas
        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        stateNames = line.split(",");

        /// para cada string em stateNames
        for (int i = 0; i < stateNames.length; i++) {
            /// limpa string e adiciona ao autômato
            stateNames[i] = stateNames[i].trim();
            automata.addState(stateNames[i]);
            System.out.println(String.format("State [%s] has been added!", stateNames[i]));
        }
    }

    /**
     * readInitialState lê estado inicial do arquivo de entrada e atribui ao autômato
     * @param automata autômato a ser modificado
     * @param fileScanner arquivo a ser lido
     * @pre-condition autômato tem que estar inicializado e arquivo aberto
     * @post-condition estado inicial é atribuido ao autômato
     */
    private static void readInitialState(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String initialStateName;

        /// lê nome do estado inicial
        initialStateName = line.substring(line.indexOf('=')+1).trim();

        /// atribui estado lido como inicial
        automata.setInitialState(initialStateName);
        System.out.println(String.format("State [%s] is now initial!", initialStateName));
    }

    /**
     * readFinalStates lê estados finais do arquivo de entrada e adiciona ao autômato
     * @param automata autômato a ser modificado
     * @param fileScanner arquivo a ser lido
     * @pre-condition autômato tem que estar inicializado e arquivo aberto
     * @post-condition estados finais são adicionados ao autômato
     */
    private static void readFinalStates(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String[] stateNames;

        /// pega substring entre "{}" e divide pelas virgulas
        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        stateNames = line.split(",");

        /// para cada string em stateNames
        for (int i = 0; i < stateNames.length; i++) {
            /// limpa string de nome e atribui estado como final
            stateNames[i] = stateNames[i].trim();
            automata.setFinalState(stateNames[i]);
            System.out.println(String.format("State [%s] is now final!", stateNames[i]));
        }
    }

    /**
     * readTransitions lê as transições do arquivo de entrada e adiciona ao autômato
     * @param automata autômato a ser modificado
     * @param fileScanner arquivo a ser lido
     * @pre-condition autômato tem que estar inicializado e arquivo aberto
     * @post-condition transições são adicionadas ao autômato
     */
    private static void readTransitions(Automata automata, Scanner fileScanner) {
        String line, stateFromSAndymbol;
        String stateNameFrom, stateNameTo;
        Character symbol;

        /// enquanto arquivo não estiver acabado
        while(fileScanner.hasNextLine()) {
            /// lê proxima linha
            line = fileScanner.nextLine();
            stateFromSAndymbol = line.substring(line.indexOf('(')+1, line.indexOf(')'));

            /// lê estado de partida, simbolo e estado de chegada
            stateNameFrom = stateFromSAndymbol.split(",")[0].trim();
            symbol = stateFromSAndymbol.split(",")[1].trim().charAt(0);
            stateNameTo = line.substring(line.indexOf('=')+1).trim();

            /// adiciona transição do estado de saída ao estado de chegada usando simbolo
            automata.createTransition(stateNameFrom, symbol, stateNameTo);
            System.out.println(String.format("Transition from [%s], with '%c', to [%s] has been created!", stateNameFrom, symbol, stateNameTo));
        }
    }
}
