#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 8

long long unsigned int fac(int n) {
	int i;
	long long unsigned int result = 1;

	for(i = 2; i < n; ++i) {
		result *= i;
	}

	return result;
}

double seno(double rads) {
	int i;
	double result;

//	rads /= (M_PI);

	for(i = result = 0; i < MAX_ITERATIONS; ++i) {
		result += pow(-1, i) * pow(rads, 2*i + 1)/fac(2*i + 1);
	}

	return result;
}

double rad(double degrees) {
	return degrees * (M_PI/180);
}

int main(void) {
	double rads;
	int i;

	for(i = 0; i < 25; ++i) {
		printf("%2d %3d %lf\n", i, i*15, seno(rad(i*15)));
	}

	return 0;
}