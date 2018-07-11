#include <stdio.h>

int sumDigit(int num) {
	int sum;

	for(sum = 0; num; num /= 10) {
		sum += num%10;
	}

	return sum;
}

int main(void) {
	int num, minSum;

	scanf("%d", &num);
	while(num != -1) {
		minSum = num;
		while(minSum >= 10) {
			minSum = sumDigit(minSum);
		}
		printf("minSum(%d) = %d\n", num, minSum);
		scanf("%d", &num);
	}

	return 0;
}