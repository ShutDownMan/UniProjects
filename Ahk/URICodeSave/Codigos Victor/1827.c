#include <stdio.h>

#define MAX 105

void printer    (int n, int mat[n][n]);
void generate   (int n, int mat[n][n]);

int main()
{
    int num;
    int mat[MAX][MAX];

    while(scanf("%d", &num)!= EOF)
    {
        generate(num, mat);
        printer (num, mat);
    }
}

void generate(int n, int mat[n][n])
{
    int i, j, aux = n/3-1;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++, mat[i][j]=0)
        {
            if(i == j)mat[i][j] = 2;
            if(i+j == n-1) mat[i][j] = 3;
            if( (i > aux) && (j > aux)  && (i < (n-aux-1)) && (j < (n-aux-1)) ) mat[i][j] = 1;
            if(i == j && j == n/2) mat[i][j] = 4;
        }
    }
}

void printer(int n, int mat[n][n])
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
