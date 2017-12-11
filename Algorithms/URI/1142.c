#include <stdio.h>

int main()
{
	int iteration, n;

	scanf("%d", &iteration);

	for (int i = 0; i < iteration; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (j < 3)
			{
				printf("%d ", n + 1);
			}
			else
			{
				printf("PUM\n");
			}
			n ++;

		}
	}

	return 0;

}