#include<stdio.h>
#include<stdlib.h>
#include "arvorebmais.h"
#define TAM 300

void menuopcoes(){

    printf("\n"
           "                       -- BIBLIOTECA -- \n\n"
           "                  [1] Inserir novo Livro\n"
           "                  [2] Imprimir arvore B+\n"
           "                  [3] Imprimir todo o acervo\n"
           "                  [4] Buscar livro\n"
           "                  [5] Atualizar Numero exemplares\n"
           "                  [6] Remover livro\n"
           "                  [0] Sair\n\n");
    printf("                  Digite a opcao desejada: ");

}
int main(int argc, const char *argv[]){

    int choice, procurado; char *nome_arq, linha_arq[TAM];
    FILE *dados, *arvore_bin, *biblioteca_bin;

    nome_arq=lerNome(argv+1);

    dados=fopen(nome_arq, "r+");

    arvore_bin=fopen("Arvore.bin", "wb+");
    biblioteca_bin=fopen("Biblioteca.bin", "wb+");

    criaCabArv(arvore_bin);
    criaCabBib(biblioteca_bin);
	if(dados==NULL) {
		printf("Arquivo vazio\n");
	}else{

        while(!feof(dados)){

			fgets(linha_arq, TAM, dados);

			lerArquivo(biblioteca_bin, arvore_bin, linha_arq);
       }

       menuopcoes();
       scanf("%d", &choice);
       system("clear");

       while(choice!=0){

           switch(choice){

               case 1:

                   leituraConsole(arvore_bin, biblioteca_bin);
                   //system("pause");
                   system("clear");


               break;

               case 2:

//                    imprimeArv(arvore_bin);
//                    printf("\n");
//                    //system("pause");
//                    system("clear");

                   printaArvore(arvore_bin);
                   //system("pause");
                   system("clear");

               break;

               case 3:

                   imprimeRegistro(arvore_bin, biblioteca_bin);
                   //system("pause");
                   system("clear");


               break;

               case 4:

//                    procurado=escanear();
//                    buscar_livro(arvore_bin, biblioteca_bin, procurado);
//                    //system("pause");
//                    system("clear");

               break;

               case 5:

//                    procurado=escanear();
//                    atualizaQuant(biblioteca_bin, arvore_bin, procurado);
//                    printf("A quantidade de exemplares foi atualizada\n");
//                    //system("pause");
//                    system("clear");

               break;

               case 6:

//                    remover(arvore_bin, biblioteca_bin);
//                    printf("Removido com sucesso\n");
//                    //system("pause");
//                    system("clear");
               break;

               default:
                   printf("Opcao inexistente\n");
               break;
           }

           menuopcoes();
           scanf("%d", &choice);

           system("clear");


       }

   }

   //system("pause");
   system("clear");


    fclose(dados);
    fclose(biblioteca_bin);
    fclose(arvore_bin);


    return 0;
}
