#include <stdio.h>
#include <string.h>

int forward(char d, char s);
int process(char d[], char s[]);

int main()
{
	int n, i;
	char src[10002], dst[10002];

	scanf("%d", &n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%s %s", &src, &dst);
		printf("%d\n", process(dst, src));
	}
}

int process(char d[], char s[])
{
	int i, lim = strlen(s), count;
	for (count = i = 0; i < lim; ++i)
	{
		if(s[i] != d[i]) count += forward(d[i], s[i]);
	}
	return count;
}

int forward(char d, char s)
{
	int aux;
	aux = d-s;
	if(aux < 0) aux += 26;
	return aux;
}