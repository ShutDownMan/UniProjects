#include <stdio.h>

int main() {
	unsigned int a = 10, b = 20, c;
	asm("movl %eax, $10;"
		"movl %ebx, $20;"
		"addl %ebx, %eax;":"=r"(c)
	);
	printf("Result = %d\n", c);

/*
	asm("movl $10, %eax;"
		"movl $20, %ebx;"
		"subl %ebx, %eax;"
	);
	printf("Result = %d\n", c);

	asm("movl $10, %eax;"
		"movl $20, %ebx;"
		"imull %ebx, %eax;"
	);
	printf("Result = %d\n", c);
*/

	return 0;
}