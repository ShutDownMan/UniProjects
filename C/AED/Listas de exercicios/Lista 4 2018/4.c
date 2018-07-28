#include <stdio.h>
#include <stdlib.h>

#define MAXNUMBER 500

typedef struct node {
	int info;
	struct node *next;
	struct node *prev;
} Node;

Node *createNode(int info) {
	Node *newNode = malloc(sizeof(Node));

	newNode->info = info;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void insertOnHead(Node **listHead, int info) {
	Node *newNode = createNode(info);

	newNode->next = *listHead;
	if(*listHead)
		(*listHead)->prev = newNode;
	*listHead = newNode;
}

void readList(Node **listHead) {
	int i, num;

	for(i = 0; i < MAXNUMBER; ++i) {
		scanf("%d", &num);
		insertOnHead(listHead, num);
	}
}

void printList(Node *listHead) {
	Node *tracer;

	for(tracer = listHead; tracer; tracer = tracer->next) {
		printf("%d\n", tracer->info);
	}
}

void insertionSort(Node **listHead) {
	Node *key = NULL;
	Node *tracer, *next;
	int foundMin;

	if(!(*listHead)) return;

	for(key = (*listHead)->next; key; key = next) {
		next = key->next;
		foundMin = 0;
		/// search for lower num
		for(tracer = key->prev; tracer && !(foundMin = (key->info > tracer->info)); tracer = tracer->prev)
			;

		/// Disconnecting from prev position
		if(key->next)
			key->next->prev = key->prev;
		key->prev->next = key->next;

		/// did not find lower num
		if(!foundMin) {
			/// insert on head
			key->next = *listHead;
			key->prev = NULL;
			(*listHead)->prev = key;
			*listHead = key;
		} else {
			/// adding to new position
			key->next = tracer->next;
			key->prev = tracer;

			if(key->next)
				key->next->prev = key;
			tracer->next = key;
		}
	}

}

int main(void) {
	Node *listHead = NULL;

	readList(&listHead);
	insertionSort(&listHead);
	printList(listHead);

	return 0;
}