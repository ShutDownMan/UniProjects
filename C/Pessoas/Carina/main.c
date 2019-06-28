#include "funcao.h"

int main(){
	int resposta = 0;
	char palavra[50];
    Carregar_Arquivo("vazia.txt");

	while(1){
	    printf("          ******************  \n");
		printf("	                        \n");
		printf("	   SIMULADOR DE AFD 	\n");
		printf("	                        \n");
		printf("          ******************  \n\n");

		printf("   |1| -> ENTRAR COM PALAVRA\n");
		printf("   |2| -> CONVERSAO AFe PARA O AFD EQUIVALENTE\n");
		printf("   |3| -> SAIR\n");

		printf("   RESPOSTA = ");
        scanf("%d", &resposta);

    	switch (resposta){
			case 1:
				printf("\n   Entre com a palavra: ");
				fflush(stdin);
				gets(palavra);
    			if(validar_palavra(palavra) == 1) printf("Palavra contem alfabeto invalido!\n\n");
    			else {
        			if(processar_palavra(palavra, EstadoInicial)) {
        				printf("ACEITO\n");
        			} else {
        				printf("REJEITADO\n");
        			}
        			system("pause");
        			main();

    			}

				printf("\n");
                scanf("%*c");
				break;

			case 2:
                break;


			case 3:
				break;

		}		return 0;
	}

}
