#include <stdio.h>

int abs(int n) {
	return (n < 0) ? -n : n;
}

int test(int a, int b, int c) {
	return ((abs(b-c) < a) && (a < b+c)
		&& (abs(a-c) < b) && (b < a+c)
		&& (abs(a-b) < c) && (c < a+b));
}

int main(int argc, char const *argv[]) {
	int a, b, c, d;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	if(test(a, b, c) || test(a, b, d) || test(a, c, d) || test(b, c, d)) {
		printf("S\n");
	} else {
		printf("N\n");
	}

	return 0;
}