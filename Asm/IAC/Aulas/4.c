#include <stdio.h>

#define int64 long long int

int64 x, y;

int main(int argc, char const *argv[]) {
	x = 123456; y = 5;

	printf("size = %d\n", sizeof(x));

	asm(".intel_syntax noprefix\n\t"
		"MOV ECX, DWORD PTR [_x]\n\t"
		"MOV EBX, DWORD PTR [_x+4]\n\t"

		"SHR EBX, 1\n\t"
		"RCR ECX, 1\n\t"

		"MOV DWORD PTR [_y], ECX\n\t"
		"MOV DWORD PTR [_y+4], EBX\n\t"

		".att_syntax prefix\n");

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	// -------------- //

	asm(".intel_syntax noprefix\n\t"
		"MOV ECX, DWORD PTR [_x]\n\t"
		"MOV EBX, DWORD PTR [_x+4]\n\t"

		"SHRD ECX, EBX, 1\n\t"

		"MOV DWORD PTR [_y], ECX\n\t"
		"MOV DWORD PTR [_y+4], EBX\n\t"

		".att_syntax prefix\n");

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	return 0;
}