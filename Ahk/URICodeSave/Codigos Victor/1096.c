#include <stdio.h>
#include <string.h>

int main ()
{
	int i = 1, j = 7;
	while (i != 11)
	{
		for (int n = 0; n < 3; ++n)
		{
			printf("I=%d J=%d\n", i, j );
			j --;
		}
		i +=2;
		j = 7;
	}
    return 0;
}
