#include <stdio.h>

int x, t;

// fatorial de um inteiro sem sinal
int main(int argc, char const *argv[]) {

	scanf("%d", &x);

	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, 1\n\t"
		"MOV EBX, 0\n\t"
		"MOV ECX, _x\n\t"
		"MOV EDX, 0\n\t"

		"\n"
	"START:\n\t"
		"OR ECX, 0\n\t"
		"JZ END\n\t"

		"IMUL ECX\n\t"
		"DEC ECX\n\t"

		"JMP START\n\t"

		"\n"
	"END:\n\t"
		"MOV _t, EAX\n\t"
		".att_syntax prefix\n");

	printf("t = %d\n", t);

	return 0;
}