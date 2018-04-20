#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "freecell.h"

int main(void) {
    Table *table = createTable();

    srand(time(NULL));

    startGame(table);

    printTable(table);

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

Heap *createHeap() {
    Heap *newHeap = (Heap*)malloc(sizeof(Heap));

    newHeap->start = NULL;
    newHeap->end = NULL;

    return newHeap;
}

void startGame(Table *table) {
    int i, ind;
    Card *deck[52];


    createDeck(deck);

    for(i = 0; i < 52; ++i) {
        ind = rand() % 8;
        table->tableau[ind] = insertCard(table->tableau[ind], deck[i]);
    }

    distributeCards(table->tableau);
}

void createDeck(Card *deck[]) {
    int suitNum, rankNum;

    for(suitNum = 0; suitNum < 4; ++suitNum) {
        for(rankNum = 0; rankNum < 13; ++rankNum) {
            deck[suitNum*13 + rankNum] = createCard(suitNum, rankNum);
        }
    }
}

Card *createCard(int suitInd, int rankInd) {
    Card *newCard = (Card*)malloc(sizeof(Card));

    newCard->suit = suits[suitInd];
    newCard->rank = ranks[rankInd];

    return newCard;
}

void distributeCards(Heap *tableau[]) {
    int i;
    Heap *rndHeap = NULL;
    Node **tracer, **aux;

    for(i = 0; i < 8; ++i) {
        if(tableau[i]) {
            rndHeap = concatHeap(rndHeap, tableau[i]);
        }
    }

    tracer = &rndHeap->start;
    for(i = 0; *tracer; ++i) {
//        printf("[%c,%c]\n", (*tracer)->card->rank, (*tracer)->card->suit);
        insertCard(tableau[i%8], (*tracer)->card);
        aux = tracer;
        tracer = &(*tracer)->next;
        free(aux);
    }
    printf("\n");
}

void printTable(Table *table) {
    int i;
    int finished = 0;
    char suit, rank;
    Node *current[8];

    for(i = 0; i < 4; ++i) {
        if(table->freeCells[i]) {
            suit = table->freeCells[i]->suit;
            rank = table->freeCells[i]->rank;
        } else {
            suit = ' ';
            rank = ' ';
        }

        printf("[%c,%c] ", suit, rank);
    }

    printf("\t");

    for(i = 0; i < 4; ++i) {
        if(table->homeCells[i] && table->homeCells[i]->end) {
            suit = table->homeCells[i]->end->card->suit;
            rank = table->homeCells[i]->end->card->rank;
        } else {
            suit = ' ';
            rank = ' ';
        }

        printf("[%c,%c] ", suit, rank);
    }

    printf("\n");


    for(i = 0; i < 8; ++i) {
        current[i] = table->tableau[i]->start;
    }

    while(!finished) {
        finished = 1;
        printf("    ");
        for(i = 0; i < 8; ++i) {
            if(current[i]) {
                suit = current[i]->card->suit;
                rank = current[i]->card->rank;
                current[i] = current[i]->next;
                finished = 0;
            } else {
                suit = ' ';
                rank = ' ';
            }

            printf("[%c,%c] ", suit, rank);
        }
        printf("\n");

    }

}

// HEAP FUNCTIONS //

Heap *insertCard(Heap *heap, Card *card) {
    Node *aux;

    if(!card) return heap;

    if(!heap) {
        Heap *newHeap = createHeap();
        newHeap->start = createNode(card);
        newHeap->end = newHeap->start;
        return newHeap;
    }

    aux = heap->start;
    heap->start = createNode(card);
    heap->start->next = aux;

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

        heap2->start = NULL;
        heap2->end = NULL;
    }

    return heap1;
}


Node *createNode(Card *card) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->card = card;
    newNode->next = NULL;

    return newNode;
}
