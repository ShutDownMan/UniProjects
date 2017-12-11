#include <stdio.h>

void strcopy(char to[], char from[]) {
	int i;

	for (i = 0; from[i]; ++i) {
		to[i] = from[i];
	}

	to[i] = 0;
}

int strcmp(char str1[], char str2[]) {
	int i;

	for (i = 0; str1[i] && str2[i]; ++i) {
		if(str1[i] != str2[i]) {
			return 0;
		}
	}
	
	if(str1[i] == str2[i]) return 1;
	else return 0;
}

int main(int argc, char const *argv[]) {
	char strAnt[100], strCurr[100];

	gets(strAnt);
	gets(strCurr);

	while(!strcmp(strCurr, "exit")) {
		printf("%d\n", strcmp(strAnt, strCurr));

		//printf("%s / %s\n", strAnt, strCurr);

		strcopy(strAnt, strCurr);
		gets(strCurr);
	}

	return 0;
}