#include <stdio.h>

void printVet(int length, int vet[], char vetName[]) {
	int i;

	for (i = 0; i < length; ++i) {
		printf("%s[%d] = %d\n", vetName, i, vet[i]);
	}
}

void scanVet(int length, int par[], int impar[]) {
	int runs, i_par = 0, i_impar = 0, cur;

	for(runs = 0; runs < 15; ++runs) {
		scanf("%d", &cur);

		if(cur %2 == 0) {
			par[i_par] = cur;
			i_par++;

			if(i_par == length) {
				printVet(length, par, "par");
				i_par = 0;
			}
				
		} else {
			impar[i_impar] = cur;
			i_impar++;

			if(i_impar == length) {
				printVet(length, impar, "impar");
				i_impar = 0;
			}
		}
	}

	printVet(i_impar, impar, "impar");
	printVet(i_par, par, "par");
}

int main(int argc, char const *argv[]) {
	int length = 5, par[length], impar[length];

	scanVet(length, par, impar);

	return 0;
}