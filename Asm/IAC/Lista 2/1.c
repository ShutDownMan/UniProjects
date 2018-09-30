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

	system("PAUSE");
	return 0;
}