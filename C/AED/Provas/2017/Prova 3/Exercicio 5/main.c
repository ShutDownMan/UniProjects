#include <stdio.h>

#define ORDER 5

struct node {
	void *children[ORDER];
	int keys[ORDER-1];
	int isLeaf, numKeys;
};

typedef struct node* BPlusTree;

int contarFolhas(BPlusTree r) {
	int result = 0;
	void *aux = r;

	if(!r) return 0;

	while(!aux->isLeaf) aux = aux->children[0];

	while(aux) {
		result++;
		aux = aux->children[ORDER-1];
	}

	return result;
}

int main(int argc, char const *argv[]) {

	return 0;
}