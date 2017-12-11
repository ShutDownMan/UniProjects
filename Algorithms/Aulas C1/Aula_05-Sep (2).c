#include <stdio.h>

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

int toNum(char numStr[]) {
	int num;

	sscanf(numStr, "%d", &num);

	return num;
}

void toVet(char str[], int vet[], int* length) {
	int i, j, currNum;
	char numStr[100];

	for (i=*length = 0; str[i]; ++i) {
		for (; str[i] != '['; ++i)
			;
		
		for (++i,j = 0; str[i] != ']'; ++i, ++j) {
			numStr[j] = str[i];
		}
		numStr[j] = 0;

		//printf("str: %s // %c\n", numStr, str[i]);

		currNum = toNum(numStr);
		vet[*length] = currNum;
		(*length)++;

		//printf("num: %d\n", currNum);
	}
	(*length)++;
}

int main(int argc, char const *argv[]) {
	char currStr[100];
	int numVet[100], numVet_Length;

	gets(currStr);
	while(!strcmp(currStr, "exit")) {
		toVet(currStr, numVet, &numVet_Length);
		gets(currStr);
	}

	return 0;
}