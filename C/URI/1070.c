#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, i;

	scanf("%d", &x);

	for (i = 0; i < 12; ++i)
	{
		if((x+i) %2 != 0) {
			printf("%d\n", x+i);
		}
	}
	return 0;
}