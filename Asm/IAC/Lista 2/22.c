#include <stdio.h>

char s[100];
int n;


// preencher string com n caracteres 'a'
int main(int argc, char const *argv[]) {

	scanf("%d", &n);

	asm(".intel_syntax noprefix\n\t"
		"MOV ECX, _n\n\t"
		"LEA EDI, [_s]\n\t"

		"\n"
	"START:\n\t"
		"OR ECX, 0\n\t"
		"JZ END\n\t"

		"MOV BYTE PTR [EDI], 'a'\n\t"

		"INC EDI\t\n"
		"DEC ECX\t\n"

		"JMP START\t\n"

		"\n"
	"END:\n\t"
		"MOV BYTE PTR [EDI], 0\n\t"
		".att_syntax prefix\n");

	printf("s = %s\n", s);

	return 0;
}