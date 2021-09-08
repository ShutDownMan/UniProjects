#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calc_primary(int m, int arr[m][m]);

int calc_second(int m, int arr[m][m]);

int main(void)
{
    int i, j, rows, columns;

    scanf("%d%d", &rows, &columns);

    int arr[rows][columns];

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Verifica se a matriz é quadrada ou não
    if (rows != columns)
    {
        printf("A matriz nao possui traco");
    }
    else
    {
        printf("%d\n%d", calc_primary(rows, arr), calc_second(rows, arr));
    }
}

int calc_primary(int m, int arr[m][m])
{
    int i, j, sum = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == j)
            {
                sum += arr[i][j];
            }
        }
    }
    return (sum);
}

int calc_second(int m, int arr[m][m])
{
    int i, j, sum = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j == m - 1 - i)
            {
                sum += arr[i][j];
            }
        }
    }
    return (sum);
}