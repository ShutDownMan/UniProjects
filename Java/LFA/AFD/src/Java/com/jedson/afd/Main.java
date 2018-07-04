package com.jedson.afd;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Main {

    private Scanner scanner;

    enum MenuChoices {
        TestSequence,
        PrintGrammar,
        Exit
    };

    public static void main(String[] args) {
        MenuChoices choice;
        Automata automata = new Automata();

        if(args.length > 1) {
            FileScanner.initializeAutomata(automata, args[1]);
        }

        choice = menu();
        while(choice != MenuChoices.Exit) {
            switch(choice) {
                case TestSequence:
                    automata.testSequence(readSequence());
                    break;
                case PrintGrammar:
                    automata.printGrammar();
                    break;
            }
            choice = menu();
        }
    }

    private static String readSequence() {
        Scanner scanner = new Scanner(System.in);
        return scanner.next();
    }


    static MenuChoices menu() {
        Scanner scanner = new Scanner(System.in);
        Integer input = scanner.nextInt();

        System.out.println("(1) -> Test Sequence on AFD");
        System.out.println("(2) -> Show grammar of AFD");
        System.out.println("(3) -> Exit");

        while(true) {
            switch (input) {
                case 0:
                    return MenuChoices.TestSequence;
                case 1:
                    return MenuChoices.PrintGrammar;
                default:
                    return MenuChoices.Exit;
            }
        }
    }

}
