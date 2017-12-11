#include <stdio.h>
#include <math.h>

int main(){
	double salary, deltaSalary;
	int percent;

	int rPercent[5] = {15, 12, 10, 7, 4};

	scanf("%lf", &salary);

	percent = (salary != 0) ? rPercent[(int)ceil(salary/400)-1] : 15;

	deltaSalary = salary * (percent/100.0);

	printf("Novo salario: %.2f\n", salary+deltaSalary);
	printf("Reajuste ganho: %.2f\n", deltaSalary);
	printf("Em percentual: %d %%\n", percent);

	return 0;
}