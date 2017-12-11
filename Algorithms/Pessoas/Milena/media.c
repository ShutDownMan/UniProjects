#include <stdio.h>

#define MAX 100

void loadvet(int v[], int* n){
	int i;
	
	scanf("%d", n);

	for (i = 0; i < *n; ++i) {
		scanf("%d", &v[i]);
	}
}

float media(int v[],int n){
	int i, sum;
	float avrg;

	sum = 0;
	for (i = 0; i < n; ++i) {
		sum += v[i];
	}

	avrg = ((float)sum/n);

	return avrg;

}

int main() {
	int n, v[MAX];

	loadvet(v, &n);

	printf("media = %g\n", media(v,n) );


	return 0;
}