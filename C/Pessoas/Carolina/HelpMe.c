#include <stdio.h>

int swap(int *x, int *y){
    *x += *y;
    *y = *x - *y;
    *x -= *y;
}

int inverter_vetor(int *v, int tam) {
    if(tam > 1) {
        swap(&v[0], &v[tam-1]);
        inverter_vetor(v+1, tam-2);
    }
}

int inverter_vetor1(int v[], int ii, int f){
    if(ii<f){
        swap(&v[ii], &v[f-1]);
        inverter_vetor1(v, ii+1, f-1);
    }
}

void imprime_vetor(int v[]){
    int i;
    for(i=0 ; i<4 ; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int vet[4] = {1,2,3,4};

    imprime_vetor(vet);

    inverter_vetor1(vet, 0, 4);
    imprime_vetor(vet);
}