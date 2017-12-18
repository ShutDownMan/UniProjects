#include <stdio.h>
#include <string.h>

int vocalize(char *d, char *s);
int revert(char * s);

int main()
{
	int i;
	char src[51], vocal[51];

	fgets(src, 51, stdin);
	vocalize(vocal, src);
	if(revert(vocal))	printf("S\n");
	else	printf("N\n");
}

int vocalize(char *d, char *s)
{
	int i, j;
	for (i = j = 0; s[i]; ++i)
	{
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') d[j++] = s[i];
	}
	d[j] = 0;
	return j;
}

int revert(char * s)
{
	int lim = strlen(s)-1, i;
	char d[lim+1];
	d[lim+1] = 0;
	for (i = lim; i ; --i)
	{
		d[lim-i] = s[i];
	}
	for (i = 0; i < lim ; ++i)
	{
		if(s[i] != d[i]) return 0;
	}
	return 1;
}