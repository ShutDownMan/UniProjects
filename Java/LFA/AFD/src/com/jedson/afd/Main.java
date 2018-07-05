package com.jedson.afd;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    enum MenuChoices {
        TestSequence,
        PrintGrammar,
        Exit
    };

    public static void main(String[] args) throws IOException, InterruptedException {
        MenuChoices choice;
        Automata automata = new Automata();

        command("cls");
        if(args.length >= 1) {
            System.out.println(String.format("FileName = %s", args[0]));
            FileScanner.initializeAutomata(automata, args[0]);
            command("pause");
        }

        command("cls");
        automata.testSequence("ab00cb");
        automata.testSequence("abbac");
        command("pause");

        command("cls");
        automata.printGrammar();
        command("pause");

        choice = menu();
        while(choice != MenuChoices.Exit) {
            command("cls");
            switch(choice) {
                case TestSequence:
                    automata.testSequence(readSequence());
                    break;
                case PrintGrammar:
                    automata.printGrammar();
                    break;
            }
            command("pause");
            choice = menu();
        }

        System.out.println("Exiting program...");
    }

    private static String readSequence() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }


    private static MenuChoices menu() throws IOException, InterruptedException {
        Scanner scanner = new Scanner(System.in);
        Integer input;

        command("cls");
        System.out.println("(1) -> Test Sequence on AFD");
        System.out.println("(2) -> Show grammar of AFD");
        System.out.println("(3) -> Exit");
        System.out.print("Type in your command: ");

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

    private static void command(String cmd) throws IOException, InterruptedException {
        ProcessBuilder processBuilder = new ProcessBuilder("cmd", "/c", cmd).inheritIO();
        processBuilder.start().waitFor();
    }

}
