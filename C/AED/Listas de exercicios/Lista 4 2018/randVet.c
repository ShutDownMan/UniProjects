#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXNUMBER 500

void createRandVet() {
	int i, num;

	for(i = num = 0; i < MAXNUMBER; ++i) {
		num += rand()%3;
		printf("%d\n", num);
	}
}

int main(void) {
	srand(time(NULL));

	createRandVet();

	return 0;
}