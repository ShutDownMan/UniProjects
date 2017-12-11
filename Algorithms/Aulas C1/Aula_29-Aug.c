#include <stdio.h>
#include <ctype.h>

int getLength(char string[]) {
	int i;

	for (i = 0;; ++i) {
		if(!string[i]) {
			return i;
		}
	}
}

int isVowel(char c) {
	int isLowercaseVowel, isUppercaseVowel;
	
	isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

	if(isLowercaseVowel || isUppercaseVowel) return 1;
	return 0;
}

int vowels(char string[]) {
	int i, vowelCount = 0;
	char c;

	for (i = 0; i < getLength(string); ++i) {
		c = string[i];

		if(isVowel(c)) vowelCount ++;
	}
	return vowelCount;
}

int consonants(char string[]) {
	int i, consonantCount = 0;
	char c;

	for (i = 0; i < getLength(string); ++i) {
		c = string[i];

		if(!isVowel(c) && isalpha(c)) consonantCount ++;
	}
	return consonantCount;
}

void getVowels(char s[], char v[]) {
	int i, j;

	for (i=j= 0; s[i]; ++i) {
		if(isVowel(s[i])) {
			v[j] = s[i];
			j++;
		}
	}
	v[j] = 0;
}

int main(int argc, char const *argv[]) {
	
	int i_cdt, cdt;
	char string[100], vowels[100];

	scanf("%d ", &cdt);

	for (i_cdt = 0; i_cdt < cdt; ++i_cdt) {
		gets(string);
		getVowels(string, vowels);
		//printf("[%s] = %d\n", string, getLength(string));
		//printf("[%s] = %d\n", string, vowels(string));
		//printf("[%s] = %d\n", string, consonants(string));
		printf("vowels = [%s]\n", vowels);
	}

	return 0;
}