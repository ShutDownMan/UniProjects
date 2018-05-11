#include <stdio.h>

int func(char a) {
	return a - 'A';
}

int main(int argc, char const *argv[]) {
	int (*funcVar)(char) = NULL;

	funcVar = func;

	func('D');

	return 0;
}