package jedson;

import java.io.IOException;
import java.util.Scanner;

import static jedson.CadastroNovoAluno.matricularNovoAluno;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        matricularNovoAluno();

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
     * cmdCommand executa comando no console
     *
     * @param cmd comando a ser executado
     * @throws IOException          erro de entrada e saida
     * @throws InterruptedException erro de execução interrompida
     * @pre-condition nenhuma
     * @post-condition comando é executado
     */
    public static void cmdCommand(String cmd) throws IOException, InterruptedException {
        ProcessBuilder processBuilder = new ProcessBuilder("cmd", "/c", cmd).inheritIO();
        processBuilder.start().waitFor();
    }
}
