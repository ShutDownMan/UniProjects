#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	long long unsigned int n;
	scanf("%llu", &n);
	printf("%llu\n", (n*(n-3))/2);
}
