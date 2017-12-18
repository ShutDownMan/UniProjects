#include <stdio.h>
#include <math.h>

int main()
{
	int width, length, perc, aux;
	while(scanf("%d %d %d", &width, &length, &perc) == 3)
	{
		printf("%d\n",(int)sqrt(width * length * (100.0 / perc)));
	}
	return 0;
}