#include <stdio.h>

char c1, c2, c3;
int i1, i2, i3;
long long int x1, x2, x3;

void setupVars() {
	c1 = 49; c2 = 2; c3 = 3;
	i1 = 11; i2 = 3; i3 = 40;
	x1 = 6; x2 = 0; x3 = 8;
}

void printVars() {
	printf("---------\n");
	printf("c1 = %d\n", c1);
	printf("c2 = %d\n", c2);
	printf("c3 = %d\n", c3);
	printf("---------\n");
	printf("i1 = %d\n", i1);
	printf("i2 = %d\n", i2);
	printf("i3 = %d\n", i3);
	printf("---------\n");
	printf("x1 = %ld\n", x1);
	printf("x2 = %ld\n", x2);
	printf("x3 = %ld\n", x3);
	printf("+++++++++\n");
}

int main(void) {

	setupVars();
	printVars();

	// x1 = x2+i1+c1+10;
	asm(".intel_syntax noprefix\n\t"
		/// +c1
		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"CWD\n\t"
		"CDQ\n\t"
		/// movimenta parte baixa -> ECX, parte alta -> EBX
		"MOV EAX, ECX\n\t"
		"MOV EDX, EBX\n\t"
		/// +i1
		"ADD ECX, _i1\n\t"
		"ADC EBX, 0\n\t"
		"ADD ECX, 10\n\t"
		"ADC EBX, 0\n\t"
		/// +x2
		"ADD ECX, DWORD PTR [_x2]\n\t"
		"ADC EBX, DWORD PTR [_x2+4]\n\t"
		/// x1 =
		"MOV DWORD PTR [_x1], ECX\n\t"
		"MOV DWORD PTR [_x1+4], EBX\n\t"
		"\n\t"
		".att_syntax prefix");

	printVars();

	return 0;
}