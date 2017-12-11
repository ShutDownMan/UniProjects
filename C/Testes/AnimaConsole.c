#include <stdio.h>

int main(int argc, char const *argv[]) {
	char control = 0;
	int n = 6;

	for(;;) {
		for (int i = 0; i < 158; ++i) {
			printf("%d", !((i/n) %2));
		}

		n += (!control) ? 1 : -1;

		if(n > 32)	control = 1;
		if(n < 6)	control = 0;
	}

	return 0;
}