#include <stdio.h>

int main()
{
	int  a, n, i=0, z=0;
	scanf("%d", &a);
	do	{
		scanf("%d", &n);	
	}while (n <= a);
	
	while (z<n)
	{
		z += a;
		a++;
		i++;
	}
	printf("%d\n",i);
	
	return 0;
}