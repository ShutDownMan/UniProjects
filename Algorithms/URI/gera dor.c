#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int r = 1000;

    for (int j = 0; j < 10000; ++j)
    {
        for (int j = 0; j < 2; ++j)
        {
            int k = 2,temp[k];
            for ( k = 0; k < 2; ++k)
            {
                temp[k] = rand() %999 +1;
            }
            for ( k = 0; k < 2; ++k)
            {
                printf(" %d", rand() %temp[k] );
            }
            for (k = 0; k < 2; ++k)
            {
                printf(" %d", temp[k] );
            }
        }
        printf("\n");
    }

    return 0;
}