#include <stdio.h>

void printer(int size);

int main()
{
	int size;
	while(scanf("%d", &size) != EOF)
	{
		printer(size);
	}
	return 0;
}

void printer(int size)
{
	int i, j, aux;
	for (i = 0; i < size; ++i)
	{
		for ( j = 0; j < size; ++j)
		{
			if(i == j && i + j != size-1)	printf("1");
			if(i + j == size -1)	printf("2");
			if(i + j != size -1 && i != j)	printf("3");
		}
		printf("\n");
	}
}