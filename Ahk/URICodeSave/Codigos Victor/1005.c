#include <stdio.h>
double a,b;

int main ()
{
     scanf( "%lf%lf", &a, &b);
     printf( "MEDIA = %.5lf\n", (a * 3.5 + b * 7.5 ) / 11);
     return 0;
}

