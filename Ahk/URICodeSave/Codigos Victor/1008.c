#include <stdio.h>
int a, b;
double c;

int main ()
{
     scanf( "%d%d%lf", &a, &b, &c);
     printf( "NUMBER = %d\nSALARY = U$ %.2lf\n", a, b * c );
     return 0;
}
