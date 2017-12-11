#include <stdio.h>

void foo(int x, int *quantD, int *quantSoma);

int main(int argc, char const *argv[]) {
	int x, quantD, quantSoma;

	do {
		scanf("%d", &x);

		foo(x, &quantD, &quantSoma);
		printf("%d %d\n", quantD, quantSoma);
	} while(x != 0);

	return 0;
}

void foo(int x, int *quantD, int *quantSoma) {
	int i;
	*quantD = 0; *quantSoma = 0;
	for (i = 0; x != 0; ++i) {
		*quantSoma += x%10;
		x /= 10;
	}

	*quantD = i;
}