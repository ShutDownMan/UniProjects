#include <stdio.h>
#include <math.h>

int main ()
{
	long long int hex, pen, ligs, count = 0;
	while(scanf("%Ld %Ld", &pen, &hex) != EOF)
	{
		count++;
		ligs = (5*pen+6*hex)/2;
		printf("Molecula #%Ld.:.\nPossui %Ld atomos e %Ld ligacoes\n\n", count, ligs-hex-pen+2, ligs);
	}
	return 0;
}
