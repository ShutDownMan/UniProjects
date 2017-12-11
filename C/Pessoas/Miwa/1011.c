#include <stdio.h>
#include <math.h>
#define pi 3.14159

int main()
{
	double r,v;

	scanf("%lf",&r);

	v = (4/3.0) * pi * pow(r,3);
	//(4/3) * pi * R3
	printf("VOLUME = %.3lf\n", v);
	return 0;
}