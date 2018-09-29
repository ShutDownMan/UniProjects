#include <stdio.h>

int x, y;

int main(int argc, char const *argv[]) {
	x = 1; y = 5;

/*	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _x\n\t"
		"MOV ECX, -1\n\t"

		"\t"
	"INI:\n\t"
		"OR EAX, EAX\n\t"
		"JZ END\n\t"

		"INC ECX\n\t"
		"SHR EAX, 1\n\t"
		"JC END\n\t"
		"JMP INI\n\t"

		"\t"
	"END:\n\t"
		"MOV _y, ECX\n\t"
		".att_syntax prefix\n");
*/

	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _x\n\t"
		"MOV ECX, -1\n\t"

		"OR EAX, EAX\n\t"
		"JZ END\n\t"

		"\t"
	"INI:\n\t"
		"INC ECX\n\t"
		"SHL EAX, 1\n\t"
		"JC END\n\t"
		"JMP INI\n\t"

		"\t"
	"END:\n\t"
		"MOV _y, ECX\n\t"
		".att_syntax prefix\n");

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	return 0;
}