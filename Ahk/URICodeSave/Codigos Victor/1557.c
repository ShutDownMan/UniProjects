#include <stdio.h>
#include <math.h>

#define MAX 15

void printer(int size, int mat[MAX][MAX]);
void matrixMaker(int size, int mat[MAX][MAX]);

int main()
{
	int size, mat[MAX][MAX];

	scanf("%d", &size);
	while(size)
	{
	    matrixMaker(size, mat);
		printer(size, mat);
		scanf("%d", &size);
	}
}

void printer(int size, int mat[MAX][MAX])
{
	int i, j;
	int spaces = log10(pow(2, 2*size-2))+1;

	for (i = 0; i < size; ++i)
	{

		for ( j = 0; j < size; ++j)
        {
            if(j) putchar(' ');
            printf("%*d", spaces, mat[i][j]);
        }
		putchar('\n');
	}
	putchar('\n');
}

void matrixMaker(int size, int mat[MAX][MAX])
{
	int i, j, aux;

	for (i = 0; i < size; ++i)
	{
		aux = pow(2, i);
		for ( j = 0; j < size; ++j)
		{
            mat[i][j] = aux;
			aux *=2;
		}
	}
}
