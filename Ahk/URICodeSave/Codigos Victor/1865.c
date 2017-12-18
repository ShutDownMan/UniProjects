#include <stdio.h>
#include <string.h>

int compare(char *s)
{
	char t[7] = {"Thor \0"};
	int i;
	for (i = 0; i < 5; ++i)
	{
//		printf("%c %c\n",s[i], t[i] );
		if(s[i] != t[i]) return 0;
	}
	return 1;
}

int main()
{
	char s[1000];
	int n, i;
	scanf("%d", &n);
	gets(s);
	for (i = 0; i < n; ++i)
	{
		gets(s);
		compare(s) ? printf("Y\n") : printf("N\n");
	}
}