#include<stdio.h>
#include <math.h>
int main(int argc, char const *argv[]) {
	int a;

	scanf("%d",&a);

	printf("tamanho(%d) = %d\n",a, ((int)log10(a))+1);

	return 0;
}