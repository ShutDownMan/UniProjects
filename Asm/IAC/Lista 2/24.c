#include <stdio.h>

char s[100];
int t;

void ler(char s[]) {
	scanf("%[^\n]%*c", s);
}

// tranforma digitos de string em valor numerico
int main(int argc, char const *argv[]) {
	ler(s);

	asm(".intel_syntax noprefix\n\t"
		"XOR AL, AL\n\t"
		"XOR ECX, ECX\n\t"
		"LEA EDI, [_s]\n\t"

		"\n"
	"START:\n\t"
		"MOV AL, BYTE PTR [EDI]\n\t"

		"OR AL, 0\n\t"
		"JZ END\n\t"

		"CBW\n\t"

		"SUB EAX, '0'\n\t"
		"IMUL ECX, ECX, 10\n\t"
		"ADD ECX, EAX\n\t"

		"INC EDI\t\n"

		"JMP START\t\n"

		"\n"
	"END:\n\t"
		"MOV _t, ECX\n\t"
		".att_syntax prefix\n");

	printf("s = %s\n", s);
	printf("t = %d\n", t);

	return 0;
}