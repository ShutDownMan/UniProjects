#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char *presente;
    int preferencia;
    float valor;

}LISTA;

void showinfo(LISTA *lp, int n, float orcamento){
    int i;
    for( i =0 ; i < n; i++){
        printf("%s", (orcamento - lp[i].valor > 0) ? "*":"");
        orcamento -= lp[i].valor;
        printf("%s - R$%.2f\n", lp[i].presente, lp[i].valor);
    }
}

void ordem(LISTA *lp, int n){
   LISTA temp;
    int i,j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j && lp[i].preferencia > lp[j].preferencia ){
                temp = lp[i];
                lp[i] = lp[j];
                lp[j] = temp;
            }else if(i != j && lp[i].preferencia == lp[j].preferencia){
                if(lp[i].valor > lp[j].valor){
                    temp = lp[i];
                    lp[i] = lp[j];
                    lp[j] = temp;
                }else if(lp[i].valor == lp[j].valor){
                    if(strcmp(lp[i].presente, lp[j].presente) < 0){
                        temp = lp[i];
                        lp[i] = lp[j];
                        lp[j] = temp;
                    }
                }
            }
        }
    }
}

LISTA *lerdados(LISTA *lp, int *n, float *orcamento){
    int i = 0;

    lp=(LISTA *)malloc (sizeof(LISTA)* 100);
    scanf("%f%*c", orcamento);
    while(1){
        lp[i].presente = (char *)malloc(sizeof(char)*100);
        
        scanf("%[^\n]%*c", lp[i].presente);
        if(lp[i].presente [0]){
            scanf("%f %d%*c", &lp[i].valor, &lp[i].preferencia);
            i++;
        }else{
            break;
        }
    }
    *n = i;

    return lp;
}
void freelista(LISTA *natal, int n){ 
    int i;
    for(i = 0; i < 0; i++){
        free(natal[i].presente);
    }
    free(natal);
}

int main (){
    LISTA *natal = NULL;
    int n; float orcamento;

    natal = lerdados(natal, &n, &orcamento);
    ordem(natal, n);
    showinfo(natal, n, orcamento);
    freelista(natal,n);
    
    return 0;
}