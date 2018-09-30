#include <stdio.h>

int x, t;

// conta a quantidade de bits ligados
int main(int argc, char const *argv[]) {

	scanf("%d", &x);

	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _x\n\t"
		"XOR ECX, ECX\n\t"

		"\n"
	"START:\n\t"
		"OR EAX, 0\n\t"
		"JZ END\n\t"

		"SHR EAX\n\t"
		"JNC START\n\t"

		"INC ECX\n\t"

		"JMP START\n\t"

		"\n"
	"END:\n\t"
		"MOV _t, ECX\n\t"
		".att_syntax prefix\n");

	printf("t = %d\n", t);

	return 0;
}