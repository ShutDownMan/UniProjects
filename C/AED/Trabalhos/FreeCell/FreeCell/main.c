#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#include "main.h"

///
/// \brief  main, função principal
/// \param  argc, número de argumentos passados
/// \param  argv, vetor de argumentos passados
/// \return se programa foi executado corretamente
/// \pre    nenhuma
/// \post   nenhuma
///
int main(int argc, char const *argv[]) {
    Table *table = createTable();
    int exit = 0;

    /// setup de rand e locale
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    /// teste se é pra carregar de arquivo
    if(argc == 1) {
        /// se não é, começa novo jogo
        startGame(table);
    } else {
        /// se é tenta carregar
        if(loadGame(table, (char*)argv[1])) {
            return 0;
        }
    }

    /// printa mesa na tela
    printTable(table);
    while(!exit) {
        /// lê e executa comando da entrada
        exit = inputCmd(table);

        /// printa mesa na tela
        printTable(table);
    }

//    liberar memória da mesa

    return 0;
}

// MAIN FUNCTIONS //

///
/// \brief  createTable, incializa mesa de jogo
/// \return mesa inicializada
/// \pre    nenhuma
/// \post   nenhuma
///
Table *createTable() {
    int i;
    Table *newTable = (Table*)malloc(sizeof(Table));

    /// inicializa todas as pilhas da mesa
    for(i = 0; i < 4; ++i) {
        newTable->tableau[i] = createHeap();
        newTable->tableau[i+4] = createHeap();
        newTable->homeCells[i] = createHeap();
        newTable->freeCells[i] = NULL;
    }

    /// inicializa quantidade de células e pilhas livres
    newTable->freeCellsQnt = 4;
    newTable->freeHeapsQnt = 8;

    /// retorna mesa inicializada
    return newTable;
}

///
/// \brief  startGame, prepara cartas para iniciar o jogo
/// \param  table, mesa de jogo
/// \pre    table e seus atributos tem que estar alocada corretamente
/// \post   cartas inicializadas e distribuidas em table
///
void startGame(Table *table) {
    int i;
    Card *deck[CARDSQNT] = {NULL};

    /// cria baralho
    createDeck(deck);

    /// embaralha baralho
    shuffleCards(deck);

    /// distribui cartas nas pilhas
    for(i = 0; i < CARDSQNT; ++i) {
        table->tableau[i%8] = insertCard(table->tableau[i%8], deck[i]);
    }

    /// inicializa quantidades de pilhas livres para 0
    table->freeHeapsQnt = 0;
}

///
/// \brief  createDeck, incializa todas as possiveis cartas
/// \param  deck, vetor de cartas
/// \pre    nenhuma
/// \post   cartas são alocadas e distribuidas no vetor
///
void createDeck(Card *deck[]) {
    int suitInd, rankNum;

    /// itera sobre os naipes
    for(suitInd = 0; suitInd < 4; ++suitInd) {
        /// itera sobre as ordens
        for(rankNum = 0; rankNum < 13; ++rankNum) {
            /// coloca carta em sua determinada posição no baralho
            deck[suitInd*13 + rankNum] = createCard(suitInd, rankNum);
        }
    }
}

///
/// \brief  createCard, inicializa carta de acordo com naipe e rank
/// \param  suitInd, naipe da carta
/// \param  rankInd, rank da carta
/// \return carta inicializada
/// \pre    nenhuma
/// \post   nenhuma
///
Card *createCard(int suitInd, int rankInd) {
    /// aloca memória para carta
    Card *newCard = (Card*)malloc(sizeof(Card));

    /// inicializa naipe e ordem da carta
    newCard->suit = suitInd;
    newCard->rank = rankInd;
    newCard->hint = 0;

    /// retorna nova carta
    return newCard;
}

