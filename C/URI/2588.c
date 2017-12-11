#include <stdio.h>
#include <ctype.h>

#define MAXSTR 1024

int main(int argc, char const *argv[]) {
	char str[MAXSTR], letters[26] = {0};
	int i, letterToAdd;

	while(scanf("%[^\n]%*c", str) != EOF) {
		letterToAdd = -1;

		for (i = 0; str[i]; ++i) {
			letters[toupper(str[i])-'A']++;
		}

		for (i = 0; i < 26; ++i) {
			letterToAdd += letters[i]%2;
			letters[i] = 0;
		}

		if(letterToAdd < 0) letterToAdd = 0;
		printf("%d\n", letterToAdd);
	}

	return 0;
}