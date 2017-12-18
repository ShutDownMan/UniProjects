#include <stdio.h>
#include <math.h>

int main ()
{
	int i = 0, j = 1;
	while (i != 22)
	{
		for (int n = 0; n < 3; ++n)
		{
			i%10 == 0 ? printf("I=%d J=%d\n", i/10, i/10 + j ) : printf("I=%.1lf J=%.1lf\n", i/10.0, (j*10+i)/10.0 );
			j ++;
		}
		i +=2;
		j =1;
	}
    return 0;
}
