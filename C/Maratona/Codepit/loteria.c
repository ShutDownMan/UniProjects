#include <stdio.h>

int main(int argc, char const *argv[]) {
	int length, width, B[256][256];
	int rowSum, colSum, res, shorter;
	int row, col, i;

	scanf("%d%d", &length, &width);

	for (row = 0; row < length; ++row) {
		for (col = 0; col < width; ++col) {
			scanf("%d", &B[row][col]);
		}
	}

	res = 0;
	shorter = (length < width) ? length : width;
	for (i = 0; i < shorter && !res; ++i) {
		for (row = rowSum = 0; row < length; rowSum += B[row++][i])
			;
		for (col = colSum = 0; col < width; colSum += B[i][col++])
			;
		res = ((rowSum%2) == (colSum%2));
	}

	printf("%s\n", (res) ? "S":"N");

	return 0;
}