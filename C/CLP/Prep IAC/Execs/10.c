#include <stdio.h>

int contaDigitos(int n, int x) {
	int i, sum;

	for (sum = 0; x; x /= 10) {
		sum += (x%10 == n);
	}

	return sum;
}

int isPermutation(int x, int y) {
	int num;
	int aux, currentNum;

	for(aux = x; aux; aux /= 10) {
		currentNum = aux%10;
		if(contaDigitos(currentNum, x) != contaDigitos(currentNum, y)) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int cdt, x, y;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d %d", &x, &y);
		if(isPermutation(x, y)) {
			printf("0\n");
		} else {
			printf("1\n");
		}
	}

	return 0;
}