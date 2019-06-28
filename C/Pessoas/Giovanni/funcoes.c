#include "header2.h"


void entra_palavra(char *palavra){
    fflush(stdin);
    gets(palavra);
}

void limpa_str(){
	int i,j;
	//limpa os dados da struct para que possa ser usada novamente.
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			trans[i][j].comple = 0;
			//Etrans[i][j] = 20;
		}
	}
}

void carrega_arquivo(char *nome){
	char aux, car;
	int i=0, k, pos_1, pos_2, pos_3 , teste, coluna = 0, index;
	FILE *arquivo;

    //anula_matrizfecho();
	//Testa se ha conteudo dentro do arquivo.
	if((arquivo = fopen(nome, "r")) == NULL) {
		printf("   Erro ao abrir o arquivo");
	}


	else{

		//Le o alfabeto

		fscanf(arquivo, "alfabeto={%c", &aux);


		while(aux!='}'){


			if(aux!=',') {
				alfabeto[i] = aux;
				i++;
			}

			fscanf(arquivo, "%c", &aux);

		}

		fscanf(arquivo, "\n");

		//Le os estados do automato;

		fscanf(arquivo, "estados={q%d", &estados[0]);


		num_estados=1;


		fscanf(arquivo,"%c", &aux);

		while(aux!='}'){

			fscanf(arquivo, "q");
			fscanf(arquivo, "%d", &estados[num_estados]);
			fscanf(arquivo, "%c", &aux);
			num_estados++;
		}

		//Le o estado inicial.

		fscanf(arquivo, "\ninicial=q%d", &inicial);

		//Le os estados finais.

		fscanf(arquivo, "\nfinais={q%d", &finais[0]);

		num_finais = 1;

		fscanf(arquivo, "%c", &aux);

		while(aux!='}'){

		fscanf(arquivo, "q");
		fscanf(arquivo, "%d", &finais[num_finais]);
		fscanf(arquivo, "%c", &aux);
		num_finais++;


		}

		limpa_str();

		teste = 1;

		fscanf(arquivo , "\n");
		//Le as transicoes do automato.
		limpa_Etrans(Etrans);
		while(fgetc(arquivo) != EOF){
			fscanf(arquivo, "q%d , %c ) = q%d%c", &pos_1, &car, &pos_2, &virgula);
            if(pos_1 == 0) Etrans[0][pos_2] = pos_1;

			if(virgula == ','){
                Etrans[pos_1][pos_2] = pos_2;
                k = trans[pos_1][pos_2].comple;
                trans[pos_1][pos_2].estados[k] = car;
               		while(virgula != '\n'){
                        fscanf(arquivo, "q");
                        fscanf(arquivo, "%d", &pos_3);
                        fscanf(arquivo, "%c", &virgula);
                        Etrans[pos_1][pos_2+1] = pos_3;
                        index++;
               		}
            fscanf(arquivo, "\n");

            }else{
	            Etrans[pos_1][pos_2] = pos_2;
				k = trans[pos_1][pos_2].comple;
				trans[pos_1][pos_2].estados[k] = car;//transicao do estado
				k++;
				trans[pos_1][pos_2].comple = k;
				numtrans[pos_1]++;
				teste++;
				fscanf(arquivo,"\n");
			}
		}

		printf("   ARQUIVO CARREGADO COM SUCESSO\n");

	}

	fclose(arquivo);
}


int testa_palavra(char *palavra){
	int j = 0, teste;

	//Testa simbolo por simbola da palavra pra ver se a mesma existe no alfabeto.
    int i = 0;
	while(palavra[i]){
		teste = 0;
        j = 0;
		while(alfabeto[j]){
			if (palavra[i] == alfabeto[j]) teste++;
			j++;
		}

        i++;
		if(!teste && palavra[i] != '@') return 1;

	}

	return 0;

}

