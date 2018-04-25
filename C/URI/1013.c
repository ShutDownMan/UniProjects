#include <stdio.h>
#include <math.h>

// Function to get the greatest of 2 numbers
int greaterThan(int a, int b) {
	return ((a+b+abs(a-b))/2);
}

int main() { // Função principal.

	// Input/Output variables
	int a, b, c, gNum;

	// get a, b, c
	scanf("%d %d %d", &a, &b, &c);

	// Get greatest of a and b
	gNum = greaterThan(a, b);
	// Get greatest of greatest and c
	gNum = greaterThan(gNum, c);

	// Print result
	printf("%d eh o maior\n", gNum);
}

