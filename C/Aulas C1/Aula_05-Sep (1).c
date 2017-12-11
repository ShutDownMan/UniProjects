#include <stdio.h>

int main(int argc, char const *argv[])
{
	int curr, ant;

	scanf("%d %d", &ant, &curr);

	while(curr != 0) {
		printf("%d\n", curr == ant);
		ant = curr;
		scanf("%d", &curr);
	}
	return 0;
}