#include <stdio.h>

int power(int base, int exp) {
	if(!exp)
		return 1;
	if(exp == 1)
		return base;
	if(exp%2)
		return base * power(base, exp - 1);

	return power(base, exp - 1) * power(base, exp - 1);
}

int main(void) {
	int k, n;

	scanf("%d%d", &k, &n);

	printf("k^n = %d\n", power(k, n));

	return 0;
}