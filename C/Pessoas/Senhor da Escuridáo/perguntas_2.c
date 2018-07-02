#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 50

void printaBonito(char str[], int tempo) {
    int i;
    for(i = 0; str[i]; ++i) {
        printf("%c", str[i]);
        Sleep(tempo);
    }
}

char escolhaSN() {
    char choice;

    printf("___digite 's' para sim, 'n' para nao___\n");
    scanf("%c%*c", &choice);
    while(choice != 's' && choice != 'n') {
        system("CLS");
        fflush(stdin);

        printf("___DIGITE 's' PARA SIM, 'n' PARA NAO___\n");
        scanf("%c%*c", &choice);
    }
    fflush(stdin);

    return choice;
}

int main(void) {
    char choice = '\0';
    char nome[MAX];

    system("CLS");

    printf("bem vindo!\n");
    printaBonito("ola humano...qual seu nome ?\n", 75);
    printf("- ");
    scanf("%[^\n]%*c", nome);
    printaBonito("interessante...entao...", 75);
    printaBonito(nome, 175);
    printaBonito("...e isso mesmo?\n", 75);

    choice = escolhaSN();

    if(choice == 'n') {
        printaBonito("Digita o nome certo entao!!!\n", 75);
        printf("- ");
        scanf("%[^\n]%*c", nome);
        printaBonito("Agora vai ser esse msm DESGRACAAAAAAAAAAAAAAAAAAAAAAA...\n", 50);
    }

    printf("- ");
    printaBonito(". . .", 175);

    return 0;
}
