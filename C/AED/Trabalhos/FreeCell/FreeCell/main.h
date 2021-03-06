#ifndef MAIN
#define MAIN

#include "heap.h"
#include "stringmanipulation.h"
#include "filemanipulation.h"

#define CARDSQNT 52

// MAIN FUNCTIONS //

///
/// \brief  createTable, incializa mesa de jogo
/// \return mesa inicializada
/// \pre    nenhuma
/// \post   nenhuma
///
Table *createTable();

///
/// \brief  startGame, prepara cartas para iniciar o jogo
/// \param  table, mesa de jogo
/// \pre    table e seus atributos tem que estar alocada corretamente
/// \post   cartas inicializadas e distribuidas em table
///
void startGame(Table *table);

///
/// \brief  createDeck, incializa todas as possiveis cartas
/// \param  deck, vetor de cartas
/// \pre    nenhuma
/// \post   cartas são alocadas e distribuidas no vetor
///
void createDeck(Card *deck[]);

///
/// \brief  createCard, inicializa carta de acordo com naipe e rank
/// \param  suitInd, naipe da carta
/// \param  rankInd, rank da carta
/// \return carta inicializada
/// \pre    nenhuma
/// \post   nenhuma
///
Card *createCard(int suitInd, int rankInd);

///
/// \brief  shuffleCards, embaralha as cartas do baralho fornecido
/// \param  deck, baralho a ser embaralhado
/// \pre    baralho tem que estar inicializado
/// \post   cartas no vetor são embaralhadas
///
void shuffleCards(Card *deck[]);

///
/// \brief  printTable, printa na saida padrão o estado atual da mesa
/// \param  table, mesa a ser printada
/// \pre    nenhuma
/// \post   nenhuma
///
void printTable(Table *table);

///
/// \brief  printCard, printa carta na tela
/// \param  card, carta
/// \pre    nenhuma
/// \post   nenhuma
///
void printCard(Card *card);

///
/// \brief  printTop, printa na saida padrão as free e home cells
/// \param  table, mesa de jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void printTop(Table *table);

///
/// \brief  printTopCols, printa na saida padrão as primeiras colunas guias
/// \pre    nenhuma
/// \post   nenhuma
///
void printTopCols();

///
/// \brief  printFreeCells, printa na saida padrão as free cells
/// \param  table, mesa de jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void printFreeCells(Table *table);

///
/// \brief  printHomeCells, printa na saida padrão as home cells
/// \param  table, mesa de jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void printHomeCells(Table *table);

///
/// \brief  reverseTableauHeaps, inverte as pilhas de cartas dispostas na mesa
/// \param  tableau, pilhas de cartas
/// \param  reversedHeaps, pilhas invertidas
/// \param  lines, número de cartas da maior pilha
/// \pre    pilhas tem que estar inicializadas
/// \post   nenhuma
///
void reverseTableauHeaps(Stack *tableau[], Node *reversedHeaps[], int *lines);

///
/// \brief  inputCmd, lê da entrada padrão um comando e o executa
/// \param  table, mesa de jogo que o comando sera executado
/// \return se é pra sair do jogo
/// \pre    nenhuma
/// \post   movimento é executado
///
int inputCmd(Table *table);

// MOVE MAKING //

///
/// \brief  moveToFreeCell, executa comando de mover para free cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \param  colTo, coluna que recebe a carta
/// \pre    pilha de saida  não pode ser nula
/// \post   mesa é manipulada
///
void moveToFreeCell(Table *table, char colFrom, char colTo);

///
/// \brief  moveToHomeCells, executa comando de mover para home cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \pre    pilha de saida e pilha de fundação não podem ser nulas
/// \post   mesa é manipulada
///
void moveToHomeCells(Table *table, char colFrom);

///
/// \brief  moveFromFreeCells, executa comando de mover das free cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \param  colTo, coluna que recebe a carta
/// \pre    célula de saida  não pode ser nula
/// \post   mesa é manipulada
///
void moveFromFreeCells(Table *table, char colFrom, char colTo);

///
/// \brief  moveColToCol, executa comando de mover coluna para coluna
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \param  cardQnt, quantidade de cartas a serem movidas
/// \param  colTo, coluna que recebe a carta
/// \pre    pilha de saida e pilha de entrada não podem ser nulas
/// \post   mesa é manipulada
///
void moveColToCol(Table *table, char colFrom, int cardQnt, char colTo);

///
/// \brief  findCard, procura carta indicada na mesa de jogo
/// \param  table, mesa de jogo
/// \param  suit, naipe
/// \param  rank, ordem
/// \pre    nenhuma
/// \post   nenhuma
///
void findCard(Table *table, char suit, char rank);

///
/// \brief  saveGame, jogo é salvo em arquivo binário
/// \param  table, mesa de jogo
/// \param  fileName, nome do arquivo a ser salvo
/// \pre    nenhuma
/// \post   jogo é salvo
///
void saveGame(Table *table, char fileName[]);

///
/// \brief  loadGame, carrega jogo a partir de arquivo binário
/// \param  table, mesa de jogo
/// \param  fileName, nome do arquivo a ser carregado
/// \return se arquivo foi carregado corretamente
/// \pre    mesa de jogo não pode estar inicializada
/// \post   jogo é carregado a memória
///
int loadGame(Table *table, char fileName[]);

///
/// \brief  moveFreeToHomeCell, executa comando de mover das free cells para as home cells
/// \param  table, mesa de jogo a ser executado o comando
/// \param  colFrom, coluna que parte a carta
/// \pre    célula de saida  não pode ser nula
/// \post   mesa é manipulada
///
void moveFreeToHomeCell(Table *table, char colFrom);

///
/// \brief  showHelp, printa na saida padrão os comandos usados para jogar o jogo
/// \pre    nenhuma
/// \post   nenhuma
///
void showHelp();

#endif // MAIN
