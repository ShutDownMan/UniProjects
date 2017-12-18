#include <stdio.h>
#include <math.h>

void arrayMaker(int size, int array[size][size]);
void printer(int size, int array[size][size]);

int main()
{
	int size;
	scanf("%d", &size);

	while(size)
	{
		int array[size][size];
		arrayMaker(size, array);
		printer(size, array);
		scanf("%d", &size);
	}

	return 0;
}
void arrayMaker(int size, int array[size][size])
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for ( j = 0; j < size; ++j)
		{
				array[i][j] = (int) fmin( fmin(size-j, size-i), fmin(i+1, j+1));
		}
	}
}

void printer(int size, int array[size][size])
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for ( j = 0; j < size; ++j)
		{
			if (j) printf(" ");
				printf("%3d", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
