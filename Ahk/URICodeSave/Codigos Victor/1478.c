#include <stdio.h>
#include <math.h>

void gerarMatriz(int tamanho, int mat[tamanho][tamanho]);
void imprimir(int tamanho, int mat[tamanho][tamanho]);

int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    while(tamanho)
    {
        int mat[tamanho][tamanho];
        gerarMatriz(tamanho, mat);
        imprimir(tamanho, mat);
        scanf("%d", &tamanho);
    }
    return 0;
}

void imprimir(int tamanho, int mat[tamanho][tamanho])
{
    int i, j;
    for (i = 0; i < tamanho; ++i)
    {
        for ( j = 0; j < tamanho; ++j)
        {
            if(j>0)printf(" ");
            printf("%3d", mat[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

void gerarMatriz(int tamanho, int mat[tamanho][tamanho])
{
    int i, j;
    for (i = 0; i < tamanho; ++i)
    {
        for ( j = 0; j < tamanho; ++j)
        {
            mat[i][j] = (int)fabs(i-j)+1;
        }
    }
}
