#include <stdio.h>

int main(int argc, char const *argv[]) {
	int casosDeTestes, cdt, i, j;
	int qPaineis, qCaminhoes, frete;
	int caminhoes[10] = {0}, paineis[1000];
	int curPainel, somaPaineis, maxCam;
	double mediaPorCam;

	scanf("%d", &casosDeTestes);

	for(cdt = 0; cdt < casosDeTestes; ++cdt) {
		scanf("%d %d %d", &qPaineis, &qCaminhoes, &frete);

		//printf("Teste: %d\n", cdt);

		somaPaineis = 0;
		maxCam = 0;
		for(i = 0; i < qPaineis; ++i) {
			scanf("%d", &curPainel);

			somaPaineis += curPainel;
			paineis[i] = curPainel;
		}

		mediaPorCam = somaPaineis/qCaminhoes;
		//printf("Media: %lf\n", mediaPorCam);

		for(i = 0, j = 0; i < qCaminhoes; ++i) {
			
			caminhoes[i] = 0;
			for(; caminhoes[i] + paineis[j] <= mediaPorCam && j < qPaineis; ++j) {
				caminhoes[i] += paineis[j];
				//printf("\tSoma: %d\n", paineis[j]);
			}

			if(caminhoes[i] > maxCam) maxCam = caminhoes[i];

			//printf("Caminhao %d: %d\n", i, caminhoes[i]);
		}
		i--;

		for(; j < qPaineis; ++j) {
			caminhoes[i] += paineis[j];
			//printf("\tSoma: %d\n", paineis[j]);
		}
		
		//printf("Caminhao %d: %d\n", i, caminhoes[i]);

		if(caminhoes[i] > maxCam) maxCam = caminhoes[i];

		printf("%d $%d\n", maxCam, maxCam * qCaminhoes * frete);
		//printf("------------\n");
	}

	return 0;
}