#include <stdio.h>

int main(int argc, char const *argv[]) {
	int n;

	scanf("%d", &n);
	while(n != 2002) {
		puts("Senha Invalida");
		scanf("%d", &n);
	}
	puts("Acesso Permitido");

	return 0;
}