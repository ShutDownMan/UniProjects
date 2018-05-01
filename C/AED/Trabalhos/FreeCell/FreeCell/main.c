#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

#include "main.h"

int main(void) {
    Table *table = createTable();

    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    startGame(table);

//    loadGame(table);

    saveGame(table);

    printTable(table);
    while(1) {
        inputCmd(table);

        printTable(table);

        saveGame(table);
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
    newCard->hint = 0;

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

void printTable(Table *table) {
    int i;
    int lines;
    unsigned char suit, rank, hint;
    Node *current[8] = {NULL}, *reverseHeaps[8] = {NULL};

    system("CLS");

    printf("    ");
    for(i = 0; i < 4; ++i) {
        printf("  %c   ", 'A'+i);
    }

    printf("\t");

    for(i = 0; i < 4; ++i) {
        printf("  %c   ", getSuitByInd(i));
    }

    printf("\n    ");
    for(i = 0; i < 4; ++i) {
        if(table->freeCells[i]) {
            suit = table->freeCells[i]->suit;
            rank = table->freeCells[i]->rank;
            hint = table->freeCells[i]->hint;
        } else {
            suit = rank = -2;
            hint = 0;
        }

        if(hint) {
            printf("%c%c,%c%c ", 166, getSuitByInd(suit), getRankByInd(rank), 166);
        } else {
            printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
        }

    }

    printf("\t");

    for(i = 0; i < 4; ++i) {
        if(table->homeCells[i] && table->homeCells[i]->start) {
            suit = table->homeCells[i]->start->card->suit;
            rank = table->homeCells[i]->start->card->rank;
            hint = table->homeCells[i]->start->card->hint;
        } else {
            suit = rank = -2;
            hint = 0;
        }

        if(hint) {
            printf("%c%c,%c%c ", 166, getSuitByInd(suit), getRankByInd(rank), 166);
        } else {
            printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
        }
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

    while(lines--) {
        printf("      ");
        for(i = 0; i < 8; ++i) {
            if(current[i]) {
                suit = current[i]->card->suit;
                rank = current[i]->card->rank;
                hint = current[i]->card->hint;
                current[i] = current[i]->next;
                if(hint) {
                    printf("%c%c,%c%c ", 166, getSuitByInd(suit), getRankByInd(rank), 166);
                } else {
                    printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
                }
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
    printf("\n");
}

void inputCmd(Table *table) {
    char cmd[MAXSTR], cmdType;
    char colFrom = 0, colTo = 0;
    char suit = 0, rank = 0;
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
//        printf("fromcol: %c | To col: %c\n", colFrom, colTo);
        moveToFreeCell(table, colFrom, colTo);
        break;
    case MOVETOHOMECELLS:
        readCmd2(cmd, &colFrom);
//        printf("fromcol: %c\n", colFrom);
        moveToHomeCells(table, colFrom);
        break;
    case MOVEFROMFREECELLS:
        readCmd3(cmd, &colFrom, &colTo);
//        printf("fromcol: %c | To col: %c\n", colFrom, colTo);
        moveFromFreeCells(table, colFrom, colTo);
        break;
    case MOVECOLTOCOL:
        readCmd4(cmd, &colFrom, &cardQnt, &colTo);
//        printf("fromcol: %c | Card qnt: %d | To col: %c\n", colFrom, cardQnt, colTo);
        moveColToCol(table, colFrom, cardQnt, colTo);
        break;
    case FINDCARD:
        readCmd5(cmd, &suit, &rank);
        printf("suit: %c | rank: %c\n", suit, rank);
        findCard(table, suit, rank);
        break;
    default:
        // Help.
        break;
    }

    getch();
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
            if(!table->freeCells[colToInd]) {
                node = pop(table->tableau[colFromInd]);
                card = node->card;
                table->freeCells[colToInd] = card;

                table->freeCellsQnt--;
                table->freeHeapsQnt += (!table->tableau[colFromInd]);
                free(node);
            } else {
                printf("There's already a card on that spot!%c\n", 7);
            }
        } else {
            printf("Column (%c) doesn't have any cards!%c\n", colFrom, 7);
        }
    } else {
        printf("The are no free spaces!%c\n", 7);
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
                printf("Card [%c,%c] cannot be discarded!%c\n", getSuitByInd(card->suit), getRankByInd(card->rank), 7);
            }
        } else {
            printf("Column (%c) doesn't have any cards!%c\n", colFrom, 7);
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
                printf("Card [%c,%c] must have a rank down!%c\n", getSuitByInd(cardFrom->suit), getRankByInd(cardFrom->rank), 7);
            }
        } else {
            printf("Cards must have alternate colors!%c\n", 7);
        }
    } else {
        printf("Column (%c) doesn't have any cards!%c\n", colFrom, 7);
    }
}

