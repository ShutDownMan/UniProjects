#include <stdio.h>

int main() {

	int x, y, i;
	printf("Valor de x: ");
	scanf("%d", &x);
	
	y = 1;
	for (i=2; i<=x; i++) {
		y = y*i;
	}

	printf("Fatorial de x = %d\n", y);

}