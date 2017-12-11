#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int d, h, c, l;
	double area;

	while(scanf("%d %d %d %d", &d, &h, &c, &l) != EOF) {
		area = (sqrt(pow(h, 2) + pow(c, 2)) * d) * l;
		area /= 10000;

		printf("%.4lf\n", area);
	}

	return 0;
}