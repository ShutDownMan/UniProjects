#include <stdio.h>

int strlength(char str[]) {
	int i;

	for(i = 0; str[i]; ++i)
		;

	return i;
}

int isPalindrom(char str[]) {
	int i, n;

	n = strlength(str);
	for(i = 0; i < (n+1)/2; ++i) {
		if(str[i] != str[n-i-1]) {
			return 0;
		}
	}

	return 1;
}

int main(void) {
	int cdt;
	char str[256];

	scanf("%d ", &cdt);
	while(cdt--) {
		scanf("%[^\n]%*c", str);
		if(isPalindrom(str)) {
			printf("sim\n");
		} else {
			printf("nao\n");
		}
	}

	return 0;
}