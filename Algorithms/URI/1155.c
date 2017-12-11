#include <stdio.h>

int main(int argc, char const *argv[]) {
	double out_result = 0;

	int i;
	for (i = 1; i <= 100; ++i) {
		out_result += 1.0/i;
	}

	printf("%.2lf\n", out_result);

	return 0;
}