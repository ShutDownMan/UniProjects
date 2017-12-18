#include <stdio.h>

int main (){

	int sorted[3], unsorted[3], i, n;

	for (i=0; i < 3; ++i)
	{
		scanf(" %d", &unsorted[i]);

		sorted[i] = unsorted[i];
	}

	for ( n=0; n < 3; ++n)
	{
		for (i=0; i < 2; ++i)
		{
			while(sorted[i]>sorted[i+1])
			{
				int swap;

				swap = sorted[i];

				sorted[i] = sorted[1+i];

				sorted[i+1] = swap;
			}
		}
	}

	for (i=0; i < 3; ++i)
	{
		printf("%d\n", sorted[i] );
	}

	printf("\n");

	for ( i = 0; i < 3; ++i)
	{
		printf("%d\n", unsorted[i]);
	}
	return 0;
}