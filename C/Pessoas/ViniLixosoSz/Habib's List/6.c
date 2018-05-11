#include<stdio.h>
#include <math.h>
int main(int argc, char const *argv[]) {
	int x, base;

	scanf("%d%d",&x,&base);

	printf("log%d(%d) = %lf\n", base, x,log(x)/log(base));

	return 0;
}

// log b(a) = ln(a)/ln(b)