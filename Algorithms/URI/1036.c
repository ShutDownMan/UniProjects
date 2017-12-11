#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	
	double a, b, c, part1, r1, r2;

	scanf("%lf %lf %lf", &a, &b, &c);

	part1 = pow(b, 2) -4 * a * c;

	if(2*a <= 0 || part1 < 0){
		printf("Impossivel calcular\n");

		return 0;
	}

	r1 = (- b + sqrt(part1)) / (2 * a);
	r2 = (- b - sqrt(part1)) / (2 * a);

	printf("R1 = %.5lf\n", r1);
	printf("R2 = %.5lf\n", r2);

	return 0;
}