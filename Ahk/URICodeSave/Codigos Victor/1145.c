#include <stdio.h>


int main ()
{
	int x, y, i;

	scanf("%d %d", &x, &y);

	for (int i = 1; i <= y; ++i)
	{
		i%x != 0 ? printf("%d ",i ) : printf("%d\n", i);
	}
	if (y%x != 0)printf("\n");

	return 0;
}
