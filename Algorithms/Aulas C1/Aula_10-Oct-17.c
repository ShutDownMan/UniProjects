#include <stdio.h>
#define MAX 256
//Tudo bem jedson vai dar tudo certo.
//programa q mostra a verdade para a vida universo e tudo.

int readvettxt(char filename[], int* length, int vet[]) {
	int i;
	FILE* vetfile = fopen(filename, "r");
	if(!vetfile) return 0;

	for (i = 0; fscanf(vetfile, "%d", &vet[i]) != EOF; ++i)
		;
	*length = i;

	fclose(vetfile);
	return 1;
}

int printvettxt(char filename[], int length, int vet[]) {
	int i;
	FILE* vetfile = fopen(filename, "w");
	if(!vetfile) return 0;

	for (i = 0; i < length; ++i) {
		fprintf(vetfile, "vet[%d] = %d\n", i, vet[i]);
	}
	
	fclose(vetfile);
	return 1;
}

int main(int argc, char const *argv[]) {
	int vet[MAX], length;

	readvettxt("in.txt", &length, vet);

	printvettxt("out.txt", length, vet);

	return 0;
}