#include <stdio.h>

int main() {
	int km;
	double liters;

	scanf("%d %lf", &km, &liters);

	double kmPerLiters = km/liters;

	printf("%.3lf km/l\n", kmPerLiters);

	return 0;
}