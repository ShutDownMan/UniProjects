#include <stdio.h>
#include <math.h>

long long int fac(long long int x, long long int y);


int main ()
{
	long long int x, y;

	while(scanf("%lld %lld", &x, &y) != EOF)
	{
		long long int swap;

		if (x > y)
		{
			swap = x;
			x = y;
			y = swap;
		}
		printf("%lld\n", fac(1, x) + fac(1, y) );
	}
	return 0;
}


long long int fac(long long int x, long long int y)
{
	long long int fac = 1;
	if (x == 0)
	{
		x++;
	}
		for (int i = x; i <= y ; ++i)
	{
		fac *= i;
	}
	return fac;
}