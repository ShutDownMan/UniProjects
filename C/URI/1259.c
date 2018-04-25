#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
} Node;

Node *createNode(int val) {
	Node *newNode = malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

Node *insert(Node *node, int val) {
	Node *aux;

	if(!node) return createNode(val);

	if(!node->next || node->next->val > val) {

		if(node->val > val) {
			aux = createNode(val);
			aux->next = node;
			return aux;
		}

		aux = node->next;
		node->next = createNode(val);
		node->next->next = aux;
	} else {
		insert(node->next, val);
	}

	return node;
}

void printList(Node *node) {
	Node **tracer;

	for(tracer = &node; *tracer; tracer = &(*tracer)->next) {
		printf("%d\n", (*tracer)->val);
	}
}

void printListRev(Node *node) {
	if(!node) return;

	printListRev(node->next);
	printf("%d\n", node->val);
}

int main(int argc, char const *argv[]) {
	int inputQnt, inputNum;
	Node *par, *imp;

	par = imp = NULL;

	scanf("%d", &inputQnt);
	while(inputQnt--) {
		scanf("%d", &inputNum);
		if(inputNum%2) {
			imp = insert(imp, inputNum);
		} else {
			par = insert(par, inputNum);
		}
	}

	printList(par);
	printListRev(imp);

	return 0;
}