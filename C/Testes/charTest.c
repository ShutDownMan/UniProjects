#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[]) {
	char c;

	do {
		c = getch();
		printf("%d <=> %c\n", c, c);
	} while(c != 3);

	return 0;
}