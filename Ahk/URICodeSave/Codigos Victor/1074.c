#include <stdio.h>
#include <math.h>

int main (){

	int n=0, x=0, i=0;

	scanf("%d", &n);

	for ( i=1; i<=n; i++)
	{
		scanf("%d", &x);

		if (x==0)
		{
			printf("NULL\n");
		}

		else
		{
			if (x%2 == 0)
			{
				printf("EVEN ");
			}
			else
			{
				printf("ODD ");
			}
			if (x>0)
			{
				printf("POSITIVE\n");
			}
			else
			{
				printf("NEGATIVE\n");
			}
		}
	}

    return 0;
}