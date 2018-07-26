#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]) {
	printf("%ld\n", (time(NULL)%86400)/3600  - 3);

	return 0;
}
