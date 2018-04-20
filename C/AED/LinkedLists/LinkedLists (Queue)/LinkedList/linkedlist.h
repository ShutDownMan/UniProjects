#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct Node {
    int info;
    struct Node *next;
} Node;

typedef struct Queue {
    int length;
    Node *first;
    Node *last;
} Queue;

// EXERCISES FUNCTIONS //

///
/// \brief isEmpty, testa se fila é vazia
/// \param q, fila a ser testada
/// \return inteiro diferente de 0 se a fila está vazia
///
int isEmpty(Queue *q);

///
/// \brief enqueue, insere na fila o valor indicado
/// \param q, fila a ser alterada
/// \param val, valor a ser inserido
///
Queue *enqueue(Queue *q, int val);

///
/// \brief dequeue, tira da fila o valor indicado
/// \param q, fila a ser alterada
/// \param val, valor a ser retirado
///
void dequeue(Queue *q, int val);

///
/// \brief printQueue, printa na saida padrão a fila indicada
/// \param q, fila a ser printada
///
void printQueue(Queue *q);

// HELPER FUNCTIONS //

///
/// \brief readQueue, lê da entrada padrão uma fila
///
Queue *readQueue();

///
/// \brief createNode, aloca espaço na memória para armazenar um nó
/// \param val, valor a ser armazenado
/// \return nó criado
///
Node *createNode(int val);


#endif // LINKEDLIST

