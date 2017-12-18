#include <stdio.h>

int main ()
{
	int x, i, tests, n;

	scanf("%d", &tests);

	double a[61], temp;
	a[0] = 0;
	a[1] = 1;

	for ( i = 2; i < 61; ++i)  a[i] = a[i-1] + a[i-2];

	for ( i = 0; i < tests; ++i)
	{
		scanf("%d", &x);
		printf("Fib(%d) = %.0lf\n", x, a[x]);
	}

	return 0;
}
