#include <stdio.h>
#include <math.h>
int fac(int a);

int main (int argc, char const *argv[]){
	int n;

	scanf("%d", &n);
	printf("fac(%d) = %d\n",n,fac(n));
}

int fac(int a) {
	int i, res;

	for(i = res = 1; i <= a; i++){
		res *= i;
	}
	return res;
}