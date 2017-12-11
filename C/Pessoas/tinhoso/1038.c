#include<stdio.h>
 int main (){

    int a,b;

    scanf("%d%d",&a,&b);

    if(a == 1){
        printf("Total: R$ %.2f\n",b*4.00);
     }
    if(a == 2){
        printf("Total: R$ %.2f\n",b*4.50);
    }
    if(a == 3){
        printf("Total: R$ %.2f\n",b*5.00);
    }
    if(a == 4){
        printf("Total: R$ %.2f\n",b*2.00);
    }
    if(a == 5){
        printf("Total: R$ %.2f\n",b*1.50);
    }
    return 0;
 }