///
/// \brief  shuffleCards, embaralha as cartas do baralho fornecido
/// \param  deck, baralho a ser embaralhado
/// \pre    baralho tem que estar inicializado
/// \post   cartas no vetor são embaralhadas
///
void shuffleCards(Card* deck[]) {
    int i, ind;
    Heap *rndHeap = NULL, *tableau[16] = {NULL};
    Node **tracer = NULL;

    /// para cada carta
    for(i = 0; i < 52; ++i) {
        /// escolhe um número aleatório de 0 a 15
        ind = rand() % 16;
        // coloca na correspondente pilha
        tableau[ind] = insertCard(tableau[ind], deck[i]);
    }

    /// para cada pilha
    for(i = 0; i < 16; ++i) {
        if(tableau[i]) {
            /// concatena pilha com as outras
            rndHeap = concatHeap(rndHeap, tableau[i]);
        }
    }

    /// volta as cartas para o baralho
    tracer = &rndHeap->start;
    for(i = 0; *tracer; ++i) {
        deck[i] = (*tracer)->card;
        tracer = &(*tracer)->next;
    }

    /// libera memória das pilhas usadas
    freeList(rndHeap->start);
    free(rndHeap);
}

///
/// \brief  printTable, printa na saida padrão o estado atual da mesa
/// \param  table, mesa a ser printada
/// \pre    nenhuma
/// \post   nenhuma
///
void printTable(Table *table) {
    int i;
    int lines;
    Node *current[8] = {NULL}, *reversedHeaps[8] = {NULL};

    /// limpa tela
    system("CLS");

    /// printa na tela a parte de cima da mesa
    printTop(table);

    /// inverte as pilhas para printar
    reverseTableauHeaps(table->tableau, reversedHeaps, &lines);
    for(i = 0; i < 8; ++i) {
        current[i] = reversedHeaps[i];
    }

    /// euquanto tiver linhas pra printar
    while(lines--) {
        printf("      ");
        /// para cada pilha
        for(i = 0; i < 8; ++i) {
            /// se nó atual existe
            if(current[i]) {
                printCard(current[i]->card);
                current[i] = current[i]->next;
            } else {
                printf("      ");
            }
        }
        printf("\n");
    }

    printf("      ");
    /// libera memória utilizada por cada pilha invertida
    for(i = 0; i < 8; ++i) {
        freeList(reversedHeaps[i]);
        printf("  %c   ", 'A' + i);
    }
    printf("\n");
}

///
/// \brief  printCard, printa carta na tela
/// \param  card, carta
/// \pre    nenhuma
/// \post   nenhuma
///
void printCard(Card *card) {
    unsigned char suit, rank, hint;

    if(card) {
        suit = card->suit; rank = card->rank; hint = card->hint;
    } else {
        suit = rank = -2;
        hint = 0;
    }

    /// se é pra pra mostrar carta como dica
    if(hint) {
        printf("%c%c,%c%c ", 166, getSuitByInd(suit), getRankByInd(rank), 166);
    } else {
        printf("%c%c,%c%c ", (suit%2) ? '(' : '[', getSuitByInd(suit), getRankByInd(rank), (suit%2) ? ')' : ']');
    }
}

///
/// \brief  printTop, printa na saida padrão as free e home cells
/// \param  table, mesa de jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void printTop(Table *table) {
    /// printa a primeira linha
    printTopCols();

    /// printa as free cells
    printFreeCells(table);

    printf("\t");

    /// printa as home cells
    printHomeCells(table);

    printf("\n");
}

///
/// \brief  printTopCols, printa na saida padrão as primeiras colunas guias
/// \pre    nenhuma
/// \post   nenhuma
///
void printTopCols() {
    int i;

    /// printa A-D
    printf("    ");
    for(i = 0; i < 4; ++i) {
        printf("  %c   ", 'A'+i);
    }

    printf("\t");

    /// printa os naipes
    for(i = 0; i < 4; ++i) {
        printf("  %c   ", getSuitByInd(i));
    }
}

///
/// \brief  printFreeCells, printa na saida padrão as free cells
/// \param  table, mesa de jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void printFreeCells(Table *table) {
    int i;

    /// para cada free cell
    printf("\n    ");
    for(i = 0; i < 4; ++i) {
        printCard(table->freeCells[i]);
    }
}

///
/// \brief  printHomeCells, printa na saida padrão as home cells
/// \param  table, mesa de jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void printHomeCells(Table *table) {
    int i;

    /// para cada home cell
    for(i = 0; i < 4; ++i) {
        /// se pilha não está vazia
        if(table->homeCells[i]->start) {
            printCard(table->homeCells[i]->start->card);
        } else {
            printCard(NULL);
        }
    }
}

