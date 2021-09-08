#include <stdio.h>
#include <stdlib.h>

void solveMatrix(int rows, int cols, int initY, int initX)
{
	int **mat = (int**) malloc(sizeof(int *) * rows);
	int i, j;

	for (i = 0; i < rows; ++i)
	{
		mat[i] = (int*) malloc(sizeof(int) * cols);
		for (j = 0; j < cols; ++j)
		{
			scanf(" %d ", &mat[i][j]);
		}
	}

	char foundWay = 0;
	int curX, curY;

	curY = initY - 1;
	curX = initX - 1;
	mat[curY][curX] = 0;
	do
	{
		foundWay = 0;

		// Mexendo Y
		for (i = curY - 1; i <= curY + 1; ++i)
		{
			if (i >= 0 && i < rows)
			{
				if (mat[i][curX])
				{
					mat[i][curX] = 0;
					curY = i;
					foundWay = 1;
				}
			}
		}

		if (!foundWay)
		{
			// Mexendo X
			for (i = curX - 1; i <= curX + 1; ++i)
			{
				if (i >= 0 && i < cols)
				{
					if (mat[curY][i])
					{
						mat[curY][i] = 0;
						curX = i;
						foundWay = 1;
					}
				}
			}
		}

	} while (foundWay);

	printf("%d %d\n", curY + 1, curX + 1);
}

int main(void)
{
	int rows, cols;
	int initY, initX;

	scanf("%d %d ", &rows, &cols);
	scanf("%d %d ", &initY, &initX);

	solveMatrix(rows, cols, initY, initX);
}