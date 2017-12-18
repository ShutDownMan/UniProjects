#include <stdio.h>
#include <math.h>

int main ()
{
	int i = 0, odd[5], even[5], oddCount = 0, evenCount = 0, current, j;

	for ( i = 0; i < 15; ++i)
	{
		scanf("%d", &current);
		if (current %2)
		{
			odd[oddCount] = current;
			oddCount++;
		}else
		{
			even[evenCount] = current;
			evenCount++;
		}
		if(oddCount == 5)
		{
			for (j = 0; j < 5; ++j)
			{
				printf("impar[%d] = %d\n", j, odd[j]);
			}
			oddCount = 0;
		}
		if (evenCount == 5)
		{
			for (j = 0; j < 5; ++j)
			{
				printf("par[%d] = %d\n", j, even[j]);
				evenCount = 0;
			}
		}
	}
	for ( j = 0; j < oddCount; ++j)	printf("impar[%d] = %d\n", j, odd[j]);
	for ( j = 0; j < evenCount; ++j)	printf("par[%d] = %d\n", j, even[j]);

	return 0;
}
