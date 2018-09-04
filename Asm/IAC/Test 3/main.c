#include <stdio.h>
#include <stdlib.h>
#define int64 long long int

// gcc -S -m32 -masm=intel -o main.asm main.c

int64 y1, y2;
int x1, x2, x3;

int x, y, z;

int main(int argc, char const *argv[]) {
	// x3 = x1 * x2 + 3;
/*	asm(".intel_syntax noprefix\n\t"
		"MOV eax, _x1\n\t"
		"IMUL eax, _x2\n\t"
		"ADD eax, 3\n\t"
		"MOV _x3, eax\n\t"
		"att_syntax");
*/

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

	z = x/y + x%10;
	asm(".intel_syntax noprefix\n\t"
	"\n\t"
	"att_syntax");

//	system("pause");
	return 0;
}