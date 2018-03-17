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
/// Pós-condição: função auxiliar para criação de uma lista encadeada
void createLinkedList(List **head);

/// Entrada: um valor inteiro
/// Pré-condição: nenhuma
/// Pós-condição: aloca e retorna um novo nó
List* createKnot(int val);

#endif // LINKEDLIST_H
