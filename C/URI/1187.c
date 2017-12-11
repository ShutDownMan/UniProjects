#include <stdio.h>

void scanmat(int length, int width, double mat[length][width]) {
	int row, col;

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			scanf("%lf", &mat[row][col]);
		}
	}
}

double sumsuppertriang(int length, int width, double mat[length][width]) {
	int row, col;
	double sum;

	sum = 0;
	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			sum += (col > row && row+col < length-1) ? mat[row][col] : 0;
		}
	}

	return sum;
}

int main(int argc, char const *argv[]) {
	double mat[100][100];
	char c;

	scanf("%c", &c);

	scanmat(12, 12, mat);

	if(c == 'S') {
		printf("%.1lf\n", sumsuppertriang(12, 12, mat));
	}

	if(c == 'M') {
		printf("%.1lf\n", sumsuppertriang(12, 12, mat)/30);
	}

	return 0;
}