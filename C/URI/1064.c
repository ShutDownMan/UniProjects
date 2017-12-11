#include <stdio.h>

int main(int argc, char const *argv[])
{
	int posCount, i;
	double n, totalSum;

	for (i = 0; i < 6; ++i) {
		scanf("%lf", &n);

		if (n > 0) {
			posCount++;
			totalSum += n;
		}

	}

	printf("%d valores positivos\n", posCount);
	printf("%.1lf\n", totalSum/posCount);

	return 0;
}