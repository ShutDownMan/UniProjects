#include <stdio.h>

void getHighestTwo(int num, int *high, int *secHigh) {
	if(num > *secHigh) {
		if(num > *high) {
			*secHigh = *high;
			*high = num;
		} else {
			*secHigh = num;
		}
	}
}

int main(void) {
	int cdt, num;
	int high, secHigh;

	high = secHigh = 0;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &num);
		getHighestTwo(num, &high, &secHigh);
	}

	printf("Primeiro maior = %d\n", high);
	printf("Segundo maior = %d\n", secHigh);

	return 0;
}