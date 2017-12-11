#include <stdio.h>
#define MAX 256

int strcmp(char str1[], char str2[]) {
	int i;

	for (i = 0; str1[i] && str2[i] && str1[i] == str2[i]; ++i);

	return (str1[i] == str2[i]);
}

int length(char* str) {
	char *p;

	for (p = str; *p; ++p);

	return (p-str);
}


int main(int argc, char const *argv[]) {
	char str[MAX];

	gets(str);
	while(!strcmp(str, "exit")) {

		printf("length: %d\n", length(str));

		gets(str);
	}

	return 0;
}