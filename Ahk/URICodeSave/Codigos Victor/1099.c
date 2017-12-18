#include <stdio.h>
#include <math.h>

int main ()
{
	int n, x, y;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int swap, sum = 0;

		scanf("%d %d", &x, &y);

		x > y ? x, y : (swap = y, y = x, x = swap);

//		printf("x=%d y=%d swap=%d\n",x, y, swap);

		for (int n = y+1; n < x; ++n)
		{
			n%2 == 1 ? sum += n : sum;
		}
			printf("%d\n", sum);
	}
    return 0;
}
