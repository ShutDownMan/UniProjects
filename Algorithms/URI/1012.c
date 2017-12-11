#include <stdio.h>

int main() {

	double a, b, c, pi;

	pi = 3.14159;
 
	scanf("%lf %lf %lf", &a, &b, &c);

	double areaTriangle = (a*c)/2;
	double areaCircle = pi*(c*c);
	double areaTrapeze = ((a+b)*c)/2;
	double areaSquare = b*b;
	double areaRectangle = a*b;

	printf("TRIANGULO: %.3lf\n", areaTriangle);
	printf("CIRCULO: %.3lf\n", areaCircle);
	printf("TRAPEZIO: %.3lf\n", areaTrapeze);
	printf("QUADRADO: %.3lf\n", areaSquare);
	printf("RETANGULO: %.3lf\n", areaRectangle);

	return 0;
}