#include <stdio.h>

int main()
{
    int n, i;
    int a,b;
    scanf("%d", &n);
    for(i=a=b=0; i < n; i++)
    {
        scanf("%d", &b);
        //printf("a=%d b=%d\n", a, b);
        if(b<a)
        {
            printf("%d\n", i+1);
            return 0;
        }
        a = b;
    }
    printf("0\n");
}
