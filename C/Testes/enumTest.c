#include <stdio.h>

typedef enum type1 {
	ENUM = 1
} Type1;

typedef enum type2 {
	ENUM = 2
} Type2;


int main(int argc, char const *argv[]) {
	int enumVal = (Type1)ENUM;

	printf("enum value = %d\n", enumVal);

	return 0;
}