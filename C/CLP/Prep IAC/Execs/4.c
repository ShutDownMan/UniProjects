#include <stdio.h>

int strlength(char str[]) {
	int i;

	for(i = 0; str[i]; ++i)
		;

	return i;
}

int main(void) {
	int cdt;
	char str[256];

	scanf("%d", &cdt);
	while(cdt--) {
		scanf(" %[^\n]%*c", str);
		printf("strLength(\"%s\") = %d\n", str, strlength(str));
	}

	return 0;
}