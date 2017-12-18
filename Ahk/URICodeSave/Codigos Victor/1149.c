#include <stdio.h>

int main()
{
	int  a, n, i, z=0;
	scanf("%d", &a);
	do	{
		scanf("%d", &n);	
	}while (n <= 0);
	
	for (i = 0; i<
		n; i++)
	{
		z += a;
		a++;
	}
	printf("%d\n",z);
	
	return 0;
}