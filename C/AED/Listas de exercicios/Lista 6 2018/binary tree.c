#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *left;
	struct node *right;
} Node;

int minimum(Node *node);
int maximum(Node *node);

Node *insert(Node *node, int val);
Node *removeNode(Node *node, int val);

void printTree(Node* node);

int somaMaiores(Node *node, int k);
int somaNoFilhoUnico(Node *node);

int main(void) {
	Node *head = NULL;

    head = insert(head, 11);
    head = insert(head, 5);
    head = insert(head, 2);
    head = insert(head, 8);
    head = insert(head, 14);
    head = insert(head, 22);
    head = insert(head, 15);
    head = insert(head, 1);

	printTree(head);
	printf("\n-------------\n");

	printf("Soma maior que (%d) = %d\n", 6, somaMaiores(head, 6));
	printf("Soma no com filho unico = %d\n", somaNoFilhoUnico(head));

//	printTree(head);
//	printf("\n-------------\n");

	return 0;
}

int minimum(Node *node) {
	if(!node) return -1;
	if(!node->left) return node->info;

	return minimum(node->left);
}

int maximum(Node *node) {
	if(!node) return -1;
	if(!node->right) return node->info;

	return maximum(node->right);
}

Node *createNode(int val) {
	Node *newNode = malloc(sizeof(Node));

	newNode->info = val;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Node *insert(Node *node, int val) {
	if(!node) return createNode(val);

	if(val < node->info) {
		if(!node->left) {
			node->left = createNode(val);
		} else {
			insert(node->left, val);
		}
	}
	if(val >= node->info) {
		if(!node->right) {
			node->right = createNode(val);
		} else {
			insert(node->right, val);
		}
	}

	return node;
}

Node *removeNode(Node *node, int val) {
	if(!node) return NULL;

	if(val < node->info)
		node->left = removeNode(node->left, val);
	else if(val > node->info)
		node->right = removeNode(node->right, val);
	else if(node->left) {
		node->info = maximum(node->left);
		node->left = removeNode(node->left, node->info);
	} else if(node->right) {
		node->info = minimum(node->right);
		node->right = removeNode(node->right, node->info);
	} else {
		free(node);
		node = NULL;
	}

	return node;
}

void printTree(Node* node) {
	printf("[");
	if(node){
		printf("%d, ", node->info);
		printTree(node->left);
		printf(", ");
		printTree(node->right);
	}
	printf("]");
}

int somaMaiores(Node *node, int k) {
	int soma = 0;

	if(!node) return 0;

	soma += somaMaiores(node->left, k);
	soma += somaMaiores(node->right, k);
	if(k < node->info) soma += node->info;

	return soma;
}

int somaNoFilhoUnico(Node *node) {
	int soma = 0;

	if(!node) return 0;

	soma += somaNoFilhoUnico(node->left);
	soma += somaNoFilhoUnico(node->right);
	if(!node->left ^ !node->right) soma += 1;

	return soma;
}