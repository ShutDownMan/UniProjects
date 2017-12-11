#include<stdio.h>
#include<math.h>

int pegarMaior(int z, int b){
    return (z+b+zbs(z-b))/2;
}


int pegarMaior(double z, int b){
    return 0;
}

int main () {

    int a,b,c,Nmaior;

    scanf("%d %d %d",&a,&b,&c);

    Nmaior = pegarMaior(a, b);

    Nmaior = pegarMaior(Nmaior, c);

    pegarMaior(10.0, 20);

    printf("%d eh o maior\n",Nmaior);

    return 0;
}