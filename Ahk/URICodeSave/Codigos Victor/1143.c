#include <stdio.h>
#include <math.h>


int main ()
{
	int x, i;

	scanf("%d", &x);

	for ( i = 1; i <= x; ++i)
	{
		printf("%d %d %d\n", i, (int)pow(i, 2), (int)pow(i, 3) );
	}


	return 0;
}
