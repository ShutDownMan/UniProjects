#include <stdio.h>

void load(int vet[], int *n) {
	int curNum;

	scanf("%d", &curNum);

	*n = 0; curNum = 0;
	while(curNum != -1) {
		vet[*n] = curNum;
		*n ++;

		scanf("%d", &curNum);
	}

}

int soma(int vet[], int n) {
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += vet[i];
	}
}

int main(int argc, char const *argv[]) {
	int v[100], n;

	load(v, &n);
	s = soma(v, n);
	printf("Soma = %d\n", s);
	return 0;
}