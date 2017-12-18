#include <stdio.h>
#include <math.h>

int main ()
{
	int i = 0;

	double start;

	scanf("%lf", &start);

	for ( ; i < 100; ++i)
	{
		printf("N[%d] = %.4lf\n", i, start);
		start /= 2;
	}

	return 0;
}
