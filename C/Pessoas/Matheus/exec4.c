#include <stdio.h>

void printaLinha(int n, char c) {
	int i;

	for(i = 0; i < n; ++i) {
		printf("%c", c);
	}
}

void desenhaTriangulo(int linhas, char c) {
	int i;

	for(i = 1; i <= linhas; ++i) {
		/// printa i caracteres na linha
		printaLinha(i, c);
		printf("\n");
	}
}

int main(void) {
	int linhas;
	char c;

	scanf("%d %c", &linhas, &c);
	while(linhas != -1) {
		desenhaTriangulo(linhas, c);

		scanf("%d %c", &linhas, &c);
	}

	return 0;
}