 #include <stdio.h>
#include <math.h>

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}

int main()
{
    int x1, x2, y1, y2, r1, r2;
    while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF)
    {
        if(r1>= dist( x1, y1, x2, y2)+ r2)
        {
            printf("RICO\n");
        }
        else
        {
            printf("MORTO\n");
        }
    }
    return 0;
}