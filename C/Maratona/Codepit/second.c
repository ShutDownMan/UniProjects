#include <stdio.h>
#include <ctype.h>

int main() {
	char str[21];
	int i, wordSum, isPrime;

	while(scanf("%[^\n]%*c", str) != EOF) {
		for(wordSum = i = 0; str[i]; ++i) {
			if(isupper(str[i])) {
				wordSum += str[i] - 'A' + 26;
			} else {
				wordSum += str[i] - 'a';
			}

			wordSum += 1;
		}

		for(i = 2; i < wordSum && (isPrime = wordSum%i); ++i)
			;

		printf("It is %sa prime word.\n", (isPrime) ? "" : "not ");
	}

	return 0;
}
