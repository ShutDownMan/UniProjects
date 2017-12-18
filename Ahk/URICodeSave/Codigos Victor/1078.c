#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, r;

    scanf("%d",&n);

    for (i=1; i<=10; i++)
    {
        printf("%d x %d = %d\n", i, n, i * n);
    }
    return 0;
}
