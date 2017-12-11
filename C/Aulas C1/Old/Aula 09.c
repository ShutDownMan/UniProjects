#include <stdio.h>

void showDigits(int n) {
	int current;

	while(n != 0) {
		printf("Digit: %d\n", n %10);
		n /= 10;
	}
}

int contaDigits(int n) {
	int i, current;

	i = 1;
	while(n != 0) {
		printf("Digit %d is %d\n", i++, n %10);
		n /= 10;
	}

	return i;
}

int main(int argc, char const *argv[]) {
	int n;

	scanf("%d", &n);
	while(n != 0) {
		contaDigits(n);
		printf("-------\n");
		scanf("%d", &n);
	}
	
	return 0;
}