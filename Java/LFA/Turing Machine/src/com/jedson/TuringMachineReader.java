package com.jedson;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

class TuringMachineReader {
    private Scanner turingMachineFile;
    private TuringMachine turingMachine;

    /**
     * construtor da classe
     * @param fileName nome do arquivo onde se encontra as especificações da máquina
     */
    TuringMachineReader(String fileName) {
        Path filePath = Paths.get(fileName);

        /// tenta abrir o arquivo
        try {
            this.turingMachineFile = new Scanner(filePath);
        } catch (Exception e) {
            /// printa erro
            System.out.println(String.format("Erro na abertura do arquivo (%s);", fileName));
        }

        this.turingMachine = new TuringMachine();
    }

    /**
     * inicializa a máquina de turing a partir do arquivo passado no construtor
     *
     * @return máquina de turing lida
     * @pre-condition arquivo de entrada tem que estar aberto
     * @post-condition maquina de turing é criada e retornada
     */
    TuringMachine initializeTuringMachine() {
        /// discarta a primeira linha
        this.turingMachineFile.nextLine();

        /// lê estados finais do arquivo
        this.readFinalStates(this.turingMachineFile.nextLine());

        /// lê alfabeto do arquivo
        this.turingMachine.addSymbolToAlphabet('*');
        this.turingMachine.addSymbolToAlphabet('$');
        this.readAlphabet(this.turingMachineFile.nextLine());

        /// lê transições do arquivo
        while(this.turingMachineFile.hasNextLine()) {
            this.readTransitions(this.turingMachineFile.nextLine());
        }

        /// incializa estado inicial
        this.turingMachine.setInitialState();

        /// retorna maquina de turing inicializada
        return this.turingMachine;
    }

    /**
     * lê estados finais da linha passada
     *
     * @param line linha a ser tirado os estados finais
     * @pre-condition formato da linha tem que ser "F={<estados>}"
     * @post-condition estados são lidos e marcados como finais
     */
    private void readFinalStates(String line) {
        String[] stateNames;

        /// pega substring entre "{}" e divide pelas virgulas
        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        stateNames = line.split(",");

        /// para cada string em stateNames
        for (int i = 0; i < stateNames.length; i++) {
            /// limpa string e adiciona a máquina
            stateNames[i] = stateNames[i].trim();
            this.turingMachine.setFinalState(stateNames[i]);
            System.out.println(String.format("State [%s] has been added!", stateNames[i]));
        }
    }

    /**
     * lê alfabeto a partir da linha passada
     *
     * @param line linha a ser tirado os simbolos
     * @pre-condition formato da linha tem que ser "A={<simbolos>}"
     * @post-condition simbolos são lidos e armazenados em uma lista na maquina
     */
    private void readAlphabet(String line) {
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
                this.turingMachine.addSymbolToAlphabet(symbols[i].charAt(0));
                System.out.println(String.format("Symbol '%c' has been added!", symbols[i].charAt(0)));
            } else {
                /// simbolo inválido
                System.out.println(String.format("Symbol [%s] is Invalid!", symbols[i]));
            }
        }
    }

    /**
     * lê transição a partir da linha passada
     *
     * @param line linha a ser tirada as informações da transição
     * @pre-condition linha tem que estar no formato (qi, SL)=(qf, SE, D)
     * @post-condition transição é adicionada a máquina
     */
    private void readTransitions(String line) {
        String part1, part2;
        String stateNameFrom, stateNameTo;
        Character readSymbol, writeSymbol, moveDirectionChar;
        int moveDirection = 0;


        /// lê proxima linha
        part1 = line.split("=")[0];
        part1 = part1.substring(part1.indexOf('(')+1, part1.indexOf(')'));
        part2 = line.split("=")[1];
        part2 = part2.substring(part2.indexOf('(')+1, part2.indexOf(')'));

        /// lê estado de partida e simbolo de leitura
        stateNameFrom = part1.split(",")[0].trim();
        readSymbol = part1.split(",")[1].trim().charAt(0);

        /// lê estado de chegada, simbolo de escrita e direção de movimento
        stateNameTo = part2.split(",")[0].trim();
        writeSymbol = part2.split(",")[1].trim().charAt(0);
        moveDirectionChar = part2.split(",")[2].trim().charAt(0);

        if(moveDirectionChar == 'D') moveDirection = 1;
        if(moveDirectionChar == 'E') moveDirection = -1;

        /// adiciona transição do estado de saída ao estado de chegada usando simbolo
        this.turingMachine.addTransition(stateNameFrom, readSymbol, stateNameTo, writeSymbol, moveDirection);
        System.out.printf("Adding the transition [%s, %c, %s, %c, %d]!\n", stateNameFrom, readSymbol, stateNameTo, writeSymbol, moveDirection);
    }
}
