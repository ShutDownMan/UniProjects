#include "funcao.h"

void Carregar_Arquivo(char Arq[]) {
    char aux; //aux onde palavras que não usaremos para a criação da gramatica serão descartadas
    int tam_alfabeto = 0, num_estados = 0, i = 0;
    FILE *arq;
    num_estadosFinal = 0;

    int n, off;

    arq = fopen(Arq, "r");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo");
    }
    else{

    //leitura do alfabeto
        do{//le tudo ate o { e armazena na variavel que nao será usada
            fscanf(arq, "%c", &aux);
        }while(aux != '{');

        do{
            fscanf(arq, "%c", &alfabeto[tam_alfabeto]); //alfabeto
            fscanf(arq, "%c", &aux);//virgula
            tam_alfabeto++;
        }while(aux != '}');

    //leitura dos estados
        do{//le tudo ate o { e armazena na variavel que nao será usada
            fscanf(arq, "%c", &aux);
        }while(aux != '{');

        do{
            fscanf(arq, "%c", &aux);//q
            fscanf(arq, "%d", &estados[num_estados]);//estado
            fscanf(arq, "%c", &aux);//virgula
            num_estados++;
        }while (aux != '}');

    //leitura do estado inicial
        do{//le tudo ate o = e armazena na variavel que nao será usada
            fscanf(arq, "%c", &aux);//inicial
        }while(aux != '=');

        fscanf(arq, "%c", &aux);//q
        fscanf(arq, "%d", &EstadoInicial);//estado

    //leitura dos estados finais
        do{//le tudo ate o { e armazena na variavel que nao ser� usada
            fscanf(arq, "%c", &aux);
        }while(aux != '{');

        do{
            fscanf(arq, " q%d ", &EstadosFinal[num_estadosFinal]);//estado
            fscanf(arq, " %c", &aux);//virgula
            num_estadosFinal++;
        }while (aux != '}');

        while(!feof(arq)) {
            n = 0, off = 0;
            char line[255] = {0};

            int trans_estadoAtual = -1;
            char trans_simbolo = -1;
            int trans_estadoProx = -1;

            fgets(line, 255, arq);
            if(line[0] == '\n') continue;

            sscanf(line+off, " (q%d ,%n", &trans_estadoAtual, &n);//primeiro estado
            off += n;
            sscanf(line+off, " %c) =%n", &trans_simbolo, &n);//letra do alfabeto
            off += n;

            do {
                n = 0;
                trans_estadoProx = -1;

                sscanf(line+off, " q%d, %n", &trans_estadoProx, &n);//estado para onde a letra lida leva
                off += n;

                if(trans_estadoProx != -1) {
                    transicao[num_transicoes].EstadoAtual = trans_estadoAtual;
                    transicao[num_transicoes].CaracterLido = trans_simbolo;
                    transicao[num_transicoes++].EstadoProx = trans_estadoProx;
                }

            } while(n);
        }

        printf("   ARQUIVO CARREGADO COM SUCESSO\n");
    }

}

int validar_palavra(char palavra[]) {
    int i = 0, j = 0;
    int aux;

    while(palavra[i]!=0) {
        aux = 0;
        j = 0;
        while(alfabeto[j] != 0) {
            if(palavra[i] == alfabeto[j])aux++;
            j++;
        }
        if (aux == 0) return 1;
        i++;
    }

    return 0;
}

int processar_palavra(char palavra[], int estado) {
    char simbolo = palavra[0];

    if(estado == -1) return 0;

    printf("[q%d]%s\n", estado, palavra);

    if(!simbolo && eh_final(estado)) return 1;

    return processar_palavra(palavra+1, prox_estado(estado, palavra[0]));
}

int eh_final(int estado) {
	int i;
	for(i = 0; i < num_estadosFinal; ++i) {
		if(estado == EstadosFinal[i]) {
			return 1;
		}
	}
	return 0;
}

int prox_estado(int estadoAtual, char simbolo) {
	int i;
	for(i = 0; i < num_transicoes; ++i) {
		if(transicao[i].EstadoAtual == estadoAtual && transicao[i].CaracterLido == simbolo) {
			return transicao[i].EstadoProx;
		}
	}

	return -1;
}