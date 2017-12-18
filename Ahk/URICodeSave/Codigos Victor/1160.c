#include <stdio.h>
#include <math.h>

int main()
{
	int pop1, pop2, n, i;
	double grow1, grow2;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		int years=0;
		scanf("%d %d %lf %lf", &pop1, &pop2, &grow1, &grow2);
		while(pop1<=pop2 && years<=101)
		{
			pop1 *= 1+grow1/100;
			pop2 *= 1+grow2/100;
			years++;
		}
		years<=100 ? printf("%d anos.\n", years) : printf("Mais de 1 seculo.\n");
	}

	return 0;
}