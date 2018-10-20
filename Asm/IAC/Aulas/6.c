#include <stdio.h>

int v[100], x, n, t;

void lerVet(int v[], int *n) {
	int i, num;

	scanf("%d", &num);
	for(i = 0; num; ++i) {
		v[i] = num;
		scanf("%d", &num);
	}
	*n = i;
}

int main(int argc, char const *argv[]) {

	scanf("%d", &t);
	lerVet(v, &n);

	asm(".intel_syntax noprefix\n\t"
		"lea esi, [_v]\n\t"
		"mov edx, _x\n\t"
		"mov eax, 0\n\t"
		"mov ecx, _n\n\t"
		"JECXZ V1\n\t"

	"V0:\n\t"
		"cmp edx, DWORD PTR [esi + ecx*4 - 4]\n\t"
		"jne SKIP\n\t"
		"inc eax\n\t"

	"SKIP:\n\t"
		"loop V0\n\t"
	"V1:\n\t"
		"mov _t, eax\n\t"
		".att_syntax prefix\n");

	printf("%d\n", t);
	return 0;
}