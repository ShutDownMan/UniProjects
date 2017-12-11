#include <stdio.h>
#include <math.h>

double Distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main() {
	int r1, r2, x1, y1, x2, y2;

	while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF) {
		if(r1 >= Distance(x1, y1, x2, y2) + r2) {
			printf("RICO\n");
		} else {
			printf("MORTO\n");
		}
	}
	return 0;
}

// Localizar e resolver os problemas da evasão acadêmica no curso de ciências da computação