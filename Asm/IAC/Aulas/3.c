#include <stdio.h>

int x, y;

int main(int argc, char const *argv[]) {
	x = 10; y = 15;

	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, x\n\t"
		"XOR ECX, ECX\n\t"

		"\n"
	"INI:\n\t"
		"OR EAX, EAX\n\t"
		"JZ CONTINUE\n\t"
		"SHR EAX, 1\n\t"
		"ADC ECX, 0\n\t"

		"JMP INI\n\t"

		"MOV y, ecx\n\t"
		".att_syntax prefix\n");

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	return 0;
}