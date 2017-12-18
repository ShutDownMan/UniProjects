#include <stdio.h>

int main ()
{
	double a, b, c;

	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
    scanf( "%lf%lf%lf", &a, &b, &c);

    printf( "%.1lf\n", (a * 2 + b * 3 + c * 5 ) / 10);
	}
    return 0;
}
