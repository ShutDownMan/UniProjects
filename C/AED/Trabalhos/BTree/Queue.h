//
// Created by Jedson on 10/21/2018.
//

#ifndef BTREE_QUEUE_H
#define BTREE_QUEUE_H

/// estrutura de nó para fila de lista encadeada
typedef struct QNode {
    /// valor armazenado
    void *info;
    /// ponteiro para o proximo
    struct QNode *next;
} QNode;

/// estrutura de fila de lista encadeada
typedef struct Queue {
    /// ponteiro para começo e fim da fila
    QNode *first, *last;
    int count;
} Queue;

//- INITIALIZE -//

/**
 * cria uma nova fila
 * @return fila alocada e inicializada
 * @precondition nenhuma
 * @postcondition fila é criada e retornada
 */
Queue *createQueue();

/**
 * cria um nó de fila
 * @param info valor a ser armazenado pelo novo nó
 * @return nó alocado e inicializado
 * @precondition nenhuma
 * @postcondition nó é criado e retornado
 */
QNode *createQNode(void *info);

//- UPDATE -//

/**
 * insere valor no final da fila
 * @param queue fila a ser inserido o valor
 * @param info valor a ser inserido na fila
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void pushQ(Queue *queue, void *info);

/**
 * retorna valor o começo da fila
 * @param queue é a fila ser modificada
 * @return nó no começo da fila
 * @precondition nenhuma
 * @postcondition nó no começo da fila é modificado
 */
QNode *popQ(Queue *queue);

//- DELETE -//

/**
 * remove a fila
 * @param queue fila a ser liberada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void deleteQueue(Queue *queue);

//- SHOW -//

/**
 * printa na saida padrão a fila indicada
 * @param queue fila indicada
 * @precondition nenhuma
 * @postcondition nenhuma
 */
void printQ(Queue *queue);

#endif //BTREE_QUEUE_H
