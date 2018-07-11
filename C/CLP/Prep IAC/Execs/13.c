#include <stdio.h>

int encaixa(int x, int y) {
	for(; x && y; x /= 10, y /= 10) {
		if(x%10 != y%10) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int cdt;
	int x, y;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d %d", &x, &y);
		if(encaixa(x, y)) {
			printf("encaixa\n");
		} else {
			printf("nao encaixa\n");
		}
	}

	return 0;
}