#include <stdio.h>

void oddEvenQnt(int num, int *total, int *oddQnt) {
	for(; num; num /= 10) {
		(*oddQnt) += ((num%10)%2);
		(*total)++;
	}
}

int main(void) {
	int cdt, total, odds, num;

	total = odds = 0;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &num);
		oddEvenQnt(num, &total, &odds);
	}

	printf("#pares = %d\n", total-odds);
	printf("#impares = %d\n", odds);

	return 0;
}