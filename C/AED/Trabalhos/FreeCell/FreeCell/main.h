#ifndef MAIN
#define MAIN

#include "heap.h"
#include "stringmanipulation.h"
#include "filemanipulation.h"

#define CARDSQNT 52

typedef struct table {
    int freeCellsQnt, freeHeapsQnt;
    Card *freeCells[4];
    Heap *homeCells[4], *tableau[8];
} Table;

// MAIN FUNCTIONS //

///
/// \brief createTable, incializa mesa de jogo
/// \return mesa inicializada
///
Table *createTable();

///
/// \brief startGame, prepara cartas para iniciar o jogo
/// \param table, mesa de jogo
///
void startGame(Table *table);

///
/// \brief createDeck, incializa todas as possiveis cartas
/// \param deck, vetor de cartas
///
void createDeck(Card *deck[]);

///
/// \brief createCard, inicializa carta de acordo com naipe e rank
/// \param suitInd, naipe da carta
/// \param rankInd, rank da carta
/// \return carta inicializada
///
Card *createCard(int suitInd, int rankInd);

///
/// \brief shuffleCards, embaralha as cartas do baralho fornecido
/// \param deck, baralho a ser embaralhado
///
void shuffleCards(Card *deck[]);

///
/// \brief printTable, printa na saida padrão o estado atual da mesa
/// \param table, mesa a ser printada
///
void printTable(Table *table);

void printTopCols();

void printTop(Table *table);

void printFreeCells(Table *table);

void printHomeCells(Table *table);

void reverseTableauHeaps(Heap *tableau[], Node *reversedHeaps[], int *lines);

///
/// \brief inputCmd, lê da entrada padrão um comando e o executa
/// \param table, mesa de jogo que o comando sera executado
///
void inputCmd(Table *table);

// MOVE MAKING //

///
/// \brief moveToFreeCell, executa comando de mover para free cells
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
/// \param colTo, coluna que recebe a carta
///
void moveToFreeCell(Table *table, char colFrom, char colTo);

///
/// \brief moveToHomeCells, executa comando de mover para home cells
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
///
void moveToHomeCells(Table *table, char colFrom);

///
/// \brief moveFromFreeCells, executa comando de mover das free cells
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
/// \param colTo, coluna que recebe a carta
///
void moveFromFreeCells(Table *table, char colFrom, char colTo);

///
/// \brief moveColToCol, executa comando de mover coluna para coluna
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
/// \param cardQnt, quantidade de cartas a serem movidas
/// \param colTo, coluna que recebe a carta
///
void moveColToCol(Table *table, char colFrom, int cardQnt, char colTo);

///
/// \brief findCard, procura carta indicada na mesa de jogo
/// \param table, mesa de jogo
/// \param suit, naipe
/// \param rank, ordem
///
void findCard(Table *table, char suit, char rank);

void saveGame(Table *table, char fileName[]);

void loadGame(Table *table, char fileName[]);

#endif // MAIN
