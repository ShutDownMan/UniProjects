#include "heap.h"

/*!
 * \brief Heap, construtor da classe
 */
template <class T>
Heap<T>::Heap() {
    this->head = NULL;
}

/*!
 * \brief push, insere na pilha o valor passado
 * \param info, valor a ser inserido
 */
template <class T>
void Heap<T>::push(const T &info) {
    Node<T>::insertOnHead(this->head, info);
}

/*!
 * \brief pop, remove primeiro nó da pilha e retorna seu valor
 * \return valor do primeiro nó da pilha
 */
template <class T>
T Heap<T>::pop() {
    T info = this->top();

    Node<T>::removeHead(this->head);

    return info;
}

/*!
 * \brief top, devolve valor do primeiro nó da pilha
 * \return valor do primeiro nó da pilha
 */
template <class T>
T Heap<T>::top() {
    if(!this->isEmpty()) return this->head->getInfo();

    return 0;
}

/*!
 * \brief revert, cria uma cópia e inverte os elementos da mesma
 * \return cópia da pilha invertida
 */
template <class T>
Heap<T> *Heap<T>::revert() {
    Heap<T> *reverted = new Heap<T>();

    reverted->head = Node<T>::revert(this->head);

    return reverted;
}

/*!
 * \brief isEmpty, retorna se a lista é vazia
 * \return um inteiro se a lista é vazia
 */
template <class T>
bool Heap<T>::isEmpty() {
    return (this->head == NULL);
}

/*!
 * \brief show, printa na saida padrão a pilha armazenada
 */
template <class T>
void Heap<T>::show() {

    if(!this->isEmpty()) {
        printf("Heap: \n");
        this->head->show();
    } else {
        printf("Empty Heap\n");
    }
}

/*!
 * \brief Heap, destrutor da classe
 */
template <class T>
Heap<T>::~Heap() {
    printf("Freeing heap.\n");

    while(!this->isEmpty()) {
        this->pop();
    }
}
