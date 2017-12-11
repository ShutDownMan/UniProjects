#include <stdio.h>
#include <math.h>

void getBitStr(char* length, char bitStr[], int num);

void printBits(char length, char bitStr[]);

void parseBitStr(char length, char bitStr[]);

int main(int argc, char const *argv[]) {
	char bitStr[32], length;
	int num;

	scanf("%d", &num);
	while(num) {

		getBitStr(&length, bitStr, num);
		printBits(length, bitStr);
		parseBitStr(length, bitStr);

		scanf("%d", &num);
	}

	return 0;
}

void getBitStr(char* length, char bitStr[], int num) {
	int i;

	for(i = 0; num > 0; ++i) {
		bitStr[i] = num%2;
		num /= 2;
	}

	*length = i;
}

void printBits(char length, char bitStr[]) {
	for(int i = length-1; i >= 0; --i) {
		printf("%d", bitStr[i]);
	}
	printf("\n");
}

void parseBitStr(char length, char bitStr[]) {
	int out = 0;

	for(int i = length-1; i >= 0; --i) {
		out = out*2 + bitStr[i];
	}

	printf("Value = %d\n", out);
}