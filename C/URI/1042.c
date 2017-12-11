#include <stdio.h>

void swap(int *x, int *y);

int main() {

	int input[3], toSort[3];

	int n = 3, i = 0;

	scanf("%d %d %d", &input[0], &input[1], &input[2]);

	for (i = 0; i < 3; ++i)
	{
		toSort[i] = input[i];
	}

	if(toSort[1] < toSort[0]) {
		swap(&toSort[0], &toSort[1]);
	}

	if(toSort[2] < toSort[1]) {
		swap(&toSort[1], &toSort[2]);
	}

	if(toSort[1] < toSort[0]) {
		swap(&toSort[0], &toSort[1]);
	}

	// Print the ordered array
	for (i = 0; i < n; ++i)
	{
		printf("%d\n", toSort[i]);
	}

	printf("\n");

	// Print the input array
	for (i = 0; i < n; ++i)
	{
		printf("%d\n", input[i]);
	}

	return 0;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}