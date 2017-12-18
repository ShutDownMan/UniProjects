#include <stdio.h>
#include <ctype.h>

int evaluate(char *s);

int main()
{
	char s[1024];

	while(!feof(stdin)) evaluate(gets(s)) ? printf("Senha valida.\n") : printf("Senha invalida.\n");
}

int evaluate(char *s)
{
	int i;
	char A, a, num;

	for ( i = A = a = num = 0; s[i] ; ++i)
	{
		if(!isalnum(s[i])) return 0;
		if(isupper(s[i])) A = 1;
		else if(islower(s[i])) a = 1;
		else if(isdigit(s[i])) num = 1;
	}
	if(A && a && num && i >= 6 && i <= 32) return 1;
	return 0;
}