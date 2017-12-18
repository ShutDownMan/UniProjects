#include <stdio.h>

int main()
{
	double old, new;
	scanf("%lf %lf", &old, &new);
	printf("%.2lf%%\n", (new-old)/old*100);
}