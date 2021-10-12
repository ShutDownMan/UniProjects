#include <stdio.h>

void getValor(char *mensagem, int *n) {
	printf(mensagem);
	scanf("%ud", n);
}

unsigned int fatorial(unsigned int n) {
	unsigned int res = 1;

	for(int i = 1; i < n; ++i) {
		res = res * i;
	}
	return res;
}

int main(void)
{
	int n, fatValor;

	getValor("Digite o numero para executar a funcao fatorial: ", &n);

	if(n < 0) {
		printf("Valor digitado inválido!\n");
		return 1;
	}
	
	fatValor = fatorial(n);

	printf("%d! = %d\n", n, fatValor);

	return 0;
}
