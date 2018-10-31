#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSTR 256

#include "Menus.h"

int main() {
    int choice;

    /// abre arquivos binários para escrita
    FILE *treeFile = fopen("btree.bin", "wb+");
    FILE *regFile = fopen("data.bin", "wb+");

    /// inicializa arquivos
    initializeFiles(treeFile, regFile);

    /// main menu
    do {
        system("CLS");
        printf("[1]Carregar arquivos de inicializacao\n");
        printf("[2]Inserir Medico\n");
        printf("[3]Alterar Medico\n");''
        printf("[4]Buscar dados de Medico\n");
        printf("[5]Remover Medico\n");
        printf("[6]Imprimir Cadastro\n");
        printf("[7]Imprimir a Arvore-B\n");
        printf("[0]Fechar\n");
        printf("---> Opcao: ");

        scanf("%d", &choice);

        /// escolha do usuário
        switch (choice) {
            case 0:
                break;
            case 1:
                /// carrega arquivo de texto para os arquivos binários
                loadFileMenu(treeFile, regFile);
                break;
            case 2:
                /// lê novo registro do console
                readRegFromConsole(treeFile, regFile);
                break;
            case 3:
                /// altera informações de registro
                modifyEntry(treeFile, regFile);
                break;
            case 4:
                /// pesquisa por registro
                searchEntry(treeFile, regFile);
                break;
            case 5:
                // WIP
            case 6:
                /// printa no console todos registros em ordem crescente de código
                printRegister(treeFile, regFile);
                break;
            case 7:
                /// printa árvore correspondente do arquivo binário por nível
                printBTree(treeFile);
                break;
            default:
                printf("Escolha invalida");
                break;
        }

        getch();

    } while (choice);

    return 0;
}