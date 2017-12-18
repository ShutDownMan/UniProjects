#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x,y;

    scanf("%d %d",&x,&y);

    while((x != y)){
        if(x > y) 
            printf("Decrescente\n");
        if(x < y)
            printf("Crescente\n");
        scanf("%d %d",&x,&y);
    }
    return 0;
}