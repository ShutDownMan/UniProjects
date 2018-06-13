#include "queue.h"

/*!
 * \brief Queue, construtor da fila
 */
template <class T>
Queue<T>::Queue() {
    this->head = NULL;
    this->tail = NULL;
}

/*!
 * \brief enqueue, insere no final da fila o valor passado
 * \param info, valor a ser inserido
 */
template <class T>
void Queue<T>::enqueue(T const &info) {
    Node<T> *newNode = new Node<T>(info);

    if(!this->tail) {
        this->head = newNode;
        this->tail = this->head;
    } else {
        this->tail->setNext(newNode);
        this->tail = newNode;
    }
}

/*!
 * \brief dequeue, retira o primeiro nó da fila
 */
template <class T>
void Queue<T>::dequeue() {
    Node<T> *tracer = NULL;

    Node<T>::removeTail(this->head);

    for(tracer = this->head; tracer && !tracer->getNext(); tracer = tracer->getNext())
        ;

    this->tail = tracer;
}

/*!
 * \brief pop, remove primeiro nó da pilha e retorna seu valor
 * \return valor do primeiro nó da pilha
 */
template <class T>
T Queue<T>::pop() {
    T info = this->top();

    Node<T>::removeHead(this->head);

    return info;
}

/*!
 * \brief top, devolve valor do primeiro nó da pilha
 * \return valor do primeiro nó da pilha
 */
template <class T>
T Queue<T>::top() {
    return this->head->getInfoPtr();
}

/*!
 * \brief revert, cria uma cópia da fila e inverte os elementos da mesma
 * \return cópia da fila invertida
 */
template <class T>
Queue<T> *Queue<T>::revert() {
    Queue<T> *reverted = new Queue<T>();
    Node<T> *tracer = NULL;

    reverted->head = Node<T>::revert(this->head);

    for(tracer = this->head; tracer && !tracer->getNext(); tracer = tracer->getNext())
        ;

    this->tail = tracer;

    return reverted;
}

/*!
 * \brief isEmpty, retorna se a lista é vazia
 * \return um inteiro se a lista é vazia
 */
template <class T>
bool Queue<T>::isEmpty() {
    return (this->head == NULL);
}

/*!
 * \brief show, printa na saida padrão a pilha armazenada
 */
template <class T>
void Queue<T>::show() {

    if(!this->isEmpty()) {
        printf("Queue: \n");
        this->head->show();
    } else {
        printf("Empty Queue\n");
    }
}

/*!
 * \brief Heap, destrutor da classe
 */
template <class T>
Queue<T>::~Queue() {
    printf("Freeing queue.\n");

    while(!this->isEmpty()) {
        this->dequeue();
    }
}

