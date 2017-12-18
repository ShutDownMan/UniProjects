#include <stdio.h>
#include <math.h>

int main (){
	double avrg;
	int n, count, i;

	for (i=0; i<5; i++)
	{

		scanf(" %d", &n);

		if (n%2 == 0)
		{
			count++;
		}
	}

	printf("%d valores pares\n",count );

    return 0;
}