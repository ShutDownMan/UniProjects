#include <stdio.h>

int __cdecl soma3(int x, int y, int z) {
//	return x + y + z;
}

int __cdecl soma4(int x, int y, int z, int w) {
/*
	int a, b;
	a = soma3(x, y, z);
	b = a + w;
	return b;
*/
	asm(".intel_syntax noprefix\n\t"
		"push ebp\n\t"
		"mov ebp, esp\n\t"

		// "sub esp, 16\n\t"

		"mov eax, [ebp + 1 * 8]\n\t"

		"mov esp, ebp\n\t"
		"pop ebp\n\t"
		// "ret\n\t"
		".att_syntax prefix\n");
}

int r, s, t;

int main(int argc, char const *argv[]) {
/*
	s = 100;
	t = 300;
	r = soma4(r, 200, s, t);
*/
	asm(".intel_syntax noprefix\n\t"
		"mov _s, dword ptr 100\n\t"

		"mov _t, dword ptr 300\n\t"

		"push dword ptr _r\n\t"
		"push dword ptr 200\n\t"
		"push dword ptr _s\n\t"
		"push dword ptr _t\n\t"
		"call _soma4\n\t"
		"add esp, 32\n\t"
		"mov _r, eax\n\t"

		"\n\t"
		"\n\t"
		".att_syntax prefix\n");

	printf("------\n", t);
	printf("r = %d\n", r);
	printf("s = %d\n", s);
	printf("t = %d\n", t);
	printf("------\n", t);

	return 0;
}