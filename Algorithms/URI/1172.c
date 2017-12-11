#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i, in_cur;

	for (i = 0; i < 10; ++i) {
		scanf("%d", &in_cur);
		in_cur = (in_cur <= 0) ? 1 : in_cur;
		printf("X[%d] = %d\n", i, in_cur);
	}

	return 0;
}