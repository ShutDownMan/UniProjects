#include <stdio.h>
#include <math.h>
int main(){
	double a;
	scanf("%lf",&a);
	a *= 100;
	a = round(a);
	a /= 100;
	printf("%lf\n",a);
}