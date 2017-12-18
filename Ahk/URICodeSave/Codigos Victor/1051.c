#include <stdio.h>
#include <math.h>

int main (){

    double sal;
    bool bottom = 0;

    scanf("%lf", &sal);
	if (sal < 0)
	{
		bottom = 1;
	}

    if (sal <= 2000 && sal >= 0)
    {
        bottom = 1;
        printf("Isento\n");
    }

    if (sal <= 3000 && bottom != 1)
    {
        bottom = 1;
        printf("R$ %.2lf\n", (sal-2000)*0.08);
    }

    if (sal <= 4500 && bottom != 1)
    {
        bottom = 1;
        printf("R$ %.2lf\n", (sal-3000)*0.18 + 80);
    }

    if (bottom != 1)
    {
        printf("R$ %.2lf\n", (sal-4500)*0.28 + 350);
    }

    return 0;
}