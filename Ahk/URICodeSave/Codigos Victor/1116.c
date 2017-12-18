#include <stdio.h>



int main ()
{
    double x, y, n;
    
    int i;
    
	scanf("%lf", &n);

	for ( i = 0; i < n; ++i)
	{
		scanf("%lf%lf", &x, &y);

		y != 0 ? printf("%.1lf\n", x/y) : printf("divisao impossivel\n");;
	}
	return 0;
}