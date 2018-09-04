#include <stdio.h>
#include <string.h>

int main() {
    int i, n;
    char str[21];

    scanf("%d ", &n);
    for(i = 0; i < n; i++) {
        scanf(" %s", str);

        if(strlen(str)==3) {
            if((str[0]=='U' && str[1]=='R') || (str[0]=='O' && str[1]=='B')) {
                str[2] = 'I';
            }
        }
        printf("%s", str);
        if(i+1 < n) printf(" ");
    }
    printf("\n");
}