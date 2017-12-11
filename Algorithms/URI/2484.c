#include <stdio.h>

int length(char src[]) {
	int i;
	for (i = 0; src[i]; ++i)
		;
	return i;
}

void createTriang(char src[]) {
	int i, j, k, l = length(src);

	for (i = 0, j = l; i < l; ++i, j--) {
		for (k = 0; k < i; ++k) {
			putchar(' ');
		}

		for (k = 0; k < j; ++k) {
			putchar(src[k]);
			if(k+1 != j) putchar(' ');
		}

		printf("\n");
	}
}

int main(int argc, char const *argv[]) {
	char s[100];

	while(scanf(" %s ", s) != EOF) {
		createTriang(s);
		printf("\n");
	}

	return 0;
}