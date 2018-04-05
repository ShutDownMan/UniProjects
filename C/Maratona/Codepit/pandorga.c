#include <stdio.h>

int main(int argc, char const *argv[]) {
	int casos, a, b;

	scanf("%d", &casos);

	while(casos--) {
		scanf("%d %d", &a, &b);

		printf("%d cm2\n", (a*b)/2);
	}

	return 0;
}