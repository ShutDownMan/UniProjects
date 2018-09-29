import java.util.Random;

class Jogo {
    private Random rand = new Random();

    void jogar() {
        int pontos = 0;
        Status status;

        int soma = lancarDados();

        switch (soma) {
            case 7:
            case 11:
                status = Status.WON;
                break;
            case 2:
            case 3:
            case 12:
                status = Status.LOST;
                break;
            default:
                pontos = soma;
                status = Status.CONTINUE;
                break;
        }

        while(status == Status.CONTINUE) {
            soma = lancarDados();

            if(soma == pontos) {
                status = Status.WON;
            }
            if(soma == 7) {
                status = Status.LOST;
            }
        }

        if(status == Status.WON) {
            System.out.print("Jogador Ganhou!\n");
        } else {
            System.out.print("Casa Ganhou!\n");
        }
    }


    private int lancarDados() {
        int d1 = rand.nextInt(6) + 1;
        int d2 = rand.nextInt(6) + 1;
        int soma = d1 + d2;

        System.out.printf("Jogada %d + %d = %d\n", d1, d2, soma);

        return soma;
    }
}
