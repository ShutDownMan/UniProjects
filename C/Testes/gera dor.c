#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

	srand(time(NULL));

	int r = 1000;

	printf("%d",r );

	for (int j = 0; j < r; ++j)
	{
		printf("\n");
		int n = rand() %96 +4;
		printf("%d", n);

		printf(" %d",rand() %10 +1);
		printf(" %d",rand() %50 +1);
		
		printf("\n");
		for (int i = 0; i < n; ++i)
		{
			printf(" %d",rand() %100 +1 );
		}
	}

	return 0;
}