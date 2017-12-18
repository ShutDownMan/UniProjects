#include <stdio.h>
#include <math.h>

int main (){

	int n=0, x=0, count = 0, i=0;

	scanf("%d", &n);

	for ( i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		if (10 <= x && 20 >= x)
		{
			count++;
		}

	}

	printf("%d in\n%d out\n",count, n-count);

    return 0;
}

