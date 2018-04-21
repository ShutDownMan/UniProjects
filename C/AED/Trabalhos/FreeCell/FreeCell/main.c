#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "freecell.h"

int main(void) {
    Table *table = createTable();

    srand(time(NULL));

    startGame(table);

    printTable(table);

    inputCmd(table);

    return 0;
}

// MAIN FUNCTIONS //

Table *createTable() {
    int i;
    Table *newTable = (Table*)malloc(sizeof(Table));

    for(i = 0; i < 4; ++i) {
        newTable->tableau[i] = NULL;
        newTable->tableau[i+4] = NULL;
        newTable->homeCells[i] = NULL;
        newTable->freeCells[i] = NULL;
    }

    return newTable;
}

void startGame(Table *table) {
    int i;
    Card *deck[MAXCARDS] = {NULL};

    createDeck(deck);

    shuffleCards(deck);

    for(i = 0; i < MAXCARDS; ++i) {
        table->tableau[i%8] = insertCard(table->tableau[i%8], deck[i]);
    }
}

void createDeck(Card *deck[]) {
    int suitInd, rankNum;

    for(suitInd = 0; suitInd < 4; ++suitInd) {
        for(rankNum = 0; rankNum < 13; ++rankNum) {
            deck[suitInd*13 + rankNum] = createCard(suitInd, rankNum);
        }
    }
}

Card *createCard(int suitInd, int rankInd) {
    Card *newCard = (Card*)malloc(sizeof(Card));

    newCard->suit = suits[suitInd];
    newCard->rank = ranks[rankInd];

    return newCard;
}

void shuffleCards(Card* deck[]) {
    int i, ind;
    Heap *rndHeap = NULL, *tableau[16] = {NULL};
    Node **tracer, **aux;

    for(i = 0; i < 52; ++i) {
        ind = rand() % 16;
        tableau[ind] = insertCard(tableau[ind], deck[i]);
    }

    for(i = 0; i < 16; ++i) {
        if(tableau[i]) {
            rndHeap = concatHeap(rndHeap, tableau[i]);
        }
    }

    tracer = &rndHeap->start;
    for(i = 0; *tracer; ++i) {
        deck[i] = (*tracer)->card;
        aux = tracer;
        tracer = &(*tracer)->next;
        free(aux);
    }
}

void printTable(Table *table) {
    int i;
    int lines;
    char suit, rank;
    Node *current[8] = {NULL}, *reverseHeaps[8] = {NULL};

    printf("    ");
    for(i = 0; i < 4; ++i) {
        if(table->freeCells[i]) {
            suit = table->freeCells[i]->suit;
            rank = table->freeCells[i]->rank;
        } else {
            suit = rank = ' ';
        }

        printf("[%c,%c] ", suit, rank);
    }

    printf("\t");

    for(i = 0; i < 4; ++i) {
        if(table->homeCells[i] && table->homeCells[i]->end) {
            suit = table->homeCells[i]->end->card->suit;
            rank = table->homeCells[i]->end->card->rank;
        } else {
            suit = rank = ' ';
        }

        printf("[%c,%c] ", suit, rank);
    }

    printf("\n");


    for(i = lines = 0; i < 8; ++i) {
        if(table->tableau[i]) {
            if(table->tableau[i]->length > lines) {
                lines = table->tableau[i]->length;
            }
            reverseHeaps[i] = reverseHeap(table->tableau[i]->start);
            current[i] = reverseHeaps[i];
        }
    }

    while(lines) {
        printf("%2d    ", lines--);
        for(i = 0; i < 8; ++i) {
            if(current[i]) {
                suit = current[i]->card->suit;
                rank = current[i]->card->rank;
                current[i] = current[i]->next;
                printf("[%c,%c] ", suit, rank);
            } else {
                printf("      ");
            }
        }
        printf("\n");
    }

    for(i = 0; i < 8; freeList(reverseHeaps[i++]))
        ;
}

void freeList(Node *node) {
    if(!node) return;

    freeList(node->next);
    free(node);
}

// Send to free cells: ^A
// Retrieve from free cells: vA > A
// Move to home cells: *A
// Move col to col: A1 > B
void inputCmd(Table *table) {
    char cmd[MAXSTR], cmdType;

    printf("\nDigite um comando: ");
    readLine(cmd);
    while(!(cmdType = getCmdType(cmd))) {

        printf("(?) -> Ajuda.\n");
        printf("\nDigite um comando v%clido: ", 160);
        readLine(cmd);
    }

    printf("Td certim.\n");

    switch(cmdType) {

    }

    // execute command...
}

void readLine(char str[]) {
    scanf("%[^\n]%*c", str);
}

int getCmdType(char cmd[]) {
    int i = 0;

    if(!cmd[i]) return 0;

    if(cmd[i] == '?') return -1;

    for(i = 0; cmd[i++]; cmd[i] = toupper(cmd[i]))
        ;

    i = 0;
    if(cmd[i] == '^') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H') * 2;
    }

    if(cmd[i] == '*') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H') * 3;
    }

    if(cmd[i] == 'v') {
        i++;
        if(!cmd[i]) return 0;

        if(cmd[i] >= 'A' && cmd[i] <= 'D') {
            i++;
            for(; cmd[i] == ' '; i++)
                ;
            if(cmd[i++] == '>') {
                for(; cmd[i] == ' '; i++)
                    ;
                return (cmd[i] >= 'A' && cmd[i] <= 'H') * 3;
            }
        }
    }

    if(cmd[i] >= 'A' && cmd[i] <= 'H') {
        i++;
        if(!cmd[i]) return 0;

        if(cmd[i] >= 'A' && cmd[i] <= 'H') {
            i++;
            for(; cmd[i] == ' '; i++)
                ;
            if(cmd[i++] == '>') {
                for(; cmd[i] == ' '; i++)
                    ;
                return (cmd[i] >= 'A' && cmd[i] <= 'H') * 4;
            }
        }
    }

    return 0;
}

// HEAP FUNCTIONS //

Heap *createHeap() {
    Heap *newHeap = (Heap*)malloc(sizeof(Heap));

    newHeap->length = 0;
    newHeap->start = NULL;
    newHeap->end = NULL;

    return newHeap;
}

Heap *insertCard(Heap *heap, Card *card) {
    Node *aux;

    if(!card) return heap;

    if(!heap) {
        Heap *newHeap = createHeap();
        newHeap->length++;
        newHeap->start = createNode(card);
        newHeap->end = newHeap->start;
        return newHeap;
    }

    aux = heap->start;
    heap->start = createNode(card);
    heap->start->next = aux;
    heap->length++;

    return heap;
}

Heap *concatHeap(Heap *heap1, Heap *heap2) {
    if(!heap1) {
        heap1 = createHeap();
    }

    if(heap2) {
        if(!heap1->start) {
            heap1->start = heap2->start;
            heap1->end = heap2->end;
        } else {
            heap1->end->next = heap2->start;
            heap1->end = heap2->end;
        }

        heap1->length += heap2->length;

        heap2->start = NULL;
        heap2->end = NULL;
        heap2->length = 0;
    }

    return heap1;
}

Node *reverseHeap(Node *node) {
    if(!node) return NULL;

    return insertNodeOnTail(reverseHeap(node->next), node->card);
}

Node *insertNodeOnTail(Node *list, Card *card) {
    if(!list) return createNode(card);
    list->next = insertNodeOnTail(list->next, card);
    return list;
}

Node *createNode(Card *card) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->card = card;
    newNode->next = NULL;

    return newNode;
}
