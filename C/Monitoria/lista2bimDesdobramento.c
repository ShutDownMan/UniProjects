#include <stdio.h>

/// 1.
int contaDigitos(int n, int x) {
	int i, sum;

	for (sum = 0; x; x /= 10) {
		sum += (x%10 == n);
	}

	return sum;
}

int isPermutation(int x, int y) {
	int aux, currentNum;

	for(aux = x; aux; aux /= 10) {
		currentNum = aux%10;
		if(contaDigitos(currentNum, x) != contaDigitos(currentNum, y)) {
			return 0;
		}
	}

	return 1;
}

void getIfPermutation() {
	int x, y;

	scanf("%d %d", &x, &y);
	printf("%s\n", isPermutation(x, y) ? "Sim" : "Nao");
}

/// 2.
void drawLine(int n, char c) {
	int i;

	for (i = 0; i < n; ++i) {
		printf("%c ", c);
	}
}

void drawArrow() {
	int i, n;
	char c;

	scanf("%d %c", &n, &c);
	for(i = 0; i <= n; ++i) {
		drawLine(i, c);
		printf("\n");
	}
	for(i = n-1; i > 0; --i) {
		drawLine(i, c);
		printf("\n");
	}
}


int main(int argc, char const *argv[]) {

	/// 1.
//	getIfPermutation();

	/// 2.
//	drawArrow();

	/// 3.

	return 0;
}