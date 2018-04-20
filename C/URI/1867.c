#include <stdio.h>

int main(int argc, char const *argv[]) {
	long int numA, numB;
	int accA, accB;
	int res;

	scanf("%ld%ld", &numA, &numB);
	while(numA || numB) {
		accA = accB = res = 0;

		do {
			while(numA || numB) {
				accA += numA%10;
				numA /= 10;

				accB += numB%10;
				numB /= 10;
			}

			if(accA >= 10) {
				numA = accA;
				accA = 0;
			}

			if(accB >= 10) {
				numB = accB;
				accB = 0;
			}

		} while(accA > 10 || accB > 10);

		res = (accA != accB);
		res += (accA < accB);
		printf("%d\n", res);

		scanf("%d%d", &numA, &numB);
	}

	return 0;
}