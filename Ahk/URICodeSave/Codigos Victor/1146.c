#include <stdio.h>

int main ()
{
	int x=1, i;
	
	while( x != 0)
	{	
	scanf("%d", &x);
		for(i=1; i<=x; i++)
		{
			i%x != 0 ? printf("%d ",i ) : printf("%d\n", i);
		}
	}
	return 0;
}