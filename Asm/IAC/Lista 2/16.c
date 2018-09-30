#include <stdio.h>

char s[100];
int t;

void ler(char s[]) {
	scanf("%[^\n]%*c", s);
}

// calcula tamanho de uma string
int main(int argc, char const *argv[]) {
	ler(s);

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

	printf("t = %d\n", t);

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

	printf("t = %d\n", t);

	return 0;
}