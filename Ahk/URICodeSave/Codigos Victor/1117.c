#include <stdio.h>

double x, y, val = 0;

int main ()
{
	while(val<2)
	{
		scanf("%lf", &y);

		y>=0 && y<=10 ? (val++, x += y ) : printf("nota invalida\n");

		if (val == 2)
			printf("media = %.2lf\n", x/2);
	}
	return 0;
}