#include <stdio.h>
#include <string.h>

int main()
{
	char s[2][128];
	while(scanf("%s %s", s[0], s[1]) != EOF)
	{
		printf("%s\n", strstr(s[0], s[1]) ? "Resistente" : "Nao resistente" );
	}
}

