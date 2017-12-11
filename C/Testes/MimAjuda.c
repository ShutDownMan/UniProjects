#include <stdio.h>

int main (){
	int n, i=0, j=0, k=0, numAtual;

	scanf("%d", &n);

	for (i = 0; i <= n; ++i) {
		scanf("%d", &numAtual);
		if ((numAtual>=10)&&(numAtual<=20)) {
			j++;
		} else {
			k++;
		}
	}

	printf("%d in\n", j );
	printf("%d out\n", k );

	return 0;
}