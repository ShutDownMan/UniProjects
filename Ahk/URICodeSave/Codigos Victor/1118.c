#include <stdio.h>

int main(int argc, char const *argv[]) {
    double current = 0, totalSum = 0;
    int totalValid = 0;
    char stopLoop = 0;

    while(1) {
        while(totalValid != 2)
        {
        	scanf("%lf", &current);
	        if(current >= 0 && current <= 10) {
	            totalSum += current;
	            totalValid++;

	        } else {
	            printf("nota invalida\n");
	        }
	    }

        if(totalValid == 2) {
            printf("media = %.2lf\n", totalSum/totalValid);

            do {
	            printf("novo calculo (1-sim 2-nao)\n");
                scanf("%lf", &current);
                if(current == 1) {
                    totalSum = 0;
                    totalValid = 0;
                    break;
                } else if(current == 2) {
                    stopLoop = 1;
                    break;
                }
            } while (1);
        }

        if (stopLoop) {
            break;
        }

    }

    return 0;
}