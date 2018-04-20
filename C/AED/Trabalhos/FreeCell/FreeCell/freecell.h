#ifndef FREECELL
#define FREECELL

char suits[4] = {'c', 'd', 'h', 's'};
char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

typedef struct Card {
    char suit, rank;
} Card;

typedef struct node {
    Card *card;
    struct node *next;
} Node;

typedef struct heap {
    Node *start, *end;
} Heap;

typedef struct table {
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
/// \brief createHeap, inicializa pilha
/// \return pilha inicializada
///
Heap *createHeap();

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
/// \brief distributeCards, distribui as cartas na mesa
/// \param tableau, mesa do jogo
///
void distributeCards(Heap *tableau[]);

///
/// \brief printTable, printa na saida padrão o estado atual da mesa
/// \param table, mesa a ser printada
///
void printTable(Table *table);

// HEAP FUNCTIONS //

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
/// \brief createNode, inicializa nó
/// \param card, carta apontada pelo nó
/// \return nó inicializado
///
Node *createNode(Card *card);

#endif // FREECELL
