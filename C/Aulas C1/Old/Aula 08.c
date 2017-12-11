#include <stdio.h>
#include <math.h>

void execute(int n) {
	int i, current, out;

	out = 0;
	for(i = 0; i < n; ++i) {
		scanf("%d", &current);

		out += current*pow(10, i);
	}

	printf("%d\n", out);
}

int main(int argc, char const *argv[]) {
	int n;

	scanf("%d", &n);

	while(n != -1) {
		execute(n);
		printf("\n");
		scanf("%d", &n);
	}

	return 0;
}