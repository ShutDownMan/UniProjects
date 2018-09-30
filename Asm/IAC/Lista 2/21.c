#include <stdio.h>

char s[100];

void ler(char s[]) {
	scanf("%[^\n]%*c", s);
}

// converte caracteres em minusculo em uma string
int main(int argc, char const *argv[]) {
	ler(s);

	asm(".intel_syntax noprefix\n\t"
		"XOR AL, AL\n\t"
		"LEA EDI, [_s]\n\t"

		"\n"
	"START:\n\t"
		"MOV AL, BYTE PTR [EDI]\n\t"

		"OR AL, 0\n\t"
		"JZ END\n\t"

		"CMP AL, 'A'\n\t"
		"JL CONTINUE\n\t"
		"CMP AL, 'Z'\n\t"
		"JG CONTINUE\n\t"

		"ADD BYTE PTR [EDI], 'a'-'A'\n\t"

		"\n"
	"CONTINUE:\n\t"
		"INC EDI\t\n"

		"JMP START\t\n"

		"\n"
	"END:\n\t"
		".att_syntax prefix\n");

	printf("s = %s\n", s);

	return 0;
}