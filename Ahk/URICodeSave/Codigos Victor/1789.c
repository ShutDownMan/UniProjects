#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, i, cur, group = 1;
	while(scanf("%d", &n) != EOF)
	{
		group = 1;
		for ( i = 0; i < n; ++i)
		{
			scanf("%d", &cur);
			if (group != 3 && cur >= 10)	group = 2;
			if(cur >= 20)	group = 3;
		}
		printf("%d\n", group);
	}
	return 0;
}
