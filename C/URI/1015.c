#include <stdio.h>
#include <math.h>

int main() {

	double x[2], y[2];

	scanf("%lf %lf", &x[0], &y[0]);
	scanf("%lf %lf", &x[1], &y[1]);

	double distance = sqrt(pow((x[1]-x[0]), 2) + pow((y[1]-y[0]), 2));

	printf("%.4lf\n", distance);

	return 0;
}