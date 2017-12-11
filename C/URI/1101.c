#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	int m, n, sum, i;

	while(1) {
		sum = 0;

		scanf("%d %d", &m, &n);

		if(m <= 0 || n <= 0)
			break;

		for (i = fmin(m, n); i <= fmax(m, n); ++i) {
			sum += i;
			printf("%d ", i);
		}

		printf("Sum=%d\n", sum);
	}

	return 0;
}