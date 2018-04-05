#include <stdio.h>

int main(int argc, char const *argv[]) {
	int res, aux;

	res = aux = 0;

	scanf("%d", &aux);
	res += aux;
	scanf("%d", &aux);
	res += aux;
	scanf("%d", &aux);
	res += aux;
	scanf("%d", &aux);
	res += aux;

	res -= 3;

	printf("%d\n", res);

	return 0;
}