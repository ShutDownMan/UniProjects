#include <stdio.h>
#include <math.h>

int checkFit(int r1, int r2, double largura, double altura);

int main(int argc, char const *argv[]) {
	int largura, altura, r1, r2;

	scanf("%d %d %d %d", &largura, &altura, &r1, &r2);

	while(largura|altura|r1|r2) {
		if(checkFit(r1, r2, largura, altura)) {
			printf("S\n");
		} else {
			printf("N\n");
		}

		scanf("%d %d %d %d", &largura, &altura, &r1, &r2);
	}

	return 0;
}

int checkFit(int r1, int r2, double largura, double altura) {
	char rectHip = pow(largura-r2-r1, 2) + pow(altura-r2-r1, 2) >= pow(r2+r1, 2);

	if (rectHip && 2*fmax(r1, r2) <= fmin(altura, largura)) {
		return 1;
	}

	return 0;
}