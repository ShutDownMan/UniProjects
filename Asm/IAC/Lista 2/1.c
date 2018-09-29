#include <stdio.h>
#include <stdlib.h>

int v[100], n, t;
char s[100];

void ler(int v[], int *n) {
	int i;

	scanf("%d", n);

	for(i = 0; i < *n; ++i) {
		scanf("%d", &v[i]);
	}
}

int main(int argc, char const *argv[]) {
	// produto dos elementos de um vetor de inteiros
	printf("Entre com o vetor\n");
	ler(v, &n);

	asm(".intel_syntax noprefix\n\t"
		"mov eax, 1\n\t"
		"mov ecx, _n\n\t"
		"xor ebx, ebx\n"
	"v0:\n\t"
		"cmp ecx, 0\n\t"
		"je v1\n\t"
		"imul eax, [ebx*4+_v]\n\t"
		"inc ebx\n\t"
		"dec ecx\n\t"
		"jmp v0\n"
	"v1:\n\t"
		"mov _t, eax\n\t"
		".att_syntax prefix\n");

	printf("%d\n", t);

	// strlen
	printf("entre com a string\n");
	gets(s);

	asm(".intel_syntax noprefix\n\t"
		"xor ebx, ebx\n"
	"s0:\n\t"
		"cmp byte ptr [ebx+_s], 0\n\t"
		"je s1\n\t"
		"inc ebx\n\t"
		"jmp s0\n"
	"s1:\n\t"
		"mov _t, ebx\n\t"
		".att_syntax prefix\n");

	printf("%d\n", t);

	// strlen

	asm(".intel_syntax noprefix\n\t"
		"lea ebx, _s\n\t"
		"mov edi, ebx\n"
	"t0:\n\t"
		"cmp byte ptr [ebx], 0\n\t"
		"je t1\n\t"
		"inc ebx\n\t"
		"jmp t0\n"
	"t1:\n\t"
		"sub ebx, edi\n\t"
		"mov _t, ebx\n"
		".att_syntax prefix\n");

	printf("%d\n", t);

	// outros blocos assembly

	system("PAUSE");
	return 0;
}