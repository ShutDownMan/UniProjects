#include <stdio.h>

int main()
{
	int cases, r1, r2, i;
	scanf("%d", &cases);
	for (i = 0; i < cases; ++i)
	{
		scanf("%d %d", &r1, &r2);
		printf("%d\n",r2 + r1 );
	}
	return 0;
}