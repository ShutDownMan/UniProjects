#include <stdio.h>
#include <math.h>

int main()
{
	int n, x;

	do
	{
		int sum = 0;

		scanf("%d", &x);

		if(x==0) break;

		for (int i = 0; i < 10; i++)
		{
			if (x%2==0) sum+=x;
			x++;
		}

		printf("%d\n",sum );
	}while(1);
	return 0;
}