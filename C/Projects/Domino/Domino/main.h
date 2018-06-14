#ifndef MAIN_H
#define MAIN_H

typedef struct domino {
    int x, y;
} Domino;

typedef Domino *ItemType;

typedef struct node {
    ItemType info;
    struct node *next;
} Node;

typedef struct list {
    int length;
    Node *head;
    Node *tail;
} List;

/*!
 * \brief createList, cria uma estrutura de lista encadeada com cabeça e cauda
 * \return ponteiro para lista criada e inicializada
 */
List *createList();

/*!
 * \brief readInputSet, lê da entrada padrão as peças que serão usadas
 * \param inList, lista a ser inserida as peças
 * \param setQnt, quantidade de peças a serem lidas
 */
void readInputSet(List *inList, int setQnt);

/*!
 * \brief createDomino, cria uma estrutura dominó que contem os valores dos lados x e y da peça
 * \param x, lado esquerdo
 * \param y, lado direito
 * \return ponteiro para peça criada e inicializada
 */
Domino *createDomino(int x, int y);

/*!
 * \brief insertOnHead, insere valor passado na cabeça da lista
 * \param aList, lista a ser inserido o valor
 * \param info, valor a ser inserido
 * \return lista original modificada
 */
List *insertOnHead(List *aList, ItemType info);

/*!
 * \brief insertOnTail, insere valor passado na cauda da lista
 * \param aList, lista a ser inserido o valor
 * \param info, valor a ser inserido
 * \return lista original modificada
 */
List *insertOnTail(List *aList, ItemType info);

/*!
 * \brief createNode, cria uma estrutura de nó que contém um valor e um ponteiro para o proximo nó na lista
 * \param info, valor armazenado pelo nó
 * \return nó criado e inicializado
 */
Node *createNode(ItemType info);

/*!
 * \brief printSet, printa na saida padrão a lista passada
 * \param set, lista a ser printada
 */
void printSet(List *set);

/*!
 * \brief freeList, libera nós da lista passada
 * \param aList, lista a ser liberada
 */
void freeList(List *aList);

/*!
 * \brief freeListInfo, libera nós e conteúdo da lista passada
 * \param aList, lista a ser liberada
 */
void freeListInfo(List *aList);

/*!
 * \brief isPossibleGame, testa se jogo é possivel passados as peças deste
 * \param aList, peças do jogo
 * \param gameSet, sequência resposta se jogo for possivel
 * \return um inteiro indicando se o jogo é possível
 */
int isPossibleGame(List *aList, List *gameSet);

/*!
 * \brief isPossiblePivot, testa se jogo é possivel passado um pivô e as peças livres
 * \param pivot, peça pivô usada para procurar uma peça que contém o valor do seu lado direito
 * \param aList, peças livres
 * \param gameSet, sequência resposta se jogo for possivel
 * \return um inteiro indicando se o jogo é possível
 */
int isPossiblePivot(ItemType pivot, List *aList, List *gameSet);

/*!
 * \brief cpyList, copia elementos da lista from para lista dest
 * \param dest, lista que recebe elementos
 * \param from, lista que elementos são copiados
 */
void cpyList(List *dest, List *from);

/*!
 * \brief removeNode, remove nós na lista com o valor passado
 * \param aList, lista a ser modificada
 * \param info, valor a procura
 */
void removeNode(List *aList, ItemType info);

/*!
 * \brief pop, remove primeiro nó da lista e retorna valor armazenado por ele
 * \param aList, lista a ser modificada
 * \return valor armazenado pelo primeiro nó da lista
 */
ItemType pop(List *aList);

/*!
 * \brief popNodePos, remove nó na posição especificada da lista e retorna valor armazenado por ele
 * \param aList, lista a ser modificada
 * \param n, posição do nó a ser removido
 * \return valor armazenado pelo primeiro nó da lista
 */
ItemType popNodePos(List *aList, int n);

/*!
 * \brief swap, troca o valor de dois inteiros um pelo outro
 * \param a, primeiro valor
 * \param b, segundo valor
 */
void swap(int *a, int *b);

#endif // MAIN_H
