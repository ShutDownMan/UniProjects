#include <stdio.h>

int main() {
    int n = 0, j = 0, ledsUsed = 0;
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    char currNum[1000];

    scanf("%d", &n);

    for(int i = 0;i < n; i++){
        scanf("%s", currNum);

        j = 0;
        while(currNum[j] != '\0'){
            ledsUsed += leds[currNum[j]-'0'];
            j++;
        }

        printf("%d leds\n", ledsUsed);

        ledsUsed = 0;
    }
    return 0;
}