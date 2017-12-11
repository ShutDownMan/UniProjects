#include <stdio.h>
#include <math.h>

void ler(int *t, float v[]);

void lerpoly(int *t, float vet[]);

void print(int length, float vet[]);

void evalpoly(int length, float vet[]);

float eval(float vet[], int length, float x);

int main() {
	float a[100];
	int n;

	lerpoly(&n, a);
	evalpoly(n, a);

	return 0;
}

void ler(int *t, float v[]) {
	int i;
	printf("Entre com um inteiro: \n");

	scanf("%d", t);
	for(i=0; i < *t; i++){
	    scanf("%f", &v[i]);
	}
}

void lerpoly(int *t, float vet[]) {
	ler(t, vet);
	print(*t, vet);
}

void print(int length, float vet[]) {
	int i;
	for(i = 0; i < length; i++){
	    printf("A[%d] = %g\n", i, vet[i]);
	}
}

void evalpoly(int length, float vet[]) {
	float x, y;

	printf("Entre com float: \n");
	scanf("%f", &x);

	while(x != 0) {
		y = eval(vet, length, x);

		printf("P[%g] = %g\n", x, y);
		scanf("%f", &x);
	}
}

float eval(float vet[], int length, float x) {
	int i;
	float y = 0, s = 0;

	for (i = length-1; i>=0; --i) {
		s = s*x + vet[i];
	}

	return y;
}