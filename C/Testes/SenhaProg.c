#include <stdio.h>
#include <conio.h>

#define BACKSPACE_KEY 8
#define RETURN_KEY 13

int main(int argc, char const *argv[]) {
	char c;

	printf("PASSWORD: ");
	do {
		c = getch();

		if(isalpha(c)) {
			printf("*");
		}

	} while(c != RETURN_KEY);


	return 0;
}