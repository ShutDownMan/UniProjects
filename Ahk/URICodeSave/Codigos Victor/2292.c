#include <stdio.h>
#include <string.h>

int toBin(int b[], char s[]);
void process(int b[], char it[],  int n);
void printer(int b[], int n);
void div(char s[], int n);

int main()
{
	int n, i, bin[61], length;
	char s[61], it[20];

	scanf("%d", &n);
	for ( i = 0; i < n; ++i)
	{
		scanf("%s %s", s, &it);
		length  = toBin(bin, s);
		process(bin, it, length);
		printer(bin, length);
	}
}

int toBin(int b[], char s[])
{
	int i;
	for (i = 0; s[i] ; ++i)		s[i] == 'X' ?	(b[i] = 0) : (b[i] = 1);
	return i;
}

void process(int b[], char it[],  int n)
{
	int i, pos = strlen(it)-1;
	for ( i = 0; i < n && it; ++i)
	{
		if(it[pos] % 2) b[i] = !b[i];
		if(it[pos] % 2 && !b[i]) it[pos]++;
		div(it, 2);
	}
}

void printer(int b[], int n)
{
	int i;
	for ( i = 0; i < n; ++i)	printf("%c", (b[i] ? 'O' : 'X') );
	printf("\n");
}

void div(char s[], int n)
{
	int i;
	for ( i = 0; s[i]; ++i)
    {
    	s[i] -= '0';
        if(s[i]%2 && s[i+1]) s[i+1] += 10;
        s[i] /= 2;
        s[i] += '0';
    }
}