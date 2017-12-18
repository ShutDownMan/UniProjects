#include <stdio.h>
#include <string.h>

int main()
{
	char s[35] = {"LIFE IS NOT A PROBLEM TO BE SOLVED\0"};
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n && i < 34; ++i)
	{
		printf("%c",s[i] );
	}
	printf("\n");
}