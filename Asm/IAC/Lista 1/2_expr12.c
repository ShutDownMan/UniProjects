#include <stdio.h>

char c1, c2, c3;
int i1, i2, i3;
long long int x1, x2, x3;

void setupVars() {
	c1 = 49; c2 = 2; c3 = 3;
	i1 = 11; i2 = 3; i3 = 40;
	x1 = 6; x2 = 0; x3 = 8;
}

void printVars() {
	printf("---------\n");
	printf("c1 = %d\n", c1);
	printf("c2 = %d\n", c2);
	printf("c3 = %d\n", c3);
	printf("---------\n");
	printf("i1 = %d\n", i1);
	printf("i2 = %d\n", i2);
	printf("i3 = %d\n", i3);
	printf("---------\n");
	printf("x1 = %ld\n", x1);
	printf("x2 = %ld\n", x2);
	printf("x3 = %ld\n", x3);
	printf("+++++++++\n");
}

int main(void) {

	setupVars();
	printVars();

/*	if(c1 < 'a' || c1 > 'z')
		i1++;
	else
		i1--;
*/
	asm(".intel_syntax noprefix\n\t"
		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"CMP EAX, 97\n\t"
		"JL TRUE\n\t"
		"CMP EAX, 122\n\t"
		"JG TRUE\n\t"

		"DEC DWORD PTR _i1\n\t"

		"JMP CONTINUE\n"
		"\n"
	"TRUE:\n\t"
		"INC DWORD PTR _i1\n\t"

		"\n"
	"CONTINUE:\n\t"
		"\n\t"
		".att_syntax prefix\n");

	printVars();

	return 0;
}