void processa_palavra(char *palavra){
	int atual, i, j, k, teste;
	char car;

	printf("   [q%d]%s\n", inicial, palavra);


	atual = inicial;

	//Repeticao para testar simbolo por simbolo da palavra.

	for (i=0; i<tam_palavra; i++){

		teste = 0;

		//Busca e compara as transicoes achando o proximo estado.

		for(j=0; j<10; j++){
			car = '\0';
			for(k=0; k<(trans[atual][j].comple); k++){
				if(trans[atual][j].estados[k] == palavra[i]){
					atual = j;
					car = palavra[i];
					teste = 1;
					break;
				}
			}
			if(car == palavra[i]) break;
		}

		//Caso nao possua transicao que leia o simbolo, a palavra e dada como invalida

		if (teste != 1 ) {
			printf("   PALAVRA NAO ACEITA");
			break;
		}

		printf("   [q%d]%s", atual, palavra+(i+1));

		teste = 0;

		printf("\n");


		//No caso de ser a ultima transicao, avalia se e um estado final

		if(i == tam_palavra-1){
			for(j = 0; j<num_finais; j++){
				if (atual == finais[j]) teste = 1;
			}

			if(teste == 1) printf("   PALAVRA ACEITA\n");
				else printf("   PALAVRA NAO ACEITA\n");
		}

	}

}
void limpa_Etrans(int mat[][15]) {
       int i,j;

        for(i=0;i<10;i++){
            for(j=0;j<10;j++){

            Etrans[i][j] = -1;
        }
    }

}

void print_Etrans(){
    int i, j, aux;


        for(i = 0; i < 10; ++i){ // Estado atual
        	aux = 0;
        	for(j = 0; j < 10; ++j) {
        		if(!aux) {
	        		if(Etrans[i][j] >= 0) {
	        			printf("(q%d, %c) = q%d", i, trans[i][j].estados[0], j);
	        			aux = 1;
	        		}
        		} else {
	        		if(Etrans[i][j] >= 0) {
	        			printf(",q%d", j);
	        		}
        		}
        	}
            printf("\n");
        }
}

void menu(){
    int process = 1, resposta=1, openarq = 0;
	char palavra[50], nome_arq[50];


	while(process){

		system("cls");

		printf("	    __________________\n");
		printf("	   |                  |\n");
		printf("	   | SIMULADOR DE AFD |	\n");
		printf("	   |__________________|\n\n");

		printf("   |0| -> CARREGAR ARQUIVO DE CONFIGURACAO\n");
		printf("   |1| -> PROCESSAMENTO DA PALAVRA DO AFD\n");
		printf("   |2| -> TRANSFORMAR AF@ P/ AFD\n");

		printf("   |3| -> SAIR\n");

		printf("   RESPOSTA = ");

		scanf("%d", &resposta);


		system("cls");



		switch (resposta){
			case 0:
				limpa_str();
				printf("\n  Entre com o nome do arquivo: ");
                entra_palavra(nome_arq);
				printf("\n");

				carrega_arquivo(nome_arq);
				openarq = 1;
				scanf("%*c");

				break;


			case 1:
				printf("\n   Entre com a palavra: ");
                    entra_palavra(palavra);

				if (openarq != 1) printf("   ARQUIVO NÃO CARREGADO\n");
                    else if(testa_palavra(palavra)) printf("   PALAVRA NAO ACEITA\n");
				else{
					printf("   PALAVRA CARREGADA\n");
					processa_palavra(palavra);
				}

				printf("\n");

				scanf("%*c");


				break;


			case 2:
				if (openarq != 1) printf("   ARQUIVO NAO CARREGADO\n");
				else //transforma_afe();
				print_Etrans();
				scanf("%*c");
				scanf("%*c");
				break;


			case 3:
				process = 0;
				break;

			default:
				printf("   Opcao Invalida\n");
				scanf("%*c");
				scanf("%*c");
		}

	}
}

