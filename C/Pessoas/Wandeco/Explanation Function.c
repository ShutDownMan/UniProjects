#include <stdio.h>

int f(int x) {
    return 2*x + 5;
}

int main(void) {
	int x;

	scanf("%d", &x);

	printf("%d\n", f(x));

	return 0;
}