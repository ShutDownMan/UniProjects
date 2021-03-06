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
/// Pré-condição: cabeça da lista não pode estar nula
/// Pós-condição: insere valor na lista
List* insert(List* list, int val);

/// Entrada: lista encadeada, valor inteiro
/// Pré-condição: nenhuma
/// Pós-condição: remove valor da lista se este for encontrado
List* remove(List* list, int val);

/// Entrada: lista encadeada
/// Pré-condição: cabeça da lista não pode estar nula
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
/// Pós-condição: conta numero de duplicatas do inteiro na lista
int countDupes(List* list, int val);

/// Entrada: uma lista
/// Pré-condição: nenhuma
/// Pós-condição: limpa a lista de duplicatas
List* removeDupes(List* list);

// HELPERS //

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
List* cpyList(List *list);

/// Entrada: uma lista e um inteiro val
/// Pré-condição: nenhuma
/// Pós-condição: traversa lista e checka pelo inteiro val
int contains(List *list, int val);

/// Entrada: uma lista
/// Pré-condição: nenhuma
/// Pós-condição: libera a memória de todos os nós alocados em uma lista
void removeList(List *list);

#endif // LINKEDLIST_H
