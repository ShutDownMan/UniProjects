#include <stdio.h>

int main() {
	int inputVal, i;

	int notas[7] = { 1, 2, 5, 10, 20, 50, 100 };

	scanf("%d", &inputVal);

	for(i = 6; i >= 0; --i) {
		printf("%d nota(s) de R$ %d,00\n", inputVal/notas[i], notas[i]);
		inputVal %= notas[i];
	}

	return 0;
}