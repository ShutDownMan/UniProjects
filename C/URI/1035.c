#include <stdio.h>
#define true 1
#define false 0

char check (int a, int b, int c, int d);

int main(){
    int a, b, c, d;
    char result;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    result = check(a,b,c,d);
    
    if(result){
        printf ("Valores aceitos\n");
    } else {
        printf ("Valores nao aceitos\n");
    }

    return 0;
}

char check (int a, int b, int c, int d){
    if (b > c){
        if (d > a){
            if ((c + d) > (a + b)){
                if (c > 0 && d > 0){
                    if (a%2 == 0){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
