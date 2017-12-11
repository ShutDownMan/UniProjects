#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i, n = 1;

	while(n != 0) {
		scanf("%d", &n);

		for(i = 0; i < n; ++i) {
			printf("%d", !((i/3) %2));
		}
		
		printf("\n");
	}

	return 0;
}