#include <stdio.h>

const char *months[] = {
	"January", "February", "March",
	"April", "May", "June", "July",
	"August", "September", "October",
	"November", "December"};

int main(int argc, char const *argv[]) {
	int n;

	scanf(" %d", &n);

	printf("%s\n", months[n-1]);

	return 0;
}