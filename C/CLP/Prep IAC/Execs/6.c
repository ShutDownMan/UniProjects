#include <stdio.h>

int sumDigit(int num) {
	int sum;

	for(sum = 0; num; num /= 10) {
		sum += num%10;
	}

	return sum;
}

int main(void) {
	int num;

	scanf("%d", &num);
	while(num != -1) {
		printf("sum(%d) = %d\n", num, sumDigit(num));
		scanf("%d", &num);
	}

	return 0;
}