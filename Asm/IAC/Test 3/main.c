#include <stdio.h>
#include <stdlib.h>

#define int64 long long int

// gcc -S -Wall -m32 -masm=intel -o main.asm main.c
// gcc -Wall -m32 main.c

//int64 y1, y2;
int x1, x2, x3;

int x, y, z;

int n, v, t;

int main(int argc, char const *argv[]) {
	x1 = 1; x2 = 7; x3 = 5;

	// x3 = x1 * x2 + 3;
	asm(".intel_syntax noprefix\n\t"
		"MOV eax, _x1\n\t"
		"IMUL eax, _x2\n\t"
		"ADD eax, 3\n\t"
		"MOV _x3, eax\n\t"
		".att_syntax prefix");

	printf("x1 = %d\n", x1);
	printf("x2 = %d\n", x2);
	printf("x3 = %d\n", x3);

	asm(".intel_syntax noprefix	\n\t"
		"mov eax, 1				\n\t"
		"mov ecx, _n			\n\t"
		"xor ebx, ebx			\n"
	"v0:                        \n\t"
		"cmp ecx, 0				\n\t"
		"je v1					\n\t"
		"imul eax, [ebx*4+_v]	\n\t"
		"inc ebx				\n\t"
		"dec ecx				\n\t"
		"jmp v0					\n\t"
	"v1:						\n"
		"mov _t, eax			\n\t"
	".att_syntax prefix");

	// y = 10 * x;
/*	asm(".intel_syntax noprefix\n\t"
	"MOV eax, _x\n\t"
	"LEA eax, [eax+eax*4]\n\t"
	"LEA eax, [eax+eax]\n\t"
	"MOV _y, eax\n\t"
	"");

	x = 5;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
*/

//	system("pause");
	return 0;
}