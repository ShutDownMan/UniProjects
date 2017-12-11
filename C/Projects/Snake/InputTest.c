#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[]) {
	char c;

	while (1) {
		c = getch();

		printf("HEYS = %c\n", c + 1);
	}


	return 0;
}
