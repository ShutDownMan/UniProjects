#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, i;

	scanf("%d", &n);

	for (i = 2; i <= n; ++i)
	{
		if(i %2 == 0) {
			printf("%d^2 = %d\n", i, i*i);
		}
	}
	return 0;
}