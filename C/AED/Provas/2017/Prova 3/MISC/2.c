#include <stdio.h>
#include <math.h>

int getHeight(Node *node) {
	if(!node) return 0;

	return fmax(getHeight(node->right), getHeight(node->left)) + 1;
}

void printLevel(Node *node, int level) {
	if(!node) return;

	if(!level) {
		printf("%d ", node->value);
	} else {
		printLevel(node->left, level-1);
		printLevel(node->right, level-1);
	}
}

void printLevels(Node *node) {
	int i;

	if(!node) return;

	for(i = 0; i < getHeight(node); ++i) {
		printLevel(node, i);
		printf("\n");
	}
}

int main(int argc, char const *argv[]) {

	printLevels();

	return 0;
}