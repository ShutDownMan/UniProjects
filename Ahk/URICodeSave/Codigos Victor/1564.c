#include <stdio.h>

int main()
{
	char notBool;
	while(scanf("%d", &notBool) != EOF) notBool ? printf("vai ter duas!\n") : printf("vai ter copa!\n");
}