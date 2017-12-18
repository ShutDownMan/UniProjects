#include <stdio.h>
#include <math.h>

int main()
{
	double s=0;

	for (int i = 1; i <= 39; i++)
	{
		s+= i/pow(2,(i-1)/2);
		i++;
	}
		printf("%.2lf\n",s );
	return 0;
}