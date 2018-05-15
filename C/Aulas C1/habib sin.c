#include <stdio.h>

int main(int argc, char const *argv[]) {
	double y, x, z, t, y, k = 2;

	scanf("%lf", &x);

	t = x;

	y = y + t;
	t = -t * x * x/(k * (k+1));

	y = y + t; k = k + 2;
	t = -t * x * x/(k * (k+1));

	y = y + t; k = k + 2;
	t = -t * x * x/(k * (k+1));

	printf("sin(%lf) = %lf\n", x, t);

	return 0;
}