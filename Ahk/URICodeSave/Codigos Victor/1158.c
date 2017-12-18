#include <stdio.h>
#include <math.h>

int main()
{
	int n, y, x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;

		scanf("%d %d", &x, &y);

		for (int i = 0; i < 2*y; i++)
		{
			if (x%2!=0) sum+=x;
			x++;
		}
		printf("%d\n",sum );
	}
	return 0;
}