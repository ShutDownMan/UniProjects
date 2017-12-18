#include <stdio.h>
#include <math.h>

int findSmallest(int *array, int size);

int main ()
{
	int size, pos = 0, i;

	scanf("%d", &size);

	int array[size];

	for ( i = 0; i < size; ++i)	scanf("%d", &array[i]);

	pos = findSmallest(array, size);

	printf("Menor valor: %d\nPosicao: %d\n", array[pos], pos);

	return 0;
}

int findSmallest(int *array, int size)
{
	int i, pos = 0, current = array[0];
	for (i = 1; i < size; ++i)
	{
		if(array[i] < current)
		{
			current = array[i];
			pos = i;
		}
	}
	return pos;
}