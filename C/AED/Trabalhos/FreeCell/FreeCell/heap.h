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
Node *reverseList(Node *node);

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

#endif // HEAP

