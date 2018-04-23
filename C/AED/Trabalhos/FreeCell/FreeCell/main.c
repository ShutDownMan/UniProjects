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
        newTable->tableau[i] = createHeap();
        newTable->tableau[i+4] = createHeap();
        newTable->homeCells[i] = createHeap();
        newTable->freeCells[i] = NULL;
    }

    newTable->freeCellsQnt = 4;
    newTable->freeHeapsQnt = 0;

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
    Node **tracer = NULL;

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
        tracer = &(*tracer)->next;
    }

    freeList(rndHeap->start);
    free(rndHeap);
}

// STRING MANIPULATION //

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
            suit = rank = -2;
        }

        printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
    }

    printf("\t");

    for(i = 0; i < 4; ++i) {
        if(table->homeCells[i] && table->homeCells[i]->start) {
            suit = table->homeCells[i]->start->card->suit;
            rank = table->homeCells[i]->start->card->rank;
        } else {
            suit = rank = -2;
        }

        printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
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
                printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
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

char getSuitByInd(unsigned char ind) {
    if(ind < 4) {
        return suits[ind];
    }
    return ' ';
}

char getRankByInd(unsigned char ind) {
    if(ind < 13) {
        return ranks[ind];
    }
    return ' ';
}

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
//        printf("From col: %c | To col: %c\n", colFrom, colTo);
        moveToFreeCell(table, colFrom, colTo);
        break;
    case MOVETOHOMECELLS:
        readCmd2(cmd, &colFrom);
//        printf("From col: %c\n", colFrom);
        moveToHomeCells(table, colFrom);
        break;
    case MOVEFROMFREECELLS:
        readCmd3(cmd, &colFrom, &colTo);
//        printf("From col: %c | To col: %c\n", colFrom, colTo);
        moveFromFreeCells(table, colFrom, colTo);
        break;
    case MOVECOLTOCOL:
        readCmd4(cmd, &colFrom, &cardQnt, &colTo);
//        printf("From col: %c | Card qnt: %d | To col: %c\n", colFrom, cardQnt, colTo);
        moveColToCol(table, colFrom, cardQnt, colTo);
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
    if(!cmd[0]) return 0;

    if(cmd[0] == '?') return HELP;

    strToUpper(cmd);

    if(testCmdMoveToFreeCells(cmd)) return MOVETOFREECELLS;

    if(testCmdMoveToHomeCells(cmd)) return MOVETOHOMECELLS;

    if(testCmdMoveFromFreeCells(cmd)) return MOVEFROMFREECELLS;

    if(testCmdMoveColToCol(cmd)) return MOVECOLTOCOL;

    return 0;
}

void strToUpper(char str[]) {
    int i;
    for(i = -1; str[++i]; str[i] = toupper(str[i]))
        ;
}

int testCmdMoveToFreeCells(char cmd[]) {
    int i = 0;
    i += skipSpaces(cmd);
    if(cmd[i] == '^') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H');
    }
    return 0;
}

int testCmdMoveToHomeCells(char cmd[]) {
    int i = 0;
    if(cmd[i] == '*') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H');
    }
    return 0;
}

int testCmdMoveFromFreeCells(char cmd[]) {
    int i = 0;
    if(cmd[i] == 'V') {
        i++;
        if(!cmd[i]) return 0;

        if(cmd[i] >= 'A' && cmd[i] <= 'D') {
            i++;
            i += skipSpaces(cmd + i);
            if(cmd[i++] == '>') {
                i += skipSpaces(cmd + i);
                return (cmd[i] >= 'A' && cmd[i] <= 'H');
            }
        }
    }
    return 0;
}

int testCmdMoveColToCol(char cmd[]) {
    int i = 0, valid = 0;
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

// MOVE MAKING //

void moveToFreeCell(Table *table, char colFrom, char colTo) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';

    if(table->freeCellsQnt > 0) {
        if(table->tableau[colFromInd]->start) {
            if(colToInd < 0 || colToInd >= 4) {
                for(colToInd = 0; colToInd < 4 && table->freeCells[colToInd]; ++colToInd)
                    ;
            }

            node = pop(table->tableau[colFromInd]);
            card = node->card;
            table->freeCells[colToInd] = card;

            table->freeCellsQnt--;
            table->freeHeapsQnt += (!table->tableau[colFromInd]);
            free(node);
        } else {
            printf("Column (%c) doesn't have any cards!\n", colFrom);
        }
    } else {
        printf("The are no free spaces!\n");
    }
}

