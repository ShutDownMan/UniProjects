#include <stdio.h>

int main(int argc, char const *argv[]) {
	double current = 0, totalSum = 0;
	int totalValid = 0;

	while(totalValid < 2) {
		scanf("%lf", &current);

		if(current >= 0 && current <= 10) {
			totalSum += current;
			totalValid++;

		} else {
			printf("nota invalida\n");
		}

	}

	printf("media = %.2lf\n", totalSum/totalValid);

	return 0;
}