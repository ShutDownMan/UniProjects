#include <stdio.h>

int x, y;

int main(int argc, char const *argv[]) {
	x = 5;

	asm(".intel_syntax noprefix\n\t"
		"XOR EAX, EAX\n\t"
		"MOV ECX, x\n\t"
		"SAR ECX, 31\n\t"
		"ADD EAX, ECX\n\t"
		"MOV y, EAX\n\t"
		".att_syntax prefix\n");

	printf("x = %d\n", x);
	printf("y = %d\n", y);


	return 0;
}