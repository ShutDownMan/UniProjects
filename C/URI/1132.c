#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	
	int in_a, in_b, sum = 0;
	int max, i;

	scanf("%d %d", &in_a, &in_b);

	max = fmax(in_a, in_b);

	for(i = fmin(in_a, in_b); i <= max; ++i) {
		if(i %13 != 0) {
			sum += i;
		}
	}

	printf("%d\n", sum);

	return 0;
}