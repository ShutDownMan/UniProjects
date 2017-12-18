#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, r;

    scanf("%d",&n);

    for (i=0; i<10001; i++)
    {

        if ( i%n == 2)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
