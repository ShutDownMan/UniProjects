package com.jedson.afd;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class FileScanner {

    public static boolean initializeAutomata(Automata automata, String fileName) {
        Path filePath = Paths.get(fileName);
        Scanner fileScanner = null;

        try{
            fileScanner = new Scanner(filePath);
        } catch (Exception e){
            System.out.println(String.format("Erro na abertura do arquivo (%s);", fileName));
            return false;
        }

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

        return true;
    }

    private static void readAlphabet(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String[] symbols;

        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        symbols = line.split(",");

        for (int i = 0; i < symbols.length; i++) {
            symbols[i] = symbols[i].trim();
            if(symbols[i].length() == 1) {
                automata.addSymbol(symbols[i].charAt(0));
                System.out.println(String.format("Symbol '%c' has been added!", symbols[i].charAt(0)));
            } else {
                System.out.println(String.format("Symbol [%s] is Invalid!", symbols[i]));
            }
        }
    }

    private static void readStates(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String[] stateNames;

        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        stateNames = line.split(",");

        for (int i = 0; i < stateNames.length; i++) {
            stateNames[i] = stateNames[i].trim();
            automata.addState(stateNames[i]);
            System.out.println(String.format("State [%s] has been added!", stateNames[i]));
        }
    }

    private static void readInitialState(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String initialStateName;

        initialStateName = line.substring(line.indexOf('=')+1).trim();

        automata.setInitialState(initialStateName);
        System.out.println(String.format("State [%s] is now initial!", initialStateName));
    }

    private static void readFinalStates(Automata automata, Scanner fileScanner) {
        String line = fileScanner.nextLine();
        String[] stateNames;

        line = line.substring(line.indexOf('{')+1, line.indexOf('}'));
        stateNames = line.split(",");

        for (int i = 0; i < stateNames.length; i++) {
            stateNames[i] = stateNames[i].trim();
            automata.setFinalState(stateNames[i]);
            System.out.println(String.format("State [%s] is now final!", stateNames[i]));
        }
    }

    private static void readTransitions(Automata automata, Scanner fileScanner) {
        String line, stateFromSAndymbol;
        String stateNameFrom, stateNameTo;
        Character symbol;

        while(fileScanner.hasNextLine()) {
            line = fileScanner.nextLine();
            stateFromSAndymbol = line.substring(line.indexOf('(')+1, line.indexOf(')'));


            stateNameFrom = stateFromSAndymbol.split(",")[0].trim();
            symbol = stateFromSAndymbol.split(",")[1].trim().charAt(0);
            stateNameTo = line.substring(line.indexOf('=')+1).trim();

            automata.createTransition(stateNameFrom, symbol, stateNameTo);
            System.out.println(String.format("Transition from [%s], with '%c', to [%s] has been created!", stateNameFrom, symbol, stateNameTo));
        }
    }
}
