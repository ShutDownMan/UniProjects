#include <stdio.h>
#include <math.h>

double getPlankLenght(double steps, double height, double lenght);

int main ()
{
	double steps, height, lenght, depth, plank;
	while(scanf("%lf %lf %lf %lf", &steps, &height, &lenght, &depth)!= EOF)
	{
		height /=100; lenght /= 100; depth /= 100;
		plank = getPlankLenght(steps, height, lenght);
		printf("%.4lf\n", plank*depth);
	}
}

double getPlankLenght(double steps, double height, double lenght)
{
	height *= steps;
	lenght *= steps;
	return sqrt(pow(height,2)+pow(lenght,2));
}