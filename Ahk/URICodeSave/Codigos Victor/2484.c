#include <stdio.h>
#include <string.h>

void printer(char s[]);

int main()
{
	char s[101];
	while(scanf("%s", &s) != EOF)	printer(s);
}

void printer(char s[])
{
	int i, j, lim = strlen(s);
	for ( i = 0; i < lim; ++i)
	{
		for (j = 0; j < i; ++j)	printf(" ");
		for (j = 0; s[j]; ++j)	s[j+1] ? printf("%c ",s[j]) : printf("%c", s[j]);
		s[j-1] = 0;
		printf("\n");
	}
	printf("\n");
}