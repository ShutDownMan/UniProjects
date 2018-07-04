package com.jedson.afd;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class FileScanner {

    public static void initializeAutomata(Automata automata, String fileName) {
        Path filePath = Paths.get(fileName);
        Scanner fileScanner = null;

        try{
            fileScanner = new Scanner(filePath);
        } catch (Exception e){
            System.out.println(String.format("Erro na abertura do arquivo (%s);", fileName));
        }

        if(fileScanner != null) {
            // TODO: Ler alfabeto
            readAlphabet(automata, fileScanner);

            // TODO: Ler estados
            readStates(automata, fileScanner);

            // TODO: Colocar atributos dos estados
            readInitialState(automata, fileScanner);
            readFinalStates(automata, fileScanner);

            // TODO: Atribuir transições
            readTransitions(automata, fileScanner);

            fileScanner.close();
        }

    }

    private static void readAlphabet(Automata automata, Scanner fileScanner) {

    }

    private static void readStates(Automata automata, Scanner fileScanner) {

    }

    private static void readInitialState(Automata automata, Scanner fileScanner) {

    }

    private static void readFinalStates(Automata automata, Scanner fileScanner) {

    }

    private static void readTransitions(Automata automata, Scanner fileScanner) {

    }
}
