#include <stdio.h>
#include <math.h>

int main (){

    double sal;
    bool bottom = 0;

    scanf("%lf", &sal);
    //printf("%lf\n", sal );

    if (sal <= 400 && sal >= 0)
    {
        bottom = 1;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 15 %%\n", sal*1.15, sal*0.15);
    }

    if (sal <= 800 && bottom != 1 && sal > 0)
    {
        bottom = 1;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 12 %%\n", sal*1.12, sal*0.12);
    }

    if (sal <= 1200 && bottom != 1 && sal > 0)
    {
        bottom = 1;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 10 %%\n", sal*1.1, sal*0.1);
    }

    if (sal <= 2000 && bottom != 1 && sal > 0)
    {
        bottom = 1;
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 7 %%\n", sal*1.07, sal*0.07);
    }

    if (bottom != 1 && sal > 0)
    {
        printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 4 %%\n", sal*1.04, sal*0.04);
    }

    return 0;
}