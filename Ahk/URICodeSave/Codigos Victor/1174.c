#include <stdio.h>

int main()
{
	double n[100];
	int i;
	for ( i = 0; i < 100; ++i)
	{
		scanf("%lf", &n[i]);
		if(n[i]<=10) printf("A[%d] = %.1lf\n", i, n[i]);
	}
    return 0;
}