///
/// \brief  reverseTableauHeaps, inverte as pilhas de cartas dispostas na mesa
/// \param  tableau, pilhas de cartas
/// \param  reversedHeaps, pilhas invertidas
/// \param  lines, número de cartas da maior pilha
/// \pre    pilhas tem que estar inicializadas
/// \post   nenhuma
///
void reverseTableauHeaps(Heap *tableau[], Node *reversedHeaps[], int *lines) {
    int i;

    /// para cada pilha na mesa
    for(i = *lines = 0; i < 8; ++i) {
        /// se pilha existe
        if(tableau[i]) {
            /// se maior número de nós é menor que o da pilha atual
            if(tableau[i]->length > *lines) {
                *lines = tableau[i]->length;
            }
            /// inverte pilha atual
            reversedHeaps[i] = reverseList(tableau[i]->start);
        }
    }
}

///
/// \brief  inputCmd, lê da entrada padrão um comando e o executa
/// \param  table, mesa de jogo que o comando sera executado
/// \return se é pra sair do jogo
/// \pre    nenhuma
/// \post   movimento é executado
///
int inputCmd(Table *table) {
    char cmd[MAXSTR], fileName[MAXSTR], cmdType;
    char colFrom = 0, colTo = 0;
    char suit = 0, rank = 0;
    int cardQnt = 0;

    /// enquanto comando for inválido
    printf("\nType in a command: ");
    readLine(cmd);
    while(!(cmdType = getCmdType(cmd))) {
        fflush(stdin);
        printf("(?) -> Ajuda.\n");
        printf("\nType in a valid command: ");
        readLine(cmd);
    }

    /// parseia e executa comando
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
        moveColToCol(table, colFrom, cardQnt, colTo);
        break;
    case FINDCARD:
        readCmd5(cmd, &suit, &rank);
        printf("suit: %c | rank: %c\n", suit, rank);
        findCard(table, suit, rank);
        break;
    case SAVEGAME:
        readCmd6(cmd, fileName);
        printf("Save game!\n");
        saveGame(table, fileName);
        break;
    case MOVEFROMFREECELLTOHOMECELL:
        readCmd7(cmd, &colFrom);
        printf("From col: %c\n", colFrom);
        moveFreeToHomeCell(table, colFrom);
        break;
    case HELP:
        // show help
        showHelp();
        break;
    default:
        return 1;
    }

    getch();
    return 0;
}

// MOVE MAKING //

