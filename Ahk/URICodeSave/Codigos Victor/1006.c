#include <stdio.h>
double a, b, c;

int main ()
{
     scanf( "%lf%lf%lf", &a, &b, &c);
     printf( "MEDIA = %.1lf\n", (a * 2 + b * 3 + c * 5 ) / 10);
     return 0;
}
