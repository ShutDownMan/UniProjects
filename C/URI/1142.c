#include <stdio.h>

int main() {
	int lines;
	int i, j;

	scanf("%d", &lines);

	for(i = 0; i < lines; ++i) {
		for(j = 1; j < 4; ++j) {
			printf("%d ", i*4 + j);
		}
		j++;
		printf("PUM\n");
	}

	return 0;
}