#include <stdio.h>

int main(int argc, char const *argv[]) {
	int n, i;
	int first, second, next;

	scanf("%d", &n);

	// Inicializa o primeiro e o segundo N de Fib
	first = 0;
	second = 1;

	// Printa os n primeiros Ns de Fib
	for (i = 0; i < n; ++i) {
		// Gambiarra pra printar certo no URI
		if(i < n-1) {
			printf("%d ", first);
		} else {
			printf("%d\n", first);
			break;
		}

		// Calcula o proximo n Fib
		next = first + second;
		// Prepara para o proximo loop
		first = second;
		second = next;
	}

	return 0;
}