#include <stdio.h>

// 3.1415926
// 1.57079632679

int main(int argc, char const *argv[]) {
    double x = 0, s = 0, t = 0;
    int k = 0;

//	scanf("%lf", &x);
    x = 3.1415926;

    s += 1; t = 1; k += 2;
    t *= -(x*x)/(k * (k-1));

    while(k/2 < 8) {
	    s += t; k += 2;
	    t *= -(x*x)/(k * (k-1));
    }

    s += t;

	printf("cos(%lf) = %lf\n", x, s);

	return 0;
}