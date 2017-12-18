#include <stdio.h>
#include <ctype.h>

int isvowel(int ch) {
  int c = toupper(ch);
 
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int clearVowels(char dest[], char src[]) {
	int i, j;

	j = 0;
	for (i = 0; src[i]; ++i) {
		if(isvowel(src[i])) {
			dest[j++] = src[i];
		}
	}
	dest[j] = 0;

	return j;
}

char veryPalin(int length, char str[]) {
	int i;

	for (i = 0; str[i]; ++i) {
		if(str[i] != str[length-i-1]) {
			return 'N';
		}
	}

	return 'S';
}

int main(int argc, char const *argv[]) {
	char inStr[100], noVowelStr[100], engra;
	int noVowelStrLength;

	gets(inStr);
	noVowelStrLength = clearVowels(noVowelStr, inStr);
	engra = veryPalin(noVowelStrLength, noVowelStr);

	printf("%c\n", engra);

	return 0;
}