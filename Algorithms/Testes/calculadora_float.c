#include <stdio.h>

int main() {

	float a, b; // Valores reais.
	int operador;

	printf("Valor de a: ");
	scanf("%f", &a); // Assim como %d indica inteiro, %f indica float.

	printf("Valor de b: ");
	scanf("%f", &b);

	printf("Operador [1 = '+', 2 = '-', 3 = '*', 4 = '/']: ");
	scanf("%d", &operador);

	switch (operador) {
		case 1:
			printf("Resultado: %f\n", a + b);
		break;
		case 2:
			printf("Resultado: %f\n", a - b);
		break;
		case 3:
			printf("Resultado: %f\n", a * b);
		break;
		case 4:
			printf("Resultado: %f\n", a / b);
		break;
	}

	while(1){
		malloc()
	}

}