#include <stdio.h>

int v1[100], n, t;
int v2[100];

void ler(int v[], int *n) {
	int i;

	scanf("%d", n);

	for(i = 0; i < *n; ++i) {
		scanf("%d", &v[i]);
	}
}

// monta um numero x a partir de um vetor de inteiros com os números de 1 a 9
int main(int argc, char const *argv[]) {
	int i;

	ler(v1, &n);
	ler(v2, &n);

	asm(".intel_syntax noprefix\n\t"
		"XOR EAX, EAX\n\t" //< result register
		"XOR EBX, EBX\n\t" //< iterator register for adress
		"MOV ECX, _n\n\t" //< iterator count register
		"MOV DWORD PTR _t, 0\n\t"

		"\n"
	"START:\n\t"
		"OR ECX, 0\n\t"
		"JZ END\n\t"

		"MOV EAX, DWORD PTR [_v1 + EBX*4]\n\t"
		"IMUL DWORD PTR [_v2 + EBX*4]\n\t"

		"ADD _t, EAX\n\t"

		"INC EBX\n\t"
		"DEC ECX\n\t"

		"JMP START\n"
	"END:\n\t"
		".att_syntax prefix\n");

	printf("t = %d\n", t);

	return 0;
}