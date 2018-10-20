#include <stdio.h>

char s[100];
int t;

void ler(char s[]) {
	scanf("%[^\n]%*c", s);
}

// checka se string é palindromo
int main(int argc, char const *argv[]) {
	ler(s);

	asm(".intel_syntax noprefix\n\t"
		"XOR EBX, EBX\n\t"
		"XOR EDX, EDX\n\t"
		"MOV ECX, 1\n\t"
		"LEA EDI, [_s]\n\t"

		"\n"
	"START_0:\n\t"
		"MOV AL, BYTE PTR [EDI]\n\t"

		"OR AL, 0\n\t"
		"JZ END_0\n\t"

		"INC EBX\n\t"
		"INC EDI\n\t"

		"JMP START_0\n\t"
		"\n"
	"END_0:\n\t"

		"DEC EDI\n\t"
		"DEC EBX\n\t"
		"SHR EBX\n\t"

		"MOV _t, EBX\n\t"
		"\n"
	"START:\n\t"
		"OR EBX, 0\n\t"
		"JZ END\n\t"

		"MOV AL, BYTE PTR [EDI]\n\t"
		"CMP AL, BYTE PTR [_s + EDX]\n\t"
		"JNE FALSE\n\t"

		"\n"
	"CONTINUE:\n\t"
		"INC EDX\n\t"
		"DEC EDI\n\t"
		"DEC EBX\n\t"

		"JMP START\n\t"

		"\n"
	"FALSE:\n\t"
		"MOV ECX, 0\n\t"

		"\n"
	"END:\n\t"
		"MOV _t, ECX\n\t"
		".att_syntax prefix\n");

	printf("s = %s\n", s);
	printf("t = %d\n", t);

	return 0;
}