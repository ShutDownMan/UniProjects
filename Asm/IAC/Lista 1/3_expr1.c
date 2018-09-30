#include <stdio.h>

int i1, i2, i3;

void setupVars() {
	i1 = 11; i2 = 9; i3 = 40;
}

void printVars() {
	printf("i1 = %d\n", i1);
	printf("i2 = %d\n", i2);
	printf("i3 = %d\n", i3);
	printf("+++++++++\n");
}

int main(int argc, char const *argv[]) {

	setupVars();
	printVars();

	// i3 = i1 + 8*i2 + 6
	asm(".intel_syntax noprefix\n\t"
		"MOV ECX, _i2\n\t"
		"LEA EAX, [6 + 8*ECX]\n\t"
		"ADD EAX, _i1\n\t"
		"MOV _i3, EAX\n\t"
		".att_syntax prefix\n");
	printVars();

	return 0;
}