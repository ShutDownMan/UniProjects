#include <stdio.h>

int main() {

	int sumEven = 0, sumOdd = 0, sumPos = 0, sumNeg = 0, i;
	int curr;

	for(i = 0; i < 5;i ++){
		scanf("%d", &curr);

		if(curr > 0){
			sumPos++;
		} else if(curr < 0) {
			sumNeg++;
		}

		if(curr %2 == 0){
			sumEven++;
		} else {
			sumOdd++;
		}
	}

	printf("%d valor(es) par(es)\n", sumEven);
	printf("%d valor(es) impar(es)\n", sumOdd);
	printf("%d valor(es) positivo(s)\n", sumPos);
	printf("%d valor(es) negativo(s)\n", sumNeg);

	return 0;
}