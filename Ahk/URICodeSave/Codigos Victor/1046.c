#include <stdio.h>
#include <math.h>

int main (){

	int s, e;

	scanf(" %d %d", &s, &e);

	if (s>=e)
	{
		e = e+24;
	}

	printf("O JOGO DUROU %d HORA(S)\n",e-s);

	return 0;
}