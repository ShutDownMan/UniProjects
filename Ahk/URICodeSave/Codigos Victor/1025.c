#include <stdio.h>
#include <math.h>

void find(int *val, int *lookFor, int marb, int quest);

int main()
{
	int marb, quest, count = 1;

	scanf("%d %d", &marb, &quest );

	while(marb != 0 && quest != 0 )
	{
		int val[marb] , lookFor[quest], i;

		for ( i = 0; i < marb; ++i)
		{
			scanf("%d", &val[i]);
			int j;
			j = i;
			while (val[j] < val[j-1] && j != 0)
			{
				int temp = val[j];
				val[j] = val[j-1];
				val[j-1] = temp;
				j--;
			}
		}

		for ( i = 0; i < quest; ++i)
		{
			scanf("%d", &lookFor[i]);
		}

		printf("CASE# %d:\n", count );

		find(val, lookFor, marb, quest);

		scanf("%d %d", &marb, &quest );

		count++;
	}
	return 0;
}

void find(int *val, int *lookFor, int marb, int quest)
{
	int i, j, notFound;

	for (i = 0; i < quest; ++i)
	{
		for (j =0, notFound = 1 ; j < marb; ++j)
		{
			if (val[j] == lookFor[i])
			{
				printf("%d found at %d\n", lookFor[i], j+1);
				notFound = 0;
				break;
			}
		}
		if(notFound)
		{
			printf("%d not found\n", lookFor[i] );
		}
	}
}
