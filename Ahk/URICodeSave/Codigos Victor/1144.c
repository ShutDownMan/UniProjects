#include <stdio.h>
#include <math.h>


int main ()
{
	int x;

	scanf("%d", &x);

	for (int i = 1; i <= x; ++i)
	{
		printf("%d %d %d\n", i, (int)pow(i, 2), (int)pow(i, 3) );

		printf("%d %d %d\n", i, (int)pow(i, 2)+1, (int)pow(i, 3)+1 );
	}


	return 0;
}
