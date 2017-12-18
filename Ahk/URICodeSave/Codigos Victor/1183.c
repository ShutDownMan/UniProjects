#include <stdio.h>

int main(){
    double M[12][12],soma = 0.0;
    int i,j,lin,col,k;
    char s[5];

//    scanf("%d %d",&lin,&col); tira esse
    scanf(" %c",&s);

    for(i=0;i<12;i++)
        for(j=0;j<12;j++)
            scanf("%lf",&M[i][j]);

    if(lin != col) return 0;
    for(i=k=0;i<12;i++){
        for(j=i+1;j<12;j++){
            soma += M[i][j];
            k++; //aumenta o k aqui
        }
    }
    if(s[0] == 'M') soma = soma/k;
    printf("%.1lf\n",soma);
}