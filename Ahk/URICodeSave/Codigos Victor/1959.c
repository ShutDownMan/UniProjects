#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[])
{
	unsigned long long int a[2];
	scanf("%llu %llu", &a[0], &a[1]);
	printf("%llu\n", a[0]*a[1] );
}
