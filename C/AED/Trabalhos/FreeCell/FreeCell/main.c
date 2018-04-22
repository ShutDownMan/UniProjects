#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

#include "freecell.h"

int main(void) {
    Table *table = createTable();

    srand(time(NULL));

    startGame(table);

    printTable(table);
    while(1) {
        inputCmd(table);

        printTable(table);
    }

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

    newTable->freeCellsQnt = 4;

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

    newCard->suit = suitInd;
    newCard->rank = rankInd;

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
    unsigned char suit, rank;
    Node *current[8] = {NULL}, *reverseHeaps[8] = {NULL};

    system("CLS");

    printf("    ");
    for(i = 0; i < 4; ++i) {
        printf("  %c   ", 'A'+i);
    }

    printf("\t\n    ");
    for(i = 0; i < 4; ++i) {
        if(table->freeCells[i]) {
            suit = table->freeCells[i]->suit;
            rank = table->freeCells[i]->rank;
        } else {
            suit = rank = ' ';
        }

        printf("[%c,%c] ", suits[suit], ranks[rank]);
    }

    printf("\t");

    for(i = 0; i < 4; ++i) {
        if(table->homeCells[i] && table->homeCells[i]->start) {
            suit = table->homeCells[i]->start->card->suit;
            rank = table->homeCells[i]->start->card->rank;
        } else {
            suit = rank = ' ';
        }

        printf("[%c,%c] ", suits[suit], ranks[rank]);
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
                printf("[%c,%c] ", suits[suit], ranks[rank]);
            } else {
                printf("      ");
            }
        }
        printf("\n");
    }

    printf("      ");
    for(i = 0; i < 8; freeList(reverseHeaps[i++])) {
        printf("  %c   ", 'A' + i);
    }
}

void freeList(Node *node) {
    if(!node) return;

    freeList(node->next);
    free(node);
}

// Send to free cells: ^A (> B)
// Move to home cells: *A
// Retrieve from free cells: vA > B
// Move col to col: A1 > B
void inputCmd(Table *table) {
    char cmd[MAXSTR], cmdType;
    char colFrom = 0, colTo = 0;
    int cardQnt = 0;

    printf("\nType in a command: ");
    readLine(cmd);
    while(!(cmdType = getCmdType(cmd))) {
        fflush(stdin);
        printf("(?) -> Ajuda.\n");
        printf("\nType in a valid command: ");
        readLine(cmd);
    }

    // parse and execute command
    switch(cmdType) {
    case MOVETOFREECELLS:
        readCmd1(cmd, &colFrom, &colTo);
        printf("From col: %c | To col: %c\n", colFrom, colTo);
        moveToFreeCell(table, colFrom, colTo);
        break;
    case MOVETOHOMECELLS:
        readCmd2(cmd, &colFrom);
        printf("From col: %c\n", colFrom);
        moveToHomeCells(table, colFrom);
        break;
    case MOVEFROMFREECELLS:
        readCmd3(cmd, &colFrom, &colTo);
        printf("From col: %c | To col: %c\n", colFrom, colTo);
        moveFromFreeCells(table, colFrom, colTo);
        break;
    case MOVECOLTOCOL:
        readCmd4(cmd, &colFrom, &cardQnt, &colTo);
        printf("From col: %c | Card qnt: %d | To col: %c\n", colFrom, cardQnt, colTo);
        break;
    default:
        // Help.
        break;
    }

    getch();
}

void readLine(char str[]) {
    scanf("%[^\n]%*c", str);
}

int getCmdType(char cmd[]) {
    int i = 0, valid = 0;

    if(!cmd[i]) return 0;

    if(cmd[i] == '?') return HELP;

    for(i = -1; cmd[++i]; cmd[i] = toupper(cmd[i]))
        ;

    i = 0;
    i += skipSpaces(cmd);
    if(cmd[i] == '^') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H') * MOVETOFREECELLS;
    }

    if(cmd[i] == '*') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H') * MOVETOHOMECELLS;
    }

    if(cmd[i] == 'V') {
        i++;
        if(!cmd[i]) return 0;

        if(cmd[i] >= 'A' && cmd[i] <= 'D') {
            i++;
            i += skipSpaces(cmd + i);
            if(cmd[i++] == '>') {
                i += skipSpaces(cmd + i);
                return (cmd[i] >= 'A' && cmd[i] <= 'H') * MOVEFROMFREECELLS;
            }
        }
    }

    if(cmd[i] >= 'A' && cmd[i] <= 'H') {
        i++;
        if(!cmd[i]) return 0;

        // read numbers
        for(valid = 0; cmd[i] && cmd[i] >= '0' && cmd[i] <= '9'; valid += ++i)
            ;
        if(!valid) return 0;

        i += skipSpaces(cmd + i);
        if(cmd[i++] == '>') {
            i += skipSpaces(cmd + i);
            return (cmd[i] >= 'A' && cmd[i] <= 'H') * MOVECOLTOCOL;
        }
    }

    return 0;
}

