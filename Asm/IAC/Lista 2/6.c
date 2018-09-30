#include <stdio.h>

int v[100], n, t;
char s[100];

void ler(int v[], int *n) {
	int i;

	scanf("%d", n);

	for(i = 0; i < *n; ++i) {
		scanf("%d", &v[i]);
	}
}

// quantidade de numeros negativos em um vetor de inteiros
int main(int argc, char const *argv[]) {
	ler(v, &n);

	asm(".intel_syntax noprefix\n\t"
		"XOR EAX, EAX\n\t" //< result register
		"XOR EBX, EBX\n\t" //< iterator register for adress
		"MOV ECX, _n\n\t" //< iterator count register

		"\n"
	"START:\n\t"
		"OR ECX, 0\n\t"
		"JZ END\n\t"

		"CMP DWORD PTR [_v + EBX*4], 0\n\t"

		"JG CONTINUE\n\t"
		"INC EAX\n\t"

		"\n"
	"CONTINUE:\n\t"
		"INC EBX\n\t"
		"DEC ECX\n\t"

		"JMP START\n"
	"END:\n\t"
		"MOV _t, EAX\n\t"
		".att_syntax prefix\n");

	printf("t = %d\n", t);

	return 0;
}