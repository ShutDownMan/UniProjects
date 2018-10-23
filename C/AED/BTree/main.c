#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSTR 256

#include "Menus.h"

int main() {
    int choice = 1;

    FILE *treeFile = fopen("btree.bin", "wb+");
    FILE *regFile = fopen("data.bin", "wb+");

    initializeFiles(treeFile, regFile);
//    getch();

    do {
        system("CLS");
        printf("[1] - Carregar arquivos de inicializacao\n");
        printf("[2] - Inserir Medico\n");
        printf("[3] - Alterar Medico\n");
        printf("[4] - Buscar dados de Medico\n");
        printf("[5] - Remover Medico\n");
        printf("[6] - Imprimir Cadastro\n");
        printf("[7] - Imprimir a Arvore-B\n");
        printf("[0] - Fechar\n");
        printf("    Opcao: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadFileMenu(treeFile, regFile);
                break;
            case 2:
                readRegFromConsole(treeFile, regFile);
                break;
            case 3:
                // WIP
                break;
            case 4:
                searchEntry(treeFile, regFile);
                break;
            case 5:
                // WIP
            case 6:
                printRegister(treeFile, regFile);
                break;
            case 7:
                printBTree(treeFile);
                break;
            default:
                break;
        }

        getch();

    } while (choice);

    return 0;
}