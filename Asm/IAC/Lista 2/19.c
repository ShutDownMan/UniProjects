#include <stdio.h>

char s[100];
int t;

void ler(char s[]) {
	scanf("%[^\n]%*c", s);
}

// conta quantidade de vogais em uma string
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

		"CMP AL, 'a'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'e'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'i'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'o'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'u'\n\t"
		"JE TRUE\n\t"

		"CMP AL, 'A'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'E'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'I'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'O'\n\t"
		"JE TRUE\n\t"
		"CMP AL, 'U'\n\t"
		"JE TRUE\n\t"

		"JMP CONTINUE\n\t"

		"\n"
	"TRUE:\n\t"
		"INC ECX\n\t"

		"\n"
	"CONTINUE:\n\t"
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