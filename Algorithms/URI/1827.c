#include <stdio.h>

#define MAX 256

void createmat(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			mat[row][col] = 0;
			if(row == col) mat[row][col] = 2;
			if(row+col == length-1) mat[row][col] = 3;
			if(row >= (length-1)/3.0 - 0.3 && col >= (length-1)/3.0 - 0.3 && col <= (2*(length))/3.0 - 0.3 && row <= (2*(length))/3.0 - 0.3) mat[row][col] = 1;
			mat[length/2][length/2] = 4;
		}
	}
}

void printmat(int length, int width, int mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			printf("%d", mat[row][col]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[]) {
	int mat[MAX][MAX], length;

	while(scanf("%d", &length) != EOF) {
		//printf("%d\n", length);
		createmat(length, length, mat);
		printmat(length, length, mat);
		printf("\n");
	}

	return 0;
}