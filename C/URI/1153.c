#include <stdio.h>

long int fac(int f);

int main()
{
	int input;

	scanf("%d", &input);

	printf("%ld\n", fac(input));

	return 0;
}

long int fac(int f){
	return (f <= 1) ? 1 : f * fac(f-1);
}