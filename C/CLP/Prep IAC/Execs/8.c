#include <stdio.h>

int superNext(int num) {
	int multiplier, resNum;

	multiplier = 1;
	for(resNum = 0; num; num /= 10) {
		resNum += ((num%10 + 1)%10) * multiplier;
		multiplier *= 10;
	}

	return resNum;
}

int main(void) {
	int num;

	scanf("%d", &num);
	while(num != -1) {
		printf("superNext(%d) = %d\n", num, superNext(num));
		scanf("%d", &num);
	}

	return 0;
}