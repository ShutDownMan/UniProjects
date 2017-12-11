#include <stdio.h>

int main() {

	double r;

	double pi = 3.14159;

	scanf("%lf", &r);

	double area = (4.0*pi/3.0)*(r*r*r);

	printf("VOLUME = %.3lf\n", area);

	return 0;
}