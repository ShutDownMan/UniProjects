#include "node.h"

/*!
 * \brief Node, construtor da classe, inicializa um valor em info
 */
template <class T>
Node<T>::Node(T const& info) {
    this->info = info;
    this->next = NULL;
}

/*!
 * \brief getInfo, função para acesso de leitura do valor armazenado
 * \return retorna valor armazenado pelo nó
 */
template <class T>
T Node<T>::getInfo() {
    return this->info;
}

/*!
 * \brief getNext, função para acesso ao proximo nó na lista
 * \return ponteiro para o proximo nó na fila
 */
template <class T>
Node<T> *Node<T>::getNext() {
    return this->next;
}

/*!
 * \brief setNext, função para acesso de escrita do valor armazenado
 * \param node, ponteiro para o próximo valor armazenado a ser atribuido
 */
template <class T>
void Node<T>::setNext(Node *node) {
    this->next = node;
}

/**
 * @brief getInfoPtr, função de acesso ao ponteiro do valor armazenado
 * @return ponteiro do valor armazenado pelo nó
 */
template <class T>
T *Node<T>::getInfoPtr() {
    return &this->info;
}

/*!
 * \brief insertOnHead, insere nó na cabeça da lista passada
 * \param head, ponteiro para o ponteiro do primeiro nó na lista
 * \param info, valor a ser inserido na lista
 * \return nova cabeça da lista
 */
template <class T>
Node<T> *Node<T>::insertOnHead(Node *&head, T const &info) {
    if(!head) {
        head = new Node<T>(info);
        return head;
    }

    Node<T> *newHead = new Node<T>(info);
    newHead->next = head;
    head = newHead;

    return newHead;
}

/*!
 * \brief insertOnTail, insere nó na cauda da lista passada
 * \param head, ponteiro para o ponteiro do primeiro nó da lista
 * \param info, valor a ser inserido
 * \return
 */
template <class T>
Node<T> *Node<T>::insertOnTail(Node *&head, T const &info) {
    if(!head) {
        head = new Node<T>(info);
        return head;
    }

    if(!head->next) {
        head->next = new Node<T>(info);
    } else {
        insertOnTail(head->next, info);
    }

    return head;
}

/*!
 * \brief removeHead, remove cabeça da lista
 * \param head, ponteiro para o ponteiro da cabeça da lista
 */
template <class T>
void Node<T>::removeHead(Node *&head) {
    Node *aux = head;

    if(aux) {
        head = head->next;
        delete aux;
    }
}

/*!
 * \brief removeTail, remove cauda da lista
 * \param head, ponteiro para o ponteiro da cabeça da lista
 */
template <class T>
void Node<T>::removeTail(Node *&node) {
    Node *aux = NULL;

    if(!node) return;

    if(node->next && !node->next->next) {
        aux = node->next;
        node->next = NULL;
    } else if(node && !node->next) {
        aux = node;
        node = NULL;
    }

    if(!aux) {
        removeTail(node->next);
    } else {
        delete aux;
    }
}

/*!
 * \brief revert, cria uma cópia da lista e inverte nós da mesma
 * \param head, ponteiro para o ponteiro da cabeça da lista
 * \return cópia dos elementos da lista invertidos
 */
template <class T>
Node<T> *Node<T>::revert(Node<T> *node) {
    Node<T> *aux = NULL;

    if(!node) return NULL;

    aux = revert(node->next);

    return insertOnTail(aux, node->info);
}

/*!
 * \brief getLength, retorna tamanho da lista formada pelo nó atual
 * \return inteiro tamanho da lista formada pelo nó atual
 */
template <class T>
int Node<T>::getLength() {
    if(!this->next) return 1;

    return 1 + this->next->getLength();
}

/*!
 * \brief getNodePos, procura e retorna nó na posição passada
 * \param pos, posição do nó
 * \return nó se achado
 */
template <class T>
Node<T> *Node<T>::getNodePos(int n) {

    if(n <= 0) return NULL;

    if(n == 1) {
        return this;
    } else {
        if(this->next) return this->next->getNodePos(n-1);
    }

    return NULL;
}

/*!
 * \brief operator [], procura e retorna nó na posição passada
 * \param pos, posição do nó
 * \return nó se achado
 */
template <class T>
Node<T> *Node<T>::operator [](int n) {
    return this->getNodePos(n+1);
}

/*!
 * \brief show, printa na saida padrão os nós da lista formada pelo nó atual
 */
template <class T>
void Node<T>::show() {
    cout << "(" << this->info << ")-> ";

    if(!this->next) {
        cout << "(!);" << endl;
    } else {
        this->next->show();
    }
}

/*!
 * \brief Node, destrutor da classe
 */
template <class T>
Node<T>::~Node() {
    printf("Freeing node");
    cout << " (" << this->info << ");" << endl;
}

