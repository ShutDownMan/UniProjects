#include <stdio.h>
#include <string.h>

#define MAX 100

// Indexado
int ispalin(char str[]) {
	int i, strlength;

	strlength = strlen(str);

	for (i = 0; i < strlength/2; ++i) {
		if(str[i] != str[strlength-i-1]) {
			return 0;
		}
	}

	return 1;
}

// Com ponteiros
int ispalinp(char str[]) {
	char *bgn, *fnl;

	bgn = str;
	fnl = str + strlen(str) - 1;

	for (; bgn < fnl; bgn++, fnl--) {
		if(*bgn != *fnl) return 0;
	}

	return 1;
}

int main(int argc, char const *argv[]) {
	char str[MAX];

	gets(str);

	while(strcmp(str, "exit")) {
		printf("%d\n", ispalinp(str));

		gets(str);
	}

	return 0;
}