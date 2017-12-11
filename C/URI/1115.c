#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, y;

	do {
		scanf("%d %d", &x, &y);

		if(x > 0 && y > 0) printf("primeiro\n");
		if(x < 0 && y > 0) printf("segundo\n");
		if(x < 0 && y < 0) printf("terceiro\n");
		if(x > 0 && y < 0) printf("quarto\n");
	} while (x != 0 || y != 0);

	return 0;
}