#include <stdio.h>

int v[100], n, t;

int main(int argc, char const *argv[]) {
	n = 10; t = 0;

	v[0] = 1;
	v[1] = 2;
	v[2] = 7;
	v[3] = 3;

	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, n\n\t"
		"XOR EBX, EBX\n\t"
		"XOR ECX, ECX\n\t"

	"\n"
	"STARTLOOP:\n\t"
		"CMP EAX, 0\n\t"
		"JZ ENDLOOP\n\t"

		"CMP DWORD PTR [v+EBX*4], 0\n\t"
		"JNZ CONTINUE\n\t"

		"INC ECX\n\t"

	"\n"
	"CONTINUE:\n\t"
		"DEC EAX\n\t"
		"INC EBX\n\t"
		"JMP STARTLOOP\n\t"

	"\n"
	"ENDLOOP:\n\t"
		"MOV t, ECX\n\t"
		".att_syntax prefix\n");

	int i;
	for(i = 0; i < 10; ++i) {
		printf("v[%d] = %d\n", i, v[i]);
	}
	printf("t = %d\n", t);


	return 0;
}