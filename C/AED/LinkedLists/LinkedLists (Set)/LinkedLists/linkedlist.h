#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct knot {
    int val;
    struct knot* next;
} List;

/// Entrada: lista encadeada
/// Pré-condição: nenhuma
/// Pós-condição: retorna se listá é vazia
int isEmpty(List* head);

/// Entrada: lista encadeada, valor inteiro
/// Pré-condição: nenhuma
/// Pós-condição: insere valor na lista
List* insert(List **list, int val);

/// Entrada: lista encadeada, valor inteiro
/// Pré-condição: nenhuma
/// Pós-condição: remove valor da lista se este for encontrado
List* remove(List **list, int val);

/// Entrada: lista encadeada
/// Pré-condição: nenhuma
/// Pós-condição: printa na saida padrão a lista encadeada
void printList(List *head);

/// Entrada: lista encadeada
/// Pré-condição: nenhuma
/// Pós-condição: inverte a lista
List* invert(List* list);

/// Entrada: duas listas encadeadas
/// Pré-condição: nenhuma
/// Pós-condição: concatena valores de ambas
List* concat(List* list1, List* list2);

/// Entrada: duas listas encadeadas
/// Pré-condição: nenhuma
/// Pós-condição: intercala as duas listas
List* merge(List* list1, List* list2);

/// Entrada: duas listas encadeadas
/// Pré-condição: nenhuma
/// Pós-condição: concatena l2 no final de l1 e retorna l1 modicada
List* append(List *list1, List *list2);

/// Entrada: uma lista e um inteiro
/// Pré-condição: nenhuma
/// Pós-condição: itera sobre a lista e checka pela presença de val
int contains(List* list, int val);

/// Entrada: duas listas
/// Pré-condição: nenhuma
/// Pós-condição: retorna a união de duas listas encadeadas sem duplicadas
List *unionSet(List *list1, List *list2);

/// Entrada: duas listas
/// Pré-condição: nenhuma
/// Pós-condição: retorna a interseção de duas listas encadeadas
List *IntersectionSet(List *list1, List *list2);

/// Entrada: duas listas
/// Pré-condição: nenhuma
/// Pós-condição: retorna a diferença de duas listas encadeadas
List *differenceSet(List *list1, List *list2);

/// Entrada: duas listas
/// Pré-condição: nenhuma
/// Pós-condição: retorna se a primeira lista está contida na segunda
int isContained(List *list1, List *list2);

// HELPER FUNCTIONS //

/// Entrada: duas listas encadeadas
/// Pré-condição: nenhuma
/// Pós-condição: função auxiliar para criação de uma lista encadeada
void createLinkedList(List **head);

/// Entrada: um valor inteiro
/// Pré-condição: nenhuma
/// Pós-condição: aloca e retorna um novo nó
List* createKnot(int val);

/// Entrada: um nó
/// Pré-condição: nenhuma
/// Pós-condição: aloca e retorna uma cópia de nó
List* cpyKnot(List *list);

/// Entrada: uma lista
/// Pré-condição: nenhuma
/// Pós-condição: aloca e retorna uma cópia de uma lista
List* cpyList(List* list);

/// Entrada: uma lista
/// Pré-condição: nenhuma
/// Pós-condição: libera a memória de todos os nós alocados em uma lista
void removeList(List *list);

/// Entrada: uma lista
/// Pré-condição: nenhuma
/// Pós-condição: limpa a lista de duplicatas
List* removeDupes(List* list);

#endif // LINKEDLIST_H
