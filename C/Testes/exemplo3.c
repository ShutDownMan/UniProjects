#include <stdio.h>

int main() {

	int x, y = 15;

	printf("Valor de x: ");
	scanf("%d", &x); // Leitura de valor int. Usa-se & em variáveis passadas por referência.
	
	printf("Valor de y: ");
	scanf("%d", &y);

	printf("Valor de x = %d, valor de y = %d.\n", x, y);

}