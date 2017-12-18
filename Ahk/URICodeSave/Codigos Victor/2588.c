#include <stdio.h>
#include <string.h>

void count(int x[], char s[]);
int process(int * x);

int main()
{
	char s[1001];
	while(scanf("%s", s) != EOF)
	{
		int letters[26] = {0};
		count(letters, s);
		printf("%d\n", process(letters));
	}
}

void count(int x[], char s[])
{
	int i;
	for (i = 0; s[i]; ++i)
	{
		x[s[i]-'a'] += 1;
	}
}
int process(int * x)
{
	int i, aux;
	for (aux = i = 0; i < 26; ++i)
	{
		aux += x[i] %2;
	}
	aux--;
	if(aux > 0) return aux;
	return 0;
}