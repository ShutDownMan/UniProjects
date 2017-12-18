#include <stdio.h>
#include <math.h>
void printer(double x, double y);
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	printer(fmin(x, y), fmax(x, y));
	return 0;
}

void printer(double x, double y)
{
	int i;
    for( i=1+x; i<y; i++)
	{
		if (i%5 == 2 || i%5 == 3)
		{
			printf("%d\n",i);
		}
	}	
}