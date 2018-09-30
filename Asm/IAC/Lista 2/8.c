#include <stdio.h>

int v[100], n, x;
int *t;

void ler(int v[], int *n) {
	int i;

	scanf("%d", n);

	for(i = 0; i < *n; ++i) {
		scanf("%d", &v[i]);
	}
}

// endereço da primeira ocorrencia de um x em um vetor de inteiros
int main(int argc, char const *argv[]) {
	ler(v, &n);

	x = 6;

	asm(".intel_syntax noprefix\n\t"
		"XOR EAX, EAX\n\t" //< result register
		"XOR EBX, EBX\n\t" //< iterator register for adress
		"MOV ECX, _n\n\t" //< iterator count register
		"MOV EDX, _x\n\t" //< 'looking for' number

		"\n"
	"START:\n\t"
		"OR ECX, 0\n\t"
		"JZ NOTFOUND\n\t"

		"CMP DWORD PTR [_v + EBX*4], EDX\n\t"

		"JE FOUND\n\t"

		"INC EAX\n\t"
		"INC EBX\n\t"
		"DEC ECX\n\t"

		"JMP START\n"

	"NOTFOUND:\n\t"
		"MOV EAX, 0\n\t"
		"JMP END\n\t"

		"\n"
	"FOUND:\n\t"
		"LEA EAX, [_v + EAX*4]\n\t"

		"\n"
	"END:\n\t"
		"MOV _t, EAX\n\t"
		".att_syntax prefix\n");


	printf("t = 0x%p\n", t);
	printf("t = %d\n", *t);

	return 0;
}