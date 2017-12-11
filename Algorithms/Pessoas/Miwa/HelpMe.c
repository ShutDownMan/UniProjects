#include <stdio.h>

void lervet(int v[], int n){
    
    int i;
    
    for(i = 0; i < n; i++)
    
        scanf("%d", &v[i]);
}

float media(int v[], int n){
    
    int i, m;
    
    for(i = m = 0; i < n; i++)
    {    
        m += (v[i]);
    }
    
    return (float) m/n;
}

int main(){
    
    int v[100], n, i;
    
    scanf("%d", &n);
    
    while(n){
        
        lervet(v, n);
        
        printf("MEDIA = %f\n", media(v, n));
        
        scanf("%d", &n);
    }
    
    return 0;
}