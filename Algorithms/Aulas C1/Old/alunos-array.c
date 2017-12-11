#include <stdio.h>

void getFreqs(int quantNotas, int freq[]) {
	int i, currNota;
	for(i = 0; i < quantNotas; ++i) {
		scanf("%d", &currNota);
		freq[currNota]++;
	}
}

int getHiFreq(int freq[]) {
	int i, hiFreqInd = 0;

	for(i = 0; i < 11; ++i) {
		if(freq[hiFreqInd] < freq[i]) {
			hiFreqInd = i;
		}
	}
}

void printFreq(int freq[]) {

}

void printHist(int freq[]) {
	int i, j, hiFreq;

	hiFreq = getHiFreq(freq);

	for(i = 0; i < hiFreq; ++i) {
		for(j = 0; j < 11; ++j) {
			if(hiFreq-i <= freq[j]) {
				printf("*\t");
				freq[j]--;
			} else {
				printf(" \t");
			}
		}
		printf("\n");
	}

	for(i = 0; i < 11; ++i) {
		printf("%d\t", i);
	}
}

int main(int argc, char const *argv[]) {
	int freqNotas[11] = {0};

	getFreqs(24, freqNotas);
	printFreq(freqNotas);
	printHist(freqNotas);

	return 0;
}