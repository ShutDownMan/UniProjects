#include <stdio.h>
#include <math.h>

int main ()
{
	int x, y=1;

	scanf("%d", &x);

	for (int i = 1; i <= x; ++i)
	{
		y *= i;
	}

	printf("%d\n",y );

	return 0;
}
