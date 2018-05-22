#define MAXSTR 126

#include "entry.h"
#include "database.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

using namespace std;

void decoyLogin() {
    char c;

    printf("Id de usuario: ");
    scanf("%*[^\n]%*c");
    printf("Senha: ");

    fflush(stdin);
    c = getch();
    while(c != 13) {

        printf("*");
        c = getch();
        fflush(stdin);
    }
    printf("\n");
}

char mainMenu() {
    char c;

    system("CLS");
    printf("(C) -> cria nova cadastro\n");
    printf("(R) -> pesquisa cadastros\n");
    printf("(U) -> edita cadastros\n");
    printf("(D) -> deleta cadastros\n\n");

    printf("Digite um comando: ");

    c = getchar();
    fflush(stdin);
    while(!isalpha(toupper(c))) {
        system("CLS");
        printf("(C) -> cria nova cadastro\n");
        printf("(R) -> pesquisa cadastros\n");
        printf("(U) -> edita cadastros\n");
        printf("(D) -> deleta cadastros\n\n");

        printf("Digite um comando: ");

        c = getchar();
        fflush(stdin);
    }

    return toupper(c);
}

void readAnoId(unsigned int *ano, unsigned int *id) {
    printf("\tDigite o ano do oficio: ");
    scanf("%d", ano);
    printf("\tDigite o id do oficio: ");
    scanf("%d", id);
}

int isValidTipo(unsigned int tipo) {
    return tipo;
}

void readTipoOficio(unsigned int *tipo, string **desc) {
    char str[MAXSTR];
    printf("\n\tDigite o tipo do oficio: ");
    scanf("%d", tipo);

    if(!(*tipo)) {
        fflush(stdin);
        printf("\t\tDigite o descricao do oficio: ");
        scanf("%[^\n]%*c", str);
        *desc = new string(str);
        return;
    }

    while(!isValidTipo(*tipo)) {
        delete *desc;
        *desc = NULL;

        printf("\n\tTipo invalido...\n");
        printf("\t(Tipo 0) -> outros\n");
        printf("\tDigite novamente um tipo do oficio: ");
        scanf("%d", tipo);

        if(!(*tipo)) {
            fflush(stdin);
            printf("\t\tDigite novamente a descricao do oficio: ");
            scanf("%[^\n]%*c", str);
            *desc = new string(str);
            return;
        }
    }
}

int isValidSetor(unsigned int setor) {
    return 1;
}

void readSetor(unsigned int *setor) {
    printf("\t\tDigite um setor: ");
    scanf("%d", setor);

    while(!isValidSetor(*setor)) {
        printf("\t\tSetor invalido...\n");
        printf("\t\t(Setor 0) -> cancela.\n");
        printf("\t\tDigite novamente um setor: ");
        scanf("%d", setor);
    }
}

void readSetoresDestinatarios(unsigned int setorDestIds[], int *qnt) {
    unsigned int setor = 0;

    readSetor(&setor);

    if(setor) {
        setorDestIds[(*qnt)++] = setor;
    }

    while(setor) {
        readSetor(&setor);

        if(setor) {
            setorDestIds[(*qnt)++] = setor;
        }
    }
}

int isValidPath(string *path) {
    return 1;
}

void readImagesDirectoryPath(string **path) {
    char str[MAXSTR];

    printf("\t\tDigite o caminho para pasta de imagens: ");
    scanf("%[^\n]%*c", str);

    *path = new string(str);

    while(!isValidPath(*path)) {
        printf("\t\tCaminho invalido...\n");
        printf("\t\t(0) -> cancela.\n");
        printf("\t\tDigite novamente um caminho: ");
        scanf("%[^\n]%*c", str);
    }
}

char readSimNao() {
    char c;

    fflush(stdin);
    c = getch();
    printf("%c", c);
    while(toupper(c) != 'S' && toupper(c) != 'N') {
        printf("Digite s ou n: ");
        fflush(stdin);
        c = getch();
    }

    printf("\n");

    return toupper(c);
}

void createEntry(Database *table) {
    Entry *entry = new Entry();
    Entry *tracer = NULL;
    unsigned int ano, id;
    char choice;

    system("CLS");

    printf("Oficio atual:\n");
    // ler ano e id do oficio atual
    readAnoId(&entry->ano, &entry->id);

    // ler tipo do oficio
    readTipoOficio(&entry->tipoId, &entry->tipoDesc);

    printf("\n\tSetor remetente:\n");
    // ler setor remetente
    readSetor(&entry->setorRmtntId);

    printf("\n\tDigite um setor destinatario: \n");
    // ler setores destinatários
    readSetoresDestinatarios(entry->setorDestIds, &entry->setorDestIdQnt);

    // add image path
    //readImagesDirectoryPath(&entry->imagesPath);

    // ler ano e id do oficio anterior, se é oficio resposta
    printf("\nOficio resposta?: \n");
    choice = readSimNao();
    if(choice == 'S') {
        printf("\nOficio anterior:\n");
        readAnoId(&ano, &id);
        entry->ant = table->search(ano, id);
        if(entry->ant)
            entry->ant->resposta = entry;
    }

    // se oficio esta pendente
    printf("\nOficio pendente?: \n");
    choice = readSimNao();
    if(choice == 'S') {
        entry->pendente = 1;
    } else {
        for(tracer = entry->ant; tracer; tracer = tracer->ant) {
            tracer->pendente = 0;
        }
    }

    table->saveEntry(entry);

    system("CLS");
    for(tracer = entry; tracer && tracer->ant; tracer = tracer->ant)
        ;
    for(tracer = entry; tracer; tracer = tracer->resposta) {
        tracer->show();
        printf("--------------\n");
    }

    getch();
}

void searchEntry(Database *table) {
    Entry *foundEntry = NULL;
    unsigned int ano, id;

    system("CLS");
    printf("Pesquisa de oficio: \n");
    // ler ano e id do oficio
    readAnoId(&ano, &id);

    foundEntry = table->search(ano, id);

    system("CLS");
    if(foundEntry) {
        printf("\n\n");
        foundEntry->show();
    } else {
        printf("Nao foi possivel encontrar cadastro.\n");
    }

    getch();
}

void listPendentes(Database *table) {
    Entry *entry = NULL;
    int i = 0;
    system("CLS");

    for(i = 0; i < table->entryQnt; ++i) {
        if(table->entry[i]->pendente) {
            table->entry[i]->show();

            printf("--------------\n");
        }
    }
    getch();
}

int main(void) {
    Database *table = new Database();
    char c = 0;

    setlocale(LC_ALL, "Portuguese");

    decoyLogin();

    while((c = mainMenu())) {
        switch(c) {
        case 'C':
            createEntry(table);
            break;
        case 'R':
            searchEntry(table);
            break;
        case 'U':
//            updateEntry();
            break;
        case 'D':
//            deleteEntry();
            break;
        case 'P':
            listPendentes(table);
            break;
        default:
            return 0;
        }
    }

    return 0;
}
