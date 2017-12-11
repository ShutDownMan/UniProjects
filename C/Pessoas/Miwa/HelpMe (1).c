#include <stdio.h>
#include <math.h>
#define MAXL 100
#define MAXC 100

int lermat(int mat[][MAXC], int *pl, int *pc){
    
    int i, j;
    
    scanf("%d %d", pl, pc);
    
    if((*pl == 0) && (*pc ==  0))
        
        return 0;
    
    for(i = 0; i < *pl; i++){
        
        for(j = 0; j < *pc; j++)
        
            scanf("%d", &mat[i][j]);
    }
    return 1;
}

int printvet(int v[], int col){ // n = col
    
    int i;
    
    for(i = 0; i < col; i++)
        
        printf("%4d", v[i]);
        
    printf("\n");
}

void printmat(int mat[][MAXC], int lin, int col){
    
    int i;
    
    for(i = 0; i < lin; i++)
    
        printvet(mat[i], col);
}

int somapc(int mat[][MAXC], int lin, int col){
    
    int i, s;
    
    for(i = s = 0; i < col; i++)

        s += mat[i][0];
        
    return s;    
}

int produtosl(int mat[][MAXC], int lin, int col){
    
    int j, p;
    
    for(j = 0, p = 1; j < lin; j++)
    
        p *= mat[1][j];
    
    return p;
}

int soma(int mat[][MAXC], int lin, int col){
    
    int i, j, s;
    
    for(i = s = 0; i < lin; i++){
        
        for(j = 0; j < col; j++)
        
            s += mat[i][j];
    }
    return s;
}
int somadp(int mat[][MAXC], int lin, int col){
    
    int i, s;
    
    if(lin != col)
    
        return 0;
        
    for(i = s = 0; i < lin; i++)
    
        s += mat[i][i];
    
    return s;
}

int somads(int mat[][MAXC], int lin, int col){
    
    int i, j, s;
    
    if(lin != col)
    
        return 0;
    
    for(i = s = 0, j = col-1; i < lin; i++, j--)
    
        s += mat[i][j]; // j = col-i-1
        
    return s;
}

int main(){
    
    int m[MAXL][MAXC], lin, col;
    
    while(lermat(m, &lin, &col) != 0){
    
        printmat(m, lin, col);
        
        printf("\nSoma Primeira Coluna = %d\n", somapc(m, lin, col));
        
        printf("\nProduto Segunda Linha = %d\n", produtosl(m, lin, col));
        
        printf("\nSoma Total = %d\n\n", soma(m, lin, col));
        
        printf("Soma Diagonal Principal = %d\n\n", somadp(m, lin, col));
        
        printf("Soma Diagonal Secundaria = %d\n\n", somads(m, lin, col));    
        
    }
    return 0;
}
