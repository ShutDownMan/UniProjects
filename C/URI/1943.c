#include <stdio.h>

int main(int argc, char const *argv[]) {
	int tops[7] = {1, 3, 5, 10, 25, 50, 100};
	int pos, i;

	scanf("%d", &pos);

	for (i = 6; i > 0 && tops[i] >= pos; --i)
		;

	if(pos == 1) i = 0;

	printf("Top %d\n", tops[i+1]);

	return 0;
}