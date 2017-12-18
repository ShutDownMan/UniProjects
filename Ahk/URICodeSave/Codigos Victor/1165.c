#include <stdio.h>
#include <math.h>
void checkPrime(int x);

int main()
{
	int n, i, x;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		checkPrime(x);
	}

	return 0;
}

void checkPrime(int x)
{
	int rootX, sum, j;
	sum=0;
	rootX = pow(x, 0.5);
	for (j = 2; j <= rootX; ++j)
	{
		if(x%j == 0) sum += j + x/j;
	}
	sum == 0 ? printf("%d eh primo\n",x) : printf("%d nao eh primo\n",x);
}