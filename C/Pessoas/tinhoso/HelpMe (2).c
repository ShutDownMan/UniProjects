#include <stdio.h>

void swap(int &a, int &b) {

}

void troca(int vet[],int tam ){
    if(tam > 2) {
        troca(vet,tam-1);
        printf("%d",vet[tam-1]);
    }
}

int main (){
    int c[5]={1,2,3,4,5};

    troca(c, 5);

}