#include <stdio.h>

int main()
{
	unsigned long long int years;
	int cases, ii;

	scanf("%d", &cases);

	for (ii = 0; ii < cases; ++ii)
	{
		scanf("%llu", &years);
		(years<2015) ? printf("%llu D.C.\n",2015-years) : printf("%llu A.C.\n", years-2014 );
	}
}