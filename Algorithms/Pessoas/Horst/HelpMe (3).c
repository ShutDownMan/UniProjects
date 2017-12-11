#include <stdio.h>
#define MAX 100


int lerVetor(int vetor[], int* tam){
    int i;

    scanf("%d", tam);

    for (i = 0; i < *tam; ++i)
    {
        scanf("%d", &vetor[i]);
    }
}

void printVetor(int vetor[], int tam){
    int i;

    for (i = 0; i < tam; ++i)
    {
        printf("V[%d] = %d\n", i, vetor[i]);
    }
}

void mediaVetor(int vetor[], int tam, float* media){
    int i;
    float soma = 0;

    for ( i = 0; i < tam; i++)
    {
        soma += vetor[i];
    }

    *media = soma/tam;

    printf("MEDIA = %g\n\n", *media);

}

void downVetor (int vetor[], int tam){
    int i, down = 0;

    for (i = 1; i < tam; i++){

        if(vetor[i] < vetor[down]){
            down = i;
        }
    }

    printf("MENOR = %d\n\n", vetor[down]);
}

int upvetor (int vetor[], int tam){
    int i, up = 0;

    for(i = 1; i < tam; i++){
        if (vetor[i] > vetor[up])
            up = i;
        
    }

    return up;
}

void upMediaVetor (int vetor[], int tam, float media){
    int i,j = 0;
    printf("NUMEROS MAIORES QUE A MEDIA:\n");
    for (i = 0; i < tam; i++){

        if(vetor[i] > media){
            printf("VETOR[%d] = %d\n", j, vetor[i]);
            j++;
        }
    }

    printf("----------------------\n");
}

void first(int vetor[], int tam){
    int i, temp = 0, up;

    up = upvetor(vetor, tam);

    if (vetor[i] < vetor[up])
    {
        temp = vetor[0];
        vetor[0] = vetor[up];
        vetor[up] = temp;    
    }
}

void orderVetor (int vetor[], int tam){
    int i;

    for (i = 0; i < tam; i++){
        first (&vetor[i], tam-i);
    }

    printf("VETOR ORDENADO:\n");
    printVetor(vetor, tam);
}


int main(){
    int vetor[MAX], tam;
    float media = 0;

    lerVetor(vetor, &tam);

    printVetor(vetor, tam);
    mediaVetor(vetor, tam, &media);
    downVetor(vetor, tam);
    upMediaVetor(vetor, tam, media);

    
    orderVetor(vetor, tam);

	return 0;
}