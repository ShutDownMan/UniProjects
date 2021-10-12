#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256

int main()
{
    int i, j, len;
    char text[MAX_STR] = {0};
    char stripped_text[MAX_STR] = {0};

    fgets(text, MAX_STR, stdin);
    
    len = strlen(text);
    for (i = j = 0; i < len; i++)
    {
        if(text[i] - ' ') {
            stripped_text[j++] = text[i];
        }
    }
    
    stripped_text[j] = '\0';
    printf("%s", stripped_text);
}