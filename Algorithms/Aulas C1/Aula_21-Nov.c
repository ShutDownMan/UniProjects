#include <stdio.h>
#include <stdlib.h>

typedef struct tdata {
	int dia, mes, ano;
} TData;

void structMalloc(void) {
	TData *data1, *data2;

	// Aloca
	data1 = malloc(sizeof(TData));
	data2 = data1;

	// Usa
	{
		data1->dia = 30;
		data2->dia = 20;
		
		printf("%d\n", data1->dia);
	}

	// Libera
	free(data1);
}

void mallocNInt(void) {
	int *v, n, i;

	scanf("%d", &n);

	v = malloc(n*sizeof(int));

	for (i = 0; i < n; ++i) {
		// *(v+i) = 0;
		v[i] = 0;	
	}

	free(v);
}

int main(int argc, char const *argv[]) {

	structMalloc();

	mallocNInt();

	return 0;
}