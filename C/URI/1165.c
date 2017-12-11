#include <stdio.h>

int main() {

	int n, input, i, j;

	char primo;

	scanf("%d'", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &input);

		primo = 1;

		for (j = 1; j < input; ++j) {
			if(input%j == 0 && j != 1) {
				primo = 0;
				break;
			}
		}

		if(primo) {
			printf("%d eh primo\n", input);
		} else {
			printf("%d nao eh primo\n", input);
		}

	}

}