#ifndef LINKEDLIST
#define LINKEDLIST

#define ItemType int
#define ItemFormat "%d"

#define MAX 64

typedef struct Node {
    ItemType info;
    struct Node *next;
} Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
} List;

// EXERCISES FUNCTIONS //

///
/// \brief testa se lista é vazia
/// \param list, lista a ser testada
/// \return inteiro diferente de 0 se for vazia e 0 se for
///
int isEmpty(List *list);

///
/// \brief insere novo elemento na cabeça da lista
/// \param list, lista a ser modificada
/// \param val, valor a ser inserido na lista
/// \return nova cabeça da lista
///
List *insertOnHead(List *list, ItemType val);

///
/// \brief insere novo elemento na cauda da lista
/// \param list, lista a ser modificada
/// \param val, valor a ser inserido na lista
/// \return nova cabeça da lista
///
List *insertOnTail(List *list, ItemType val);

///
/// \brief função helper de insertOnTail
/// \param node, nó atual
/// \param newNode, nó a ser adicionado a lista
/// \return cabeça da lista
///
Node *insertNodeOnTail(Node *node, Node *newNode);

///
/// \brief remove todas ocorrências de um valor na lista
/// \param list, lista a ser manipulada
/// \param val, valor a ser removido
///
void removeNodes(List *list, ItemType val);

// HELPER FUNCTIONS //

///
/// \brief lê nova lista na entrada padrão
/// \return lista lida
///
List *readList();

///
/// \brief printa na saida padrão a lista encadeada
/// \param list, lista a ser printada
///
void printList(List *list);

///
/// \brief cria instância vazia de lista
/// \return memória inicializada para lista vazia
///
List *createList();

///
/// \brief cria instância de nó e atribui val
/// \param val, valor a ser atribuido
/// \return memória alocada para nó
///
Node *createNode(ItemType val);


#endif // LINKEDLIST

