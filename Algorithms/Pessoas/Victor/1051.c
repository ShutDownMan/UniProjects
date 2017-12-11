#include <stdio.h>

int main()
{
    double sal, somaTotal = 0;

    scanf("%lf", &sal);

    somaTotal += (sal <= 3000) ? (sal-2000) * 0.08 :
            (
                (sal < 4500) ? (sal - 3000) * 0.18 + 80 : 
                (
                    (sal - 4500) * 0.28 + 350
                )
            );
    (sal-2000 <= 0 ) ? printf("Isento\n") : printf("R$ %.2lf\n", somaTotal);

    return 0;
}