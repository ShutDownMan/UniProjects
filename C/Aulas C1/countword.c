#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#define MAX 256

int countwords(char str[]) {
	int i, wordcount;
	char lstchr = str[0];

	wordcount = 0;
	for(i = 0; str[i]; i++) {

		if(isspace(str[i])) {
			if(!isspace(lstchr)) {
				wordcount++;
				printf("\n");
			}
		} else {
			printf("%c", str[i]);
		}

		lstchr = str[i];
	}

	return wordcount;
}

int main(int argc, char const *argv[]) {
	char str[MAX];

	fgets(str, MAX, stdin);
	while(strcmp(str, "exit")) {
		printf("There are %d word(s)\n", countwords(str));

		fgets(str, MAX, stdin);
	}

	return 0;
}