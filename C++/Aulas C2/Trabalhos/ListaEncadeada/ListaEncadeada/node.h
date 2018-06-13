#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdio.h>

using namespace std;

/*!
 * \class Node
 * \brief The Node class
 *
 * é uma classe que simboliza um nó de lista encadeda e possui
 * funções de inserção, remoção e utilidades em uma lista encadeada simples
 *
 */
template <class T>
class Node {

private:
    /*!
     * \brief info, campo de armazenamento de valor do nó
     */
    T info;
    /*!
     * \brief next, ponteiro para o proximo nó na lista
     */
    Node *next;

public:
    /*!
     * \brief Node, construtor da classe (usado para classes herança)
     */
    Node();

    /*!
     * \brief Node, construtor da classe, inicializa um valor em info
     */
    Node(T const&);

    /*!
     * \brief getInfo, função para acesso de leitura do valor armazenado
     * \return retorna valor armazenado pelo nó
     */
    T getInfo();

    /*!
     * \brief getNext, função para acesso ao proximo nó na lista
     * \return ponteiro para o proximo nó na fila
     */
    Node *getNext();

    /*!
     * \brief setNext, função para acesso de escrita do valor armazenado
     * \param node, ponteiro para o próximo valor armazenado a ser atribuido
     */
    void setNext(Node *node);

    /**
     * @brief getInfoPtr, função de acesso ao ponteiro do valor armazenado
     * @return ponteiro do valor armazenado pelo nó
     */
    T *getInfoPtr();

    /*!
     * \brief insertOnHead, insere nó na cabeça da lista passada
     * \param head, ponteiro para o ponteiro do primeiro nó na lista
     * \param info, valor a ser inserido na lista
     * \return nova cabeça da lista
     */
    static Node *insertOnHead(Node *&head, T const &info);

    /*!
     * \brief insertOnTail, insere nó na cauda da lista passada
     * \param head, ponteiro para o ponteiro do primeiro nó da lista
     * \param info, valor a ser inserido
     * \return
     */
    static Node *insertOnTail(Node *&head, T const &info);

    /*!
     * \brief removeHead, remove cabeça da lista
     * \param head, ponteiro para o ponteiro da cabeça da lista
     */
    static void removeHead(Node *&head);

    /*!
     * \brief removeTail, remove cauda da lista
     * \param head, ponteiro para o ponteiro da cabeça da lista
     */
    static void removeTail(Node *&head);

    /*!
     * \brief revert, cria uma cópia da lista e inverte nós da mesma
     * \param head, ponteiro para o ponteiro da cabeça da lista
     * \return cópia dos elementos da lista invertidos
     */
    static Node *revert(Node<T> *head);

    /*!
     * \brief getLength, retorna tamanho da lista formada pelo nó atual
     * \return inteiro tamanho da lista formada pelo nó atual
     */
    int getLength();

    /*!
     * \brief getNodePos, procura e retorna nó na posição passada
     * \param pos, posição do nó
     * \return nó se achado
     */
    Node *getNodePos(int pos);

    /*!
     * \brief operator [], procura e retorna nó na posição passada
     * \param pos, posição do nó
     * \return nó se achado
     */
    Node *operator [](int);

    /*!
     * \brief show, printa na saida padrão os nós da lista formada pelo nó atual
     */
    void show();

    /*!
     * \brief Node, destrutor da classe
     */
    ~Node();
};

#include "node.tcc"

#endif // NODE_H
