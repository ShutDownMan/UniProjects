#include <stdio.h>

void showOddNSum(int num) {
	int i, sum;
	int rNum = num*num*num;

	sum = 0;
	for(i = 1; sum < rNum; i += 2) {
		if(i/2 >= num) {
			sum -= i - num*2;
		}
		sum += i;
	}

	i -= 2*num;

	printf("%d^3 = ", num);
	while(num--) {
		printf("%d%s", i, (num) ? " + " : "\n");
		i += 2;
	}
}


int main(void) {
	int cdt, num;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &num);
		showOddNSum(num);
	}

	return 0;
}