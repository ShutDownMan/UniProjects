#include <stdio.h>

int main() {

	int a, b, operador;

	printf("Valor de a: ");
	scanf("%d", &a);

	printf("Valor de b: ");
	scanf("%d", &b);

	printf("Operador [1 = '+', 2 = '-', 3 = '*', 4 = '/']: ");
	scanf("%d", &operador);

	switch (operador) {
		case 1:
			printf("Resultado: %d\n", a + b);
		break;
		case 2:
			printf("Resultado: %d\n", a - b);
		break;
		case 3:
			printf("Resultado: %d\n", a * b);
		break;
		case 4:
			printf("Resultado: %d\n", a / b); // Divisão inteira, não tem casas decimais.
		break;
	}

}