void moveToHomeCells(Table *table, char colFrom) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';

    if(colFromInd >= 0 && colFromInd < 8) {
        if(table->tableau[colFromInd]->start) {
            card = table->tableau[colFromInd]->start->card;

            if(table->homeCells[card->suit]) {
                node = table->homeCells[card->suit]->start;
            }
            if(!card->rank || (node && node->card->rank == card->rank-1)) {
                node = pop(table->tableau[colFromInd]);
                table->homeCells[card->suit] = insertCard(table->homeCells[card->suit], node->card);

                table->freeHeapsQnt += (!table->tableau[colFromInd]->length);
                free(node);
            } else {
                printf("Card [%c,%c] cannot be discarded!\n", suits[card->suit], ranks[card->rank]);
            }
        } else {
            printf("Column (%c) doesn't have any cards!\n", colFrom);
        }
    }
}

void moveFromFreeCells(Table *table, char colFrom, char colTo) {
    Card *cardFrom = NULL, *cardTo = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';

    if(table->freeCells[colFromInd]) {
        cardFrom = table->freeCells[colFromInd];
        if(table->tableau[colToInd]->start) {
            node = table->tableau[colToInd]->start;
            cardTo = node->card;
        }
        if(!node || (cardFrom->suit%2 != cardTo->suit%2)) {
            if(!node || (cardFrom->rank - cardTo->rank == -1)) {
                table->tableau[colToInd] = insertCard(table->tableau[colToInd], cardFrom);
                table->freeCells[colFromInd] = NULL;

                table->freeCellsQnt++;
                table->freeHeapsQnt -= (!node);
            } else {
                printf("Card [%c,%c] must have a rank down!\n", suits[cardFrom->suit], ranks[cardFrom->rank]);
            }
        } else {
            printf("Cards must have alternate colors!\n");
        }
    } else {
        printf("Column (%c) doesn't have any cards!\n", colFrom);
    }
}

void moveColToCol(Table *table, char colFrom, int cardQnt, char colTo) {
    Node *nodeFrom = NULL, *nodeTo = NULL;
    Card *cardFrom = NULL, *cardTo = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';
    int i, valid;

    if(table->tableau[colFromInd]->start) {
        if(cardQnt <= table->freeCellsQnt + table->freeHeapsQnt + 1) {
            nodeFrom = table->tableau[colFromInd]->start;
            for(i = valid = 1; i < cardQnt && valid; ++i) {
                if(nodeFrom && nodeFrom->next) {
                    if(nodeFrom->card->suit%2 == nodeFrom->next->card->suit%2) {
                        valid = 0;
                        printf("Sequence must have alternate colors!\n");
                    }
                    if(nodeFrom->card->rank - nodeFrom->next->card->rank != -1) {
                        valid = 0;
                        printf("Sequence must be ranking down!\n");
                    }
                } else {
                    valid = 0;
                    printf("There are not %d card%s to be moved!\n", cardQnt, (cardQnt == 1) ? "" : "s");
                }
                nodeFrom = nodeFrom->next;
            }
            if(valid) {
                cardFrom = nodeFrom->card;
                nodeTo = table->tableau[colToInd]->start;
                if(nodeTo) {
                    cardTo = table->tableau[colToInd]->start->card;
                }
                if(!nodeTo || cardFrom->suit%2 != cardTo->suit%2) {
                    if(!nodeTo || cardFrom->rank - cardTo->rank == -1) {
                        for(i = 0; i < cardQnt; ++i) {
                            nodeTo = pop(table->tableau[colFromInd]);
                            table->tableau[colToInd] = insertCard(table->tableau[colToInd], nodeTo->card);
                            free(nodeTo);
                        }
                    } else {
                        printf("Cards must have a rank down!\n");
                    }
                } else {
                    printf("Cards must have alternate colors!\n");
                }
            }
        } else {
            printf("You can only move %d cards now!\n", table->freeCellsQnt + table->freeHeapsQnt + 1);
        }
    } else {
        printf("Column (%c) doesn't have any cards!\n", colFrom);
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
            heap2->end->next = heap1->start;
            heap2->end = heap1->end;
            heap1->start = heap2->start;
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

void freeList(Node *node) {
    if(!node) return;

    freeList(node->next);
    free(node);
}