///
/// \brief  inputCmd, lê da entrada padrão um comando e o executa
/// \param  table, mesa de jogo que o comando sera executado
/// \pre    pilha de saida  não pode ser nula
/// \post   movimento é executado
///
void moveToFreeCell(Table *table, char colFrom, char colTo) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';

    /// se tem células livres
    if(table->freeCellsQnt > 0) {
        /// se tem cartas na pilha de saida
        if(table->tableau[colFromInd]->start) {
            /// se indice da célula livre não é válido
            if(colToInd < 0 || colToInd >= 4) {
                /// escolhe a primeira livre
                for(colToInd = 0; colToInd < 4 && table->freeCells[colToInd]; ++colToInd)
                    ;
            }
            /// se já não tem nenhuma carta na célula
            if(!table->freeCells[colToInd]) {
                /// tira nó da pilha e coloca na pilha
                node = pop(table->tableau[colFromInd]);
                card = node->card;
                table->freeCells[colToInd] = card;

                /// atualiza valores de quantidade e libera nó
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

///
/// \brief  moveToHomeCells, executa comando de mover para home cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \pre    pilha de saida e pilha de fundação não podem ser nulas
/// \post   mesa é manipulada
///
void moveToHomeCells(Table *table, char colFrom) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';

    /// se pilha tem cartas
    if(table->tableau[colFromInd]->start) {
        /// pega carta mais ao topo da pilha de saida
        card = table->tableau[colFromInd]->start->card;

        /// pega nó mais ao topo da pilha de fundação
        node = table->homeCells[card->suit]->start;

        /// se é um As ou carta de fundação é uma sequência abaixo
        if(!card->rank || (node && node->card->rank == card->rank-1)) {
            /// retira carta da pilha de saída e coloca na fundação
            node = pop(table->tableau[colFromInd]);
            table->homeCells[card->suit] = insertCard(table->homeCells[card->suit], node->card);

            /// atualiza quantidade de pilhas livres e libera nó
            table->freeHeapsQnt += (!table->tableau[colFromInd]->length);
            free(node);
        } else {
            printf("Card [%c,%c] cannot be discarded!%c\n", getSuitByInd(card->suit), getRankByInd(card->rank), 7);
        }
    } else {
        printf("Column (%c) doesn't have any cards!%c\n", colFrom, 7);
    }
}

///
/// \brief  moveFromFreeCells, executa comando de mover das free cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \param  colTo, coluna que recebe a carta
/// \pre    célula de saida  não pode ser nula
/// \post   mesa é manipulada
///
void moveFromFreeCells(Table *table, char colFrom, char colTo) {
    Card *cardFrom = NULL, *cardTo = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';

    /// se tem carta pra ser retirada da célula
    if(table->freeCells[colFromInd]) {
        cardFrom = table->freeCells[colFromInd];
        node = table->tableau[colToInd]->start;
        cardTo = node->card;

        /// se pilha de entrada esta vazia ou as cartas tem cores alternadas
        if(!node || (cardFrom->suit%2 != cardTo->suit%2)) {
            /// se pilha de entrada esta vazia ou a carta de saída é uma sequência maior
            if(!node || (cardFrom->rank - cardTo->rank == -1)) {
                /// insere carta na pilha de entrada
                table->tableau[colToInd] = insertCard(table->tableau[colToInd], cardFrom);
                table->freeCells[colFromInd] = NULL;

                /// atualiza quantidade de células e pilhas livres
                table->freeCellsQnt++;
                table->freeHeapsQnt -= !(node);
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

///
/// \brief  moveColToCol, executa comando de mover coluna para coluna
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \param  cardQnt, quantidade de cartas a serem movidas
/// \param  colTo, coluna que recebe a carta
/// \pre    pilha de saida e pilha de entrada não podem ser nulas
/// \post   mesa é manipulada
///
void moveColToCol(Table *table, char colFrom, int cardQnt, char colTo) {
    Node *nodeFrom = NULL, *nodeTo = NULL;
    Card *cardFrom = NULL, *cardTo = NULL;
    Heap *heap;
    int colFromInd = colFrom - 'A';
    int colToInd = colTo - 'A';
    int i, valid;

    /// se tem cartas na pilha de saída
    if(table->tableau[colFromInd]->start) {
        /// se da pra mover quantidade de cartas fornecida
        if(cardQnt <= (table->freeCellsQnt + 1) * pow(2, table->freeHeapsQnt)) {
            nodeFrom = table->tableau[colFromInd]->start;

            /// se nenhuma carta foi pedida pra ser movida
            if(!cardQnt) return;

            /// para cada carta na pilha de saída
            for(i = valid = 1; i < cardQnt && valid; ++i) {
                /// se pilha tem cartas suficientes que a quantidade fornecida
                if(nodeFrom && nodeFrom->next) {
                    /// se cartas tem mesma cor
                    if(nodeFrom->card->suit%2 == nodeFrom->next->card->suit%2) {
                        valid = 0;
                        printf("Sequence must have alternate colors!%c\n", 7);
                    }
                    /// se cartas não estão na sequência correta
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
            /// se sequência de saída é válida
            if(valid) {
                cardFrom = nodeFrom->card;
                nodeTo = table->tableau[colToInd]->start;
                cardTo = table->tableau[colToInd]->start->card;

                /// se pilha de entrada estiver vazia ou carta de entrada tem cor alternada
                if(!nodeTo || cardFrom->suit%2 != cardTo->suit%2) {
                    /// se pilha de entrada estiver vazia ou carta de entrada esta na sequência correta
                    if(!nodeTo || cardFrom->rank - cardTo->rank == -1) {
                        heap = createHeap();
                        /// para cada carta na pilha de saída
                        for(i = 0; i < cardQnt; ++i) {
                            /// adiciona-se a uma pilha auxiliar
                            nodeTo = pop(table->tableau[colFromInd]);
                            heap = insertCard(heap, nodeTo->card);
                            free(nodeTo);
                        }
                        /// para cada carta na pilha auxiliar
                        for(i = 0; i < cardQnt; ++i) {
                            /// adiciona-se a pilha de entrada
                            nodeTo = pop(heap);
                            table->tableau[colToInd] = insertCard(table->tableau[colToInd], nodeTo->card);
                            free(nodeTo);
                        }
                        /// libera espaço da pilha auxiliar
                        free(heap);
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

///
/// \brief  findCard, procura carta indicada na mesa de jogo
/// \param  table, mesa de jogo
/// \param  suit, naipe
/// \param  rank, ordem
/// \pre    nenhuma
/// \post   nenhuma
///
void findCard(Table *table, char suit, char rank) {
    int i;
    int rankInd, suitInd, found;
    Node *node = NULL;
    Card *foundCard = NULL;

    /// pega naipe e ordem da carta a ser procurada
    suitInd = getIndBySuit(suit);
    rankInd = getIndByRank(rank);
    found = 0;

    /// para cada free e home cell
    for(i = 0; i < 4 && !found; ++i) {
        /// se tem carta na célula
        if(table->freeCells[i]) {
            /// se carta bate com a procura
            if(table->freeCells[i]->rank == rankInd && table->freeCells[i]->suit == suitInd) {
                /// marca a carta e para a pesquisa
                table->freeCells[i]->hint = 1;
                found = 1;
                foundCard = table->freeCells[i];
            }
        }
        /// se tem cartas na pilha de fundação
        if(table->homeCells[i]->start) {
            node = table->homeCells[i]->start;
            /// enquanto não estiver no final da pilha
            while(node && !found) {
                /// se carta bate com a pesquisa
                if(node->card->rank == rankInd && node->card->suit == suitInd) {
                    /// marca a carta e para a pesquisa
                    table->homeCells[i]->start->card->hint = 1;
                    found = 1;
                    foundCard = table->homeCells[i]->start->card;
                }
                node = node->next;
            }
        }
    }
    /// para pilha no tableau
    for(i = 0; i < 8 && !found; ++i) {
        /// se tem cartas na pilha
        if(table->tableau[i]->start) {
            node = table->tableau[i]->start;
            /// enqaunto não estiver no final da pilha
            while(node && !found) {
                /// se carta bate com a pesquisa
                if(node->card->rank == rankInd && node->card->suit == suitInd) {
                    /// marca a carta e para a pesquisa
                    node->card->hint = 1;
                    found = 1;
                    foundCard = node->card;
                }
                node = node->next;
            }
        }
    }
    /// se carta foi achada
    if(found) {
        /// printa mesa e desmarca a carta
        printTable(table);
        printf("Card found!\n");
        foundCard->hint = 0;
    }
}

///
/// \brief  saveGame, jogo é salvo em arquivo binário
/// \param  table, mesa de jogo
/// \param  fileName, nome do arquivo a ser salvo
/// \pre    nenhuma
/// \post   jogo é salvo
///
void saveGame(Table *table, char fileName[]) {
    FILE *f = openBinaryFile(fileName, "wb+");
    Card *card = NULL;
    Node *tracer = NULL;
    int i;

    /// inicializa pilhas no arquivo
    createEmptyList(f);

    /// para cada free e home cell
    for(i = 0; i < 4; ++i) {
        /// se tem carta na free cell
        if(table->freeCells[i]) {
            /// transforma carta em número e adiciona ao arquivo
            card = table->freeCells[i];
            insertNodeOnFreeCell(f, i, card->suit*13 + card->rank);
        }

        /// para cada nó na pilha de fundação
        for(tracer = table->homeCells[i]->start; tracer; tracer = tracer->next) {
            /// transforma carta em número e adiciona ao arquivo
            card = tracer->card;
            insertNodeOnHomeCell(f, i, card->suit*13 + card->rank);
        }
    }

    /// para cada pilha no tableau
    for(i = 0; i < 8; ++i) {
        /// para cada nó na pilha
        for(tracer = table->tableau[i]->start; tracer; tracer = tracer->next) {
            /// transforma carta em número e adiciona ao arquivo
            card = tracer->card;
            insertNodeOnTableau(f, i, card->suit*13 + card->rank);
        }
    }

    /// fecha arquivo
    fclose(f);
}

///
/// \brief  loadGame, carrega jogo a partir de arquivo binário
/// \param  table, mesa de jogo
/// \param  fileName, nome do arquivo a ser carregado
/// \return se arquivo foi carregado corretamente
/// \pre    mesa de jogo não pode estar inicializada
/// \post   jogo é carregado a memória
///
int loadGame(Table *table, char fileName[]) {
    FILE *f = openBinaryFile(fileName, "rb");
    Header *header = readHeader(f);
    FileNode *tracer = NULL;
    Card *card;
    int i, next = 0;

    /// se arquivo não foi aberto
    if(!f) return 1;

    /// para cada free e home cell
    for(i = 0; i < 4; ++i) {
        /// se tem carta na free cell
        printf("FREE[%d] = %d\n", i, header->freeCellsHeads[i]);
        if(header->freeCellsHeads[i] != -1) {
            /// lê nó e adiciona a mesa
            tracer = readFileNode(f, header->freeCellsHeads[i]);
            card = createCard(tracer->val/13, tracer->val%13);
            printf("[%c, %c]\n", getSuitByInd(card->suit), getRankByInd(card->suit));
            table->freeCells[i] = card;
            table->freeCellsQnt--;
            free(tracer);
        }

        /// se tem cartas na pilha
        printf("HOME[%d] = %d\n", i, header->homeCellsHeads[i]);
        if(header->homeCellsHeads[i] != -1) {
            /// para cada nó na pilha
            next = 0;
            for(tracer = readFileNode(f, header->homeCellsHeads[i]); next != -1; tracer = readFileNode(f, next)) {
                /// lê nó e adiciona a mesa
                card = createCard(tracer->val/13, tracer->val%13);
                table->homeCells[i] = insertCard(table->homeCells[i], card);

                next = tracer->next;
                free(tracer);
            }
        }
    }

    /// para cada pilha na tableau
    for(i = 0; i < 8; ++i) {
        /// se tem cartas na pilha
        printf(">TABLEAU[%d] = %d\n", i, header->tableauHeads[i]);
        if(header->tableauHeads[i] != -1) {
            /// para cada nó na pilha
            table->freeHeapsQnt--;
            next = 0;
            for(tracer = readFileNode(f, header->tableauHeads[i]); next != -1; tracer = readFileNode(f, next)) {
                /// lê nó e adiciona a mesa
                card = createCard(tracer->val/13, tracer->val%13);
                table->tableau[i] = insertCard(table->tableau[i], card);

                next = tracer->next;
                free(tracer);
            }
        }
    }

    printf("------------\n");
    printf("Game loaded!\n");

    /// fecha arquivo
    fclose(f);
    getch();
    return 0;
}


///
/// \brief  moveFreeToHomeCell, executa comando de mover das free cells para as home cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \pre    célula de saida  não pode ser nula
/// \post   mesa é manipulada
///
void moveFreeToHomeCell(Table *table, char colFrom) {
    Card *card = NULL;
    Node *node = NULL;
    int colFromInd = colFrom - 'A';

    /// se tem carta pra ser retirada da célula
    if(table->freeCells[colFromInd]) {
        /// pega carta da free cell
        card = table->freeCells[colFromInd];

        /// pega nó mais ao topo da pilha de fundação
        node = table->homeCells[card->suit]->start;

        /// se é um As ou carta de fundação é uma sequência abaixo
        if(!card->rank || (node && node->card->rank == card->rank-1)) {
            /// retira carta da free cell de saída e coloca na fundação
            table->freeCells[colFromInd] = NULL;
            table->homeCells[card->suit] = insertCard(table->homeCells[card->suit], card);

            /// atualiza quantidade de pilhas livres e libera nó
            table->freeCellsQnt += (!table->tableau[colFromInd]->length);
            free(node);
        } else {
            printf("Card [%c,%c] cannot be discarded!%c\n", getSuitByInd(card->suit), getRankByInd(card->rank), 7);
        }

    } else {
        printf("Column (%c) doesn't have any cards!%c\n", colFrom, 7);
    }
}

///
/// \brief  showHelp, printa na saida padrão os comandos usados para jogar o jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void showHelp() {
    system("CLS");
    printf("^A\n  => move coluna 'A' para free cell;\n");
    printf("^A > B\n  => move coluna 'A' para free cell 'B';\n");
    printf("*A\n  => move coluna 'A' para fundação;\n");
    printf("vA\n  => move coluna 'A' da free cell para tableau;\n");
    printf("v*A\n  => move coluna 'A' da free cell para fundacao;\n");
    printf("A > B\n  => move coluna 'A' do tableau para coluna 'B';\n");
    printf("(c,A)\n  => procura por carta As de copas no jogo;\n");
    printf("save \"nomearquivo.bin\"\n  => salva jogo como arquivo binario;\n");
}
