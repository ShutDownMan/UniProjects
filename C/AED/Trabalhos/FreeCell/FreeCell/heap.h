#ifndef HEAP
#define HEAP

typedef struct Card {
    unsigned char suit, rank, hint;
} Card;

typedef struct node {
    Card *card;
    struct node *next;
} Node;

typedef struct heap {
    int length;
    Node *start, *end;
} Heap;

// estrutura da mesa de jogo
typedef struct table {
    // quantidade de células e pilhas livres
    int freeCellsQnt, freeHeapsQnt;
    // células
    Card *freeCells[4];
    // pilhas e fundações
    Heap *homeCells[4], *tableau[8];
} Table;

// HEAP FUNCTIONS //

///
/// \brief  createHeap, inicializa pilha
/// \return pilha inicializada
/// \pre    nenhuma
/// \post   retorna memória alocada para pilha inicializada
///
Heap *createHeap();

///
/// \brief  insertCard, insere na pilha a carta indicada
/// \param  heap, pilha a ser modificada
/// \param  card, carta a ser inserida
/// \return pilha modificada
/// \pre    nenhuma
/// \post   nenhuma
///
Heap *insertCard(Heap *heap, Card *card);

///
/// \brief  concatHeap, concatena duas pilhas
/// \param  heap1, primeira pilha
/// \param  heap2, segunda pilha
/// \return primeira pilha
/// \pre    nenhuma
/// \post   nenhuma
///
Heap *concatHeap(Heap *heap1, Heap *heap2);

///
/// \brief  reverseHeap, inverte uma cópia
/// \param  node, cabeça atual da lista
/// \return pilha invertida
/// \pre    nenhuma
/// \post   nenhuma
///
Node *reverseList(Node *node);

///
/// \brief  insertNodeOnTail, insere nó no final da lista fornecida
/// \param  list, lista a ser modificada
/// \param  card, carta a ser adicionada
/// \return lista modificada
/// \pre    nenhuma
/// \post   nó é inserida na cauda
///
Node *insertNodeOnTail(Node *list, Card *card);

///
/// \brief  pop, retira a cabeça de uma pilha e a retorna
/// \param  heap, pilha a ser modificada
/// \return nó removido da pilha
/// \pre    nenhuma
/// \post   pilha perde a cabeça
///
Node *pop(Heap *heap);

///
/// \brief  createNode, inicializa nó
/// \param  card, carta apontada pelo nó
/// \return nó inicializado
/// \pre    nenhuma
/// \post   nenhuma
///
Node *createNode(Card *card);

///
/// \brief  freeList, libera espaço da memória usado para lista
/// \param  node, cabeça atual da lista
/// \pre    nenhuma
/// \post   memória da lista é liberada
///
void freeList(Node *node);

#endif // HEAP

