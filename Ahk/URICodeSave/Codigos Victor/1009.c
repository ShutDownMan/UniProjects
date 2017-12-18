#include <stdio.h>
double a, b;

int main ()
{
     scanf( "%*s%lf%lf", &a, &b);
     printf( "TOTAL = R$ %.2lf\n", a + b * 0.15 );
     return 0;
}
