#include <stdio.h>

int x, t;

// soma do quadrado das casas decimais de um inteiro sem sinal
int main(int argc, char const *argv[]) {

	scanf("%d", &x);

	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _x\n\t"
		"MOV EBX, 10\n\t"
		"MOV ECX, 0\n\t"
		"MOV DWORD PTR _t, 0\n\t"

		"\n"
	"START:\n\t"
		"OR EAX, 0\n\t"
		"JZ END\n\t"

		"MOV EDX, 0\n\t"
		"IDIV EBX\n\t"

		"IMUL EDX, EDX\n\t"
		"ADD ECX, EDX\n\t"

		"JMP START\n\t"

		"\n"
	"END:\n\t"
		"MOV _t, ECX\n\t"
		".att_syntax prefix\n");

	printf("t = %d\n", t);

	return 0;
}