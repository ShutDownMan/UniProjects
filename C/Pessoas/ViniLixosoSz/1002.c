#include <stdio.h>

int main(int argc, char const *argv[]) {
	double pi,n,res;
	pi=3.14159;
	scanf("%lf",&n);
	res=pi*n*n;
	printf("A=%.4lf\n",res);

	return 0;
}