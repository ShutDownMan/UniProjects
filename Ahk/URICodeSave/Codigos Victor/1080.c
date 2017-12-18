#include <stdio.h>

int main ()
{
	int n = 0, j = 0;

	for (int i = 0; i < 100; ++i)
	{
		int num;

		scanf("%d", &num);

		(n < num) ? n = num, j = i+1 : n;

	}

	printf("%d\n%d\n",n, j );

    return 0;
}
