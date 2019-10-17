#include <stdio.h>

void createMat(int N);

void printMat(int N, int mat[N][N]);

int main(int argc, char const *argv[]) {	
	int N;

	scanf("%d", &N);
	createMat(N);

	return 0;
}

void createMat(int N) {
	int mat[N][N];
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if(i+j < N) {
				mat[i][j] = i + j + 1;

				mat[(N - j - 1)][(N - 1 - i)] = i + j + 1;
			}
		}
	}

	printMat(N, mat);
}

void printMat(int N, int mat[N][N]) {
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
}