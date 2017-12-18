#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, pos = 0;
	scanf("%d", &n);
	int vet[n];
//	printf("%d\n",n );
	for ( i = 0; i < n; ++i)
	{
		scanf("%d", &vet[i]);
		if(vet[i] < vet[pos]) pos = i;
//		printf("vet[%d] = %d, vet[%d] = %d\n",i, vet[i], pos, vet[pos] );
	}
	printf("%d\n", pos+1);
}