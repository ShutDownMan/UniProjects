#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readNames(char fileName[], int *length) {
	FILE *f = fopen(fileName, "r+");
	int i, maxLength;
	char **newVet;
	char str[256];

	maxLength = 2;
	newVet = (char **)malloc(sizeof(char *) * maxLength);

	for(i = 0; !feof(f); ++i) {
		if(i+1 > maxLength) {
			maxLength *= 2;
			newVet = (char **)realloc(newVet, sizeof(char *) * maxLength);
		}
		fscanf(f, " %[^\n]%*c", str);
		newVet[i] = strcpy(malloc(sizeof(char) * strlen(str) + 1), str);
	}

	maxLength = i;
	newVet = (char **)realloc(newVet, sizeof(char *) * maxLength);

	*length = maxLength;
	return newVet;
}

void shuffle(char **vet, int length) {
	int i, randInd;
	char *aux;

	for(i = 0; i < length; ++i) {
		randInd = rand() % length;
		aux = vet[i]; vet[i] = vet[randInd]; vet[randInd] = aux;
	}
}

void printNames(char fileName[], char **vet, int length) {
	FILE *f = fopen(fileName, "w+");
	int i;

	for(i = 0; i < length; ++i) {
		fprintf(f, "%s\n", vet[i]);
	}
}

int main(int argc, char const *argv[]) {
	char **names;
	int length;

	names = readNames("first-names.txt", &length);

	shuffle(names, length);

	printNames("unsorted-names.txt", names, length);

	return 0;
}