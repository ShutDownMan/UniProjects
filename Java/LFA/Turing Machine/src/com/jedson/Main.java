package com.jedson;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    /**
     * Escolhas do menu principal
     */
    enum MenuChoices {
        TestSequence,
        Exit
    }

    /**
     * função principal
     *
     * @param args argumentos de execução
     * @throws IOException          erro de entrada e saida
     * @throws InterruptedException erro de execução interrompida
     */
    public static void main(String[] args) throws IOException, InterruptedException {
        MenuChoices choice;
        TuringMachineReader TMReader;
        TuringMachine turingMachine;

        command("cls");
        /// se existe mais de um argumento
        if (args.length == 1) {
            /// inicializa autômato com arquivo de nome do segundo argumento
            System.out.println(String.format("FileName = %s", args[0]));
            TMReader = new TuringMachineReader(args[0]);
            turingMachine = TMReader.initializeTuringMachine();
            command("pause");
        } else {
            /// printa erro
            System.out.println("Nenhum arquivo de entrada especificado!");
            command("pause");
            return;
        }

        /// menu principal
        choice = menu();
        while (choice != MenuChoices.Exit) {
            command("cls");

            /// testa palavra passada pelo usuário
            System.out.print("Type in the sequence to be tested: ");
            String sequence = "*" + readSequence() + "$";
            turingMachine.testSequence(sequence);

            command("pause");
            choice = menu();
        }

        System.out.println("Exiting program...");
    }

    /**
     * readSequence lê sequência da entrada padrão (nem deveria existir)
     *
     * @return sequência lida
     */
    private static String readSequence() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    /**
     * MenuChoices printa na saida padrão as opções do menu principal
     *
     * @return escolha do usuário
     * @throws IOException          erro de entrada e saida
     * @throws InterruptedException erro de execução interrompida
     * @pre-condition nenhuma
     * @post-condition nenhuma
     */
    private static MenuChoices menu() throws IOException, InterruptedException {
        Scanner scanner = new Scanner(System.in);
        Integer input;

        /// opções do menu
        command("cls");
        System.out.println("(1) -> Test Sequence on AFD");
        System.out.println("(2) -> Exit");
        System.out.print("Type in your command: ");

        /// escolha do usuário
        input = scanner.nextInt();
        while (true) {
            switch (input) {
                case 1:
                    return MenuChoices.TestSequence;
                case 2:
                    return MenuChoices.Exit;
                default:
                    System.out.println("Type in a valid command!");
                    input = scanner.nextInt();
                    break;
            }
        }
    }

    /**
     * command executa comando no console
     *
     * @param cmd comando a ser executado
     * @throws IOException          erro de entrada e saida
     * @throws InterruptedException erro de execução interrompida
     * @pre-condition nenhuma
     * @post-condition comando é executado
     */
    private static void command(String cmd) throws IOException, InterruptedException {
        ProcessBuilder processBuilder = new ProcessBuilder("cmd", "/c", cmd).inheritIO();
        processBuilder.start().waitFor();
    }
}
