package com.jedson.afd;

import java.util.Scanner;

public class Main {

    enum MenuChoices {
        TestSequence,
        PrintGrammar,
        Exit
    };

    public static void main(String[] args) {
        MenuChoices choice;
        Automata automata = new Automata();


        if(args.length >= 1) {
            System.out.println(String.format("FileName = %s", args[0]));
            FileScanner.initializeAutomata(automata, args[0]);
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

        System.out.println("Exiting program...");
    }

    private static String readSequence() {
        Scanner scanner = new Scanner(System.in);
        return scanner.next();
    }


    private static MenuChoices menu() {
        Scanner scanner = new Scanner(System.in);
        Integer input;

        System.out.println("(1) -> Test Sequence on AFD");
        System.out.println("(2) -> Show grammar of AFD");
        System.out.println("(3) -> Exit");

        input = scanner.nextInt();
        while(true) {
            switch (input) {
                case 1:
                    return MenuChoices.TestSequence;
                case 2:
                    return MenuChoices.PrintGrammar;
                case 3:
                    return MenuChoices.Exit;
                default:
                    System.out.println("Type in a valid command!");
                    input = scanner.nextInt();
            }
        }
    }

}
