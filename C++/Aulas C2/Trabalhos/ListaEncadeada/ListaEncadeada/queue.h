#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "node.h"

/*!
 * \brief The Queue class
 *
 * é uma classe que possui nós cabeça e cauda e permite inserção e remoção constante
 * na cabeça e cauda da fila
 *
 */
template <class T>
class Queue {

private:
    /*!
     * \brief head, ponteiro para o primeiro nó da fila
     */
    Node<T> *head;

    /*!
     * \brief head, ponteiro para o ultimo nó da fila
     */
    Node<T> *tail;

public:
    /*!
     * \brief Queue, construtor da fila
     */
    Queue();

    /*!
     * \brief enqueue, insere no final da fila o valor passado
     * \param info, valor a ser inserido
     */
    void enqueue(T const &info);

    /*!
     * \brief dequeue, retira o primeiro nó da fila
     */
    void dequeue();


    /*!
     * \brief pop, remove primeiro nó da pilha e retorna seu valor
     * \return valor do primeiro nó da pilha
     */
    T pop();

    /*!
     * \brief top, devolve valor do primeiro nó da pilha
     * \return valor do primeiro nó da pilha
     */
    T top();

    /*!
     * \brief revert, cria uma cópia da fila e inverte os elementos da mesma
     * \return cópia da fila invertida
     */
    Queue *revert();

    /*!
     * \brief isEmpty, retorna se a lista é vazia
     * \return um inteiro se a lista é vazia
     */
    bool isEmpty();

    /*!
     * \brief show, printa na saida padrão a pilha armazenada
     */
    void show();

    /*!
     * \brief Heap, destrutor da classe
     */
    ~Queue();
};

#include "queue.tcc"

#endif // QUEUE_H
