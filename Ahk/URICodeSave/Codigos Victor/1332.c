#include <stdio.h>
#include <string.h>

int main()
{
    char s[6], comp[3][6] = {"one", "two", "three"};
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", s);
        if(strlen(s) > 3)   printf("3\n");
        else if( (s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e') >= 2) printf("1\n");
        else printf("2\n");
    }
}
