#ifndef FREECELL
#define FREECELL

#define MAXCARDS 52
#define MAXSTR 64

#define HELP -1
#define MOVETOFREECELLS 1
#define MOVETOHOMECELLS 2
#define MOVEFROMFREECELLS 3
#define MOVECOLTOCOL 4

// (v)copas, (p)espadas, (p)paus, (v)ouros,
char suits[4] = {'c', 'e', 'p', 'o'};
char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

typedef struct Card {
    unsigned char suit, rank;
} Card;

typedef struct node {
    Card *card;
    struct node *next;
} Node;

typedef struct heap {
    int length;
    Node *start, *end;
} Heap;

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

// STRING MANIPULATION //

///
/// \brief printTable, printa na saida padrão o estado atual da mesa
/// \param table, mesa a ser printada
///
void printTable(Table *table);

///
/// \brief inputCmd, lê da entrada padrão um comando e o executa
/// \param table, mesa de jogo que o comando sera executado
///
void inputCmd(Table *table);

///
/// \brief getCmdType, lê comando e determina seu tipo
/// \param cmd, string a ser lida
/// \return tipo do comando
///
int getCmdType(char cmd[]);

///
/// \brief skipSpaces, pula espaços de dada string
/// \param str, string a ser lida
/// \return quantidade de espaços a ser pulada
///
int skipSpaces(char str[]);

///
/// \brief readLine, lê da entrada padrão uma linha
/// \param str, armazena linha lida
///
void readLine(char str[]);

void strToUpper(char str[]);

int testCmdMoveToFreeCells(char cmd[]);

int testCmdMoveToHomeCells(char cmd[]);

int testCmdMoveFromFreeCells(char cmd[]);

int testCmdMoveColToCol(char cmd[]);

///
/// \brief readCmd1, executa parse em comando de (mover para free cells)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
/// \param colTo, armazena segunda coluna lida
///
void readCmd1(char cmd[], char *colFrom, char *colTo);

///
/// \brief readCmd1, executa parse em comando de (mover para home cells)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
///
void readCmd2(char cmd[], char *colFrom);

///
/// \brief readCmd1, executa parse em comando de (mover das free cells)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
/// \param colTo, armazena segunda coluna lida
///
void readCmd3(char cmd[], char *colFrom, char *colTo);

///
/// \brief readCmd1, executa parse em comando de (mover coluna para coluna)
/// \param cmd, string a ser parseada
/// \param colFrom, armazena primeira coluna lida
/// \param cardQnt, armazena quantidade de cartas lida
/// \param colTo, armazena segunda coluna lida
///
void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo);

// MOVE MAKING //

///
/// \brief moveToFreeCell, executa comando de mover para free cells
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
/// \param colTo, coluna que recebe a carta
///
void moveToFreeCell(Table *table, char colFrom, char colTo);

///
/// \brief moveToFreeCell, executa comando de mover para home cells
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
///
void moveToHomeCells(Table *table, char colFrom);

///
/// \brief moveToFreeCell, executa comando de mover das free cells
/// \param table, mesa de jogo a ser executado o comando
/// \param colFrom, coluna que parte a carta
/// \param colTo, coluna que recebe a carta
///
void moveFromFreeCells(Table *table, char colFrom, char colTo);

// HEAP FUNCTIONS //

///
/// \brief createHeap, inicializa pilha
/// \return pilha inicializada
///
Heap *createHeap();

///
/// \brief insertCard, insere na pilha a carta indicada
/// \param heap, pilha a ser modificada
/// \param card, carta a ser inserida
/// \return pilha modificada
///
Heap *insertCard(Heap *heap, Card *card);

///
/// \brief concatHeap, concatena duas pilhas
/// \param heap1, primeira pilha
/// \param heap2, segunda pilha
/// \return primeira pilha
///
Heap *concatHeap(Heap *heap1, Heap *heap2);

///
/// \brief reverseHeap, inverte uma cópia
/// \param node, cabeça atual da lista
/// \return
///
Node *reverseHeap(Node *node);

///
/// \brief insertNodeOnTail, insere nó no final da lista fornecida
/// \param list, lista a ser modificada
/// \param card, carta a ser adicionada
/// \return
///
Node *insertNodeOnTail(Node *list, Card *card);

///
/// \brief pop, retira a cabeça de uma pilha e a retorna
/// \param heap, pilha a ser modificada
/// \return
///
Node *pop(Heap *heap);

///
/// \brief createNode, inicializa nó
/// \param card, carta apontada pelo nó
/// \return nó inicializado
///
Node *createNode(Card *card);

///
/// \brief freeList, libera espaço da memória usado para lista
/// \param node, cabeça atual da lista
///
void freeList(Node *node);

#endif // FREECELL
