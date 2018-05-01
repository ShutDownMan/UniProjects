#include <stdio.h>

int main() {

    int voto, totv = 0, jose = 0, maria = 0, joao = 0, nulo = 0, branco = 0;

    printf("**ELEICOES**\n\n");
    printf("Jose = 1111\nMaria = 2222\nJoao = 3333\nbranco = 0000\nnulo (qualquer outro numero)\n-1 para sair\n\n");

    printf("Digite o numero do seu candidato: ");
    scanf("%d", &voto);
    while(voto != -1) {

        if (voto == 1111)
            jose++;
        else
        	if (voto == 2222)
            	maria++;
	        else
	        	if (voto == 3333)
	            	joao++;
		        else
		        	if (voto == 0000)
		            	branco++;
		            else
		            	nulo++;

        printf("Digite o numero do seu candidato: ");
        scanf("%d", &voto);
    }

    totv = jose + maria + joao + branco + nulo;

    printf("\n");
    printf("Jose teve %d votos\n", jose);
    printf("Maria teve %d votos\n", maria);
    printf("Joao teve %d votos\n", joao);
    printf("Houve %d votos em branco\n", branco);
    printf("Houve %d votos nulos\n", nulo);

    return 0;
}