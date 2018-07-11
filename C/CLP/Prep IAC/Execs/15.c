#include <stdio.h>

void showHourSum(int h, int m, int s1, int s2) {
	int sSum = h*3600 + m*60 + s1 + s2;

	printf("%d:%d:%d\n", sSum/3600, (sSum%3600)/60, ((sSum%3600)%60));
}

int main(void) {
	int cdt, h, m, s1, s2;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d %d %d", &h, &m, &s1);
		scanf("%d", &s2);
		showHourSum(h, m, s1, s2);
	}

	return 0;
}