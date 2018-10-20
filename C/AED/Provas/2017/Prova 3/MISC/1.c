#include <stdio.h>

#define ORDER 5

struct node {
	int numKeys;
	int keys[ORDER-1];
	struct node* children[ORDER];
};

typedef struct node* BTree;

int maximo(BTree r) {
	int result = -1;
	struct node *aux = r;

	if(!r) return -1;

	if(r->numKeys) {
		while(aux->children[aux->numKeys]) {
			aux = aux->children[aux->numKeys];
		}
		result = aux->keys[aux->numKeys-1];
	}

	return result;
}

int minimo(arvoreB *r) {
    int resultado = -1;
    arvoreB* aux = r;

    if(r->numChaves){
        while(aux->filho[0]) aux = aux->filho[0];

        resultado = aux->chave[0];
    }

    return resultado;
}

int main(int argc, char const *argv[]) {

	return 0;
}