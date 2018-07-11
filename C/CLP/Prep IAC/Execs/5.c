#include <stdio.h>

char *findFirstOcc(char c, char str[]) {
	int i;

	for(i = 0; str[i]; ++i) {
		if(str[i] == c) {
			return str + i;
		}
	}

	return NULL;
}

int main(void) {
	int cdt;
	char str[256];

	scanf("%d", &cdt);
	while(cdt--) {
		scanf(" %[^\n]%*c", str);
		printf("('a') => %s\n", findFirstOcc('a', str));
	}

	return 0;
}