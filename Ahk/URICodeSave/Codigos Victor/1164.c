#include <stdio.h>
#include <math.h>
void checkPerf(int x);

int main()
{
	int n, i, x;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		checkPerf(x);
	}

	return 0;
}

void checkPerf(int x)
{
	int rootX, sum, j;
	sum=1;
	rootX = pow(x, 0.5);
	for (j = 2; j <= rootX; ++j)
	{
		if(x%j == 0) sum += j + x/j;
	}
	x == sum && x != 1 ? printf("%d eh perfeito\n",x) : printf("%d nao eh perfeito\n",x);
}