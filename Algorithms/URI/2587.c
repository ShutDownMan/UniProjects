#include <stdio.h>

#define OPT1 in[0]
#define OPT2 in[1]
#define DOUBTWORD in[2]

int crossCheck(char in[][16], int* gapsInd);

void locateGaps(char doubtWord[], int gapsInd[]);

int main() {
	int n, i, result;
	int gapsInd[2];
	char in[3][16];

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s %s %s", OPT1, OPT2, DOUBTWORD);
		locateGaps(DOUBTWORD, gapsInd);

		if(crossCheck(in, gapsInd)) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
}

void locateGaps(char doubtWord[], int gapsInd[]) {
	int i, count;

	count = 0;
	for (i = 0; doubtWord[i]; ++i) {
		if(doubtWord[i] == '_') gapsInd[count++] = i;
	}
}

int crossCheck(char in[][16], int gapsInd[]) {
	if(OPT1[gapsInd[0]] == OPT2[gapsInd[1]]) return 1;
	if(OPT1[gapsInd[1]] == OPT2[gapsInd[0]]) return 1;
	return 0;
}