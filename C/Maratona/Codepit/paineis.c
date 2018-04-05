#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i, casos, caminhoes, frete;
	int nPaineis, paineis[100];
	int frete, heavyPan, heavyCam;

	scanf("%d", &casos);

	while(casos--) {
		scanf("%d%d%d", &nPaineis, &caminhoes, &frete);

		heavyPan = heavyCam = frete = 0;
		for (i = 0; i < nPaineis; ++i) {
			scanf("%d", paineis+i);
			if(paineis[i] > heavyPan) {
				heavyPan = paineis[i];
			}
		}

		frete = heavyPan * caminhoes;


	}

	return 0;
}