void moveColToCol(Table *table, char colFrom, int cardQnt, char colTo) {
    Node *nodeFrom = NULL, *nodeTo = NULL;
    Card *cardFrom = NULL, *cardTo = NULL;
    Heap *heap;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';
    int i, valid;

    if(table->tableau[colFromInd]->start) {
        if(cardQnt <= table->freeCellsQnt + table->freeHeapsQnt + 1) {
            nodeFrom = table->tableau[colFromInd]->start;
            if(cardQnt < 1) {
                cardQnt = 1;
            }
            for(i = valid = 1; i < cardQnt && valid; ++i) {
                if(nodeFrom && nodeFrom->next) {
                    if(nodeFrom->card->suit%2 == nodeFrom->next->card->suit%2) {
                        valid = 0;
                        printf("Sequence must have alternate colors!%c\n", 7);
                    }
                    if(nodeFrom->card->rank - nodeFrom->next->card->rank != -1) {
                        valid = 0;
                        printf("Sequence must be ranking down!%c\n", 7);
                    }
                } else {
                    valid = 0;
                    printf("There are not %d card%s to be moved!%c\n", cardQnt, (cardQnt == 1) ? "" : "s", 7);
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
                        heap = createHeap();
                        for(i = 0; i < cardQnt; ++i) {
                            nodeTo = pop(table->tableau[colFromInd]);
                            heap = insertCard(heap, nodeTo->card);
                            free(nodeTo);
                        }
                        for(i = 0; i < cardQnt; ++i) {
                            nodeTo = pop(heap);
                            table->tableau[colToInd] = insertCard(table->tableau[colToInd], nodeTo->card);
                            free(nodeTo);
                        }
                    } else {
                        printf("Cards must have a rank down!%c\n", 7);
                    }
                } else {
                    printf("Cards must have alternate colors!%c\n", 7);
                }
            }
        } else {
            printf("You can only move %d cards now!%c\n", table->freeCellsQnt + table->freeHeapsQnt + 1, 7);
        }
    } else {
        printf("Column (%c) doesn't have any cards!%c\n", colFrom, 7);
    }
}

void findCard(Table *table, char suit, char rank) {
    int i;
    int rankInd, suitInd, found;
    Node *node = NULL;
    Card *foundCard = NULL;

    suitInd = getIndBySuit(suit);
    rankInd = getIndByRank(rank);
    found = 0;

    for(i = 0; i < 4 && !found; ++i) {
        if(table->freeCells[i]) {
            if(table->freeCells[i]->rank == rankInd && table->freeCells[i]->suit == suitInd) {
                table->freeCells[i]->hint = 1;
                found = 1;
                foundCard = table->freeCells[i];
            }
        }
        if(table->homeCells[i]->start) {
            node = table->homeCells[i]->start;
            while(node && !found) {
                if(node->card->rank == rankInd && node->card->suit == suitInd) {
                    table->homeCells[i]->start->card->hint = 1;
                    found = 1;
                    foundCard = table->homeCells[i]->start->card;
                }
                node = node->next;
            }
        }
    }
    for(i = 0; i < 8 && !found; ++i) {
        if(table->tableau[i]->start) {
            node = table->tableau[i]->start;
            while(node && !found) {
                if(node->card->rank == rankInd && node->card->suit == suitInd) {
                    node->card->hint = 1;
                    found = 1;
                    foundCard = node->card;
                }
                node = node->next;
            }
        }
    }
    if(found) {
        printTable(table);
        printf("Card found!\n");
        foundCard->hint = 0;
    }
}

void saveGame(Table *table) {
    FILE *f = openBinaryFile("gamesave.bin", "wb+");
    Node *aux = NULL;
    int i;

    createEmptyList(f);

    for(i = 0; i < 4; ++i) {
        if(table->freeCells[i]) {
            insertNodeOnFreeCell(f, i, *table->freeCells[i]);
        }

//        for(aux = table->homeCells[i]->start; aux; aux = aux->next) {
//            insertNodeOnHomeCell(f, i, *aux->card);
//        }
    }

//    for(i = 0; i < 8; ++i) {
//        for(aux = table->tableau[i]->start; aux; aux = aux->next) {
//            insertNodeOnTableau(f, i, *aux->card);
//        }
//    }

    fclose(f);
}

void loadGame(Table *table) {
    FILE *f = openBinaryFile("gamesavetest.bin", "rb");
    Header *header = readHeader(f);
    FileNode *aux = NULL;
    Card card = {.suit = -1, .rank = -1};
    int i, next = 0;

    for(i = 0; i < 4; ++i) {
//        printf("FREE[%d] = %d\n", i, header->freeCellsHeads[i]);
//        if(header->freeCellsHeads[i] != -1) {
//            aux = readFileNode(f, header->freeCellsHeads[i]);
//            card = aux->val;
//            printf("[%c, %c]\n", getSuitByInd(card.suit), getRankByInd(card.suit));
//            table->freeCells[i] = createCard(card.suit, card.suit);
//            table->freeCellsQnt--;
//            free(aux);
//        }

//        printf(">HOME[%d] = %d\n", i, header->homeCellsHeads[i]);
//        if(header->homeCellsHeads[i] != -1) {
//            next = 0;
//            for(aux = readFileNode(f, header->homeCellsHeads[i]); next != -1; aux = readFileNode(f, next)) {
//                card = aux->val;
//                table->homeCells[i] = insertCard(table->homeCells[i], &card);

//                next = aux->next;
//                free(aux);
//            }
//        }
    }

    for(i = 0; i < 8; ++i) {
        printf(">TABLEAU[%d] = %d\n", i, header->tableauHeads[i]);
        if(header->tableauHeads[i] != -1) {
            next = 0;
            for(aux = readFileNode(f, header->tableauHeads[i]); next != -1; aux = readFileNode(f, next)) {
                printf(">\tTABLEAU[%d] = %d\n", i, next);
                card = aux->val;
                table->tableau[i] = insertCard(table->tableau[i], createCard(card.suit, card.suit));

                next = aux->next;
                free(aux);
            }
        }
    }

    fclose(f);
    getch();
}
