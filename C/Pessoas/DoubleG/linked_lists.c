#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *create_node(int n);

Node *insert_head(Node *a, int n);

void print_list(Node *a);

void free_list(Node *a);

int swap(Node **a, int ind1, int ind2);

int main(void)
{
    Node *firstNode = NULL;

    firstNode = insert_head(firstNode, 10);
    firstNode = insert_head(firstNode, 26);
    firstNode = insert_head(firstNode, -1);
    firstNode = insert_head(firstNode, 15);
    firstNode = insert_head(firstNode, 4);
    firstNode = insert_head(firstNode, 33);
    firstNode = insert_head(firstNode, 84);
    firstNode = insert_head(firstNode, 5);
    firstNode = insert_head(firstNode, 8);
    firstNode = insert_head(firstNode, 7);

    print_list(firstNode);

    swap(&firstNode, 1, 8);

    print_list(firstNode);

    free_list(firstNode);

    return 0;
}

Node *create_node(int n) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = n;
    new_node->next = NULL;
    return new_node;
}

Node *insert_head(Node *a, int n) {
    Node *new_node = create_node(n);

    if(a == NULL) {
        return new_node;
    }

    new_node->next = a;

    return new_node;
}

void print_list(Node *a) {
    Node *aux = a;

    while(aux != NULL) {
        printf("(%d)->", aux->value);
        aux = aux->next;
    }
    printf("(//)\n");
}

void free_list(Node *a) {
    Node *aux = a;
    Node *next = NULL;

    while(aux != NULL) {
        next = aux->next;
        free(aux);
        aux = next;
    }
}

int swap(Node **a, int ind1, int ind2) {
    Node *first = *a;
    Node *second = NULL;
    Node *prev_second = NULL;
    int i = 1;
    
    /// list is empty
    if((*a) == NULL)
        return 0;

    /// indices are wrong
    if(ind1 >= ind2)
        return 0;

    /// finding the position of the first node
    for(; i < ind1 && first != NULL; i++) {
        first = first->next;
    }

    /// index is wrong, first node is null
    if(first == NULL)
        return 0;

    /// the first possible swaping pair
    prev_second = first;
    second = first->next;

    /// finding the position of the second node
    for(++i; i < ind2 && second != NULL; i++) {
        prev_second = second;
        second = second->next;
    }

    /// if we messed with the head
    if(first == *a) {
        /// swapty swap
        Node *next_one = second->next;
        prev_second->next = first;
        second->next = first->next;
        first->next = next_one;

        /// update head to second pointer
        (*a) = second;
    } else {
        
    }
    
    return 1;
}