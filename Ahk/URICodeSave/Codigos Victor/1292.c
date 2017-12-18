#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846264338

int main(int argc, char const *argv[])
{
    double in_pLength, out_sqrLength;

    while(scanf("%lf", &in_pLength) != EOF) {
        out_sqrLength = (in_pLength) * sin(108*PI/180)/sin(63*PI/180);;
        printf("%.10lf\n", out_sqrLength);
    }

    return 0;
}