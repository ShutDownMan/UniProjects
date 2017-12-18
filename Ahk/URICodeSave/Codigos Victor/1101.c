#include <stdio.h>
#include <math.h>

int main ()
{
	int n, x, y;

	scanf("%d %d", &x, &y);

	while( x>0 && y>0)
	{
		int swap, sum = 0;


		x > y ? x, y : (swap = y, y = x, x = swap);

//		printf("x=%d y=%d swap=%d\n",x, y, swap);

		for (int n = y; n <= x; ++n)
		{
			sum += n;
			printf("%d ",n );
		}
			printf("Sum=%d\n", sum);

			scanf("%d %d", &x, &y);
	}
    return 0;
}
