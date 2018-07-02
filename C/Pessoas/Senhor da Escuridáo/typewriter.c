#include <stdio.h>
#include <windows.h>

#define MAX 1024

void printaBonito(char str[]) {
	int i;
	for(i = 0; str[i]; ++i) {
		printf("%c", str[i]);
		Sleep(75);
	}
}

int main(void) {
	char nome[MAX];

	printaBonito("digite seu nome: ");
	scanf("%[^\n]%*c", nome);
	printaBonito("Ola, tudo bem com vc ");
	printaBonito(nome);
	printaBonito("?\n");

	return 0;
}