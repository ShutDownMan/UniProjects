#include <stdio.h>
#include <math.h>

void scanner();
double operate(char operation, int line);

double matrix[12][12];

int main ()
{
	int line;
	char operation;

	scanf("%d %c", &line, &operation);

	scanner();
	printf("%.1lf\n", operate(operation, line));
}

void scanner()
{
	int i, j;
	for (i = 0; i < 12; ++i)
	{
		for ( j = 0; j < 12; ++j)
		{
			scanf("%lf", &matrix[i][j]);
		}
	}
}
double operate(char operation, int line)
{
	double sum = 0;
	int i;
	for ( i = 0; i < 12; ++i)
	{
		sum += matrix[line][i];
	}
	if(operation == 'S') return sum;
	return sum/12;
}