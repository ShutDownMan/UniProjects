#ifndef HEAP_H
#define HEAP_H

#include "node.h"
#include <stdio.h>

/*!
 * \brief The Heap class
 *
 * é uma classe que possui um nó cabeça e permite inserção e remoção constante
 * na cabeça da pilha
 *
 */
template <class T>
class Heap {
private:
    /*!
     * \brief head, ponteiro para o primeiro nó da pilha
     */
    Node<T> *head;

public:
    /*!
     * \brief Heap, construtor da classe
     */
    Heap();

    /*!
     * \brief push, insere na pilha o valor passado
     * \param info, valor a ser inserido
     */
    void push(T const& info);

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
     * \brief revert, cria uma cópia da pilha e inverte os elementos da mesma
     * \return cópia da pilha invertida
     */
    Heap *revert();

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
    ~Heap();
};

#include "heap.tcc"

#endif // HEAP_H
