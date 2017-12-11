#include <stdio.h>
#include <math.h>

int main() {
	int a, b, i;

	scanf("%d %d", &a, &b);

	for(i = fmin(a, b)+1; i < fmax(a, b); ++i) {
		if(i %5 == 2 || i %5 == 3) {
			printf("%d\n", i);
		}
	}

	return 0;
}