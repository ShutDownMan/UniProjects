#include <stdio.h>

int v[100], n;

// preenche um vetor de inteiros com os números de 1 a n
int main(int argc, char const *argv[]) {
	int i;

	scanf("%d", &n);

	asm(".intel_syntax noprefix\n\t"
		"XOR EAX, EAX\n\t"
		"XOR EBX, EBX\n\t" //< iterator register for adress
		"MOV ECX, _n\n\t" //< iterator count register

		"\n"
	"START:\n\t"
		"OR ECX, 0\n\t"
		"JZ END\n\t"

		"MOV EAX, EBX\n\t"
		"INC EAX\n\t"
		"MOV DWORD PTR [_v + EBX*4], EAX\n\t"

		"INC EBX\n\t"
		"DEC ECX\n\t"

		"JMP START\n"
	"END:\n\t"
		".att_syntax prefix\n");

	for(i = 0; i < n; ++i) {
		printf("v[%d] = %d\n", i, v[i]);
	}

	return 0;
}