int skipSpaces(char str[]) {
   int i;
   for(i = 0; str[i] == ' '; i++)
       ;
   return i;
}

void readCmd1(char cmd[], char *colFrom, char *colTo) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[++i];
    i++;
    i += skipSpaces(cmd + i);

    if(cmd[i++] == '>') {
        i += skipSpaces(cmd + i);
        if(cmd[i] >= 'A' && cmd[i] <= 'D') {
            *colTo = cmd[i];
        }
    }
}

void readCmd2(char cmd[], char *colFrom) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[++i];
}

void readCmd3(char cmd[], char *colFrom, char *colTo) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[++i];
    i++;

    i += skipSpaces(cmd + i);
    i++; // >
    i += skipSpaces(cmd + i);

    *colTo = cmd[i];
}

void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[i];
    i++;

    for(*cardQnt = 0; cmd[i] >= '0' && cmd[i] <= '9'; ++i) {
        *cardQnt = (*cardQnt * 10) + (cmd[i] - '0');
    }

    i += skipSpaces(cmd + i);
    i++; // >
    i += skipSpaces(cmd + i);

    *colTo = cmd[i];
}

void moveToFreeCell(Table *table, char colFrom, char colTo) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';

    if(colFromInd >= 0 && colFromInd < 8) {
        if(table->freeCellsQnt > 0) {
            if(table->tableau[colFromInd] && table->tableau[colFromInd]->start) {
                if(colToInd < 0 || colToInd >= 4) {
                    for(colToInd = 0; colToInd < 4 && table->freeCells[colToInd]; ++colToInd)
                        ;
                }
                node = pop(table->tableau[colFromInd]);
                card = node->card;
                table->freeCells[colToInd] = card;
                table->freeCellsQnt--;
                free(node);
            } else {
                printf("Column (%c) doesn't have any cards!\n", colFrom);
            }
        } else {
            printf("The are no free spaces!\n");
        }
    } else {
        printf("Column (%c) doesn't exist!\n", colFrom);
    }
}

void moveToHomeCells(Table *table, char colFrom) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';

    if(colFromInd >= 0 && colFromInd < 8) {
        if(table->tableau[colFromInd] && table->tableau[colFromInd]->start) {
            card = table->tableau[colFromInd]->start->card;

            if(table->homeCells[card->suit]) {
                node = table->homeCells[card->suit]->start;
            }
            if(!card->rank || (node && node->card->rank == card->rank-1)) {
                node = pop(table->tableau[colFromInd]);
                table->homeCells[card->suit] = insertCard(table->homeCells[card->suit], node->card);
                free(node);
            } else {
                printf("Card [%c,%c] cannot be discarded!\n", suits[card->suit], ranks[card->rank]);
            }
        } else {
            printf("Column (%c) doesn't have any cards!\n", colFrom);
        }
    } else {
        printf("Column (%c) doesn't exist!\n", colFrom);
    }
}

void moveFromFreeCells(Table *table, char colFrom, char colTo) {
    Card *cardFrom = NULL, *cardTo = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';

    if(colFromInd >= 0 && colFromInd < 4) {
        if(table->freeCells[colFromInd]) {
            cardFrom = table->freeCells[colFromInd];
            if(colFromInd >= 0 && colFromInd < 8) {
                if(table->tableau[colToInd] && table->tableau[colToInd]->start) {
                    node = table->tableau[colToInd]->start;
                    cardTo = node->card;
                    if((cardFrom->suit < 2 && cardTo->suit > 1) || (cardTo->suit < 2 && cardFrom->suit > 1)) {
                        if(cardFrom->rank+1 == cardTo->rank) {
                            table->tableau[colToInd] = insertCard(table->tableau[colToInd], cardFrom);
                            table->freeCells[colFromInd] = NULL;
                            table->freeCellsQnt++;
                        } else {
                            printf("Card [%c,%c] must have a rank down!\n", suits[cardFrom->suit], ranks[cardFrom->rank]);
                        }
                    } else {
                        printf("Cards must have alternate colors!\n");
                    }
                }
            }
        } else {
            printf("Column (%c) doesn't have any cards!\n", colFrom);
        }
    } else {
        printf("Column (%c) doesn't exist!\n", colFrom);
    }
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

Node *pop(Heap *heap) {
    Node *aux;

    if(!heap || !heap->start) return NULL;

    aux = heap->start;
    if(heap->start == heap->end) {
        heap->start = heap->end = NULL;
    } else {
        heap->start = heap->start->next;
    }
    heap->length--;
    aux->next = NULL;

    return aux;
}


Node *createNode(Card *card) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->card = card;
    newNode->next = NULL;

    return newNode;
}
