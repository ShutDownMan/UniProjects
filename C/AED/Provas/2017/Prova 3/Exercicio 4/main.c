#include <stdio.h>

#define ORDER 5

struct node {
	int numKeys;
	int keys[ORDER-1];
	struct node* children[ORDER];
};

typedef struct node* BTree;

int contaNosMinChaves(BTree t) {
	int i, sum;

	if(!t) return 0;

	for(i = sum = 0; i <= t->numKeys; ++i) {
		sum += contaNosMinChaves(t->children[i]);
	}

	if(t->numKeys == ORDER/2) ++sum;

	return sum;
}

void printBTree(BTree t) {
	int i;

	if(!t) return;

	for(i = 0; i < t->numKeys; ++i) {
		printBTree(t->children[i]);
		printf("%d ", t->keys[i]);
	}
	printBTree(t->children[ORDER-1]);
}

void imprimirMaiores(BTree t, int k) {
	int i;

	if(!t) return;

	for(i = 0; i < t->numKeys; ++i) {
		if(k < t->keys[i]) {
			printBTree(t->children[i]);
			printf("%d ", t->keys[i]);
		}
	}

	imprimirMaiores(t->children[ORDER-1], k);
	printf("\n");
}

int main(int argc, char const *argv[]) {
	
	return 0;
}