#include <stdio.h>
#include <math.h>

int main (){

	int s[2], e[2];

	scanf(" %d %d %d %d", &s[0], &s[1], &e[0], &e[1]);

	s[1] = s[0]*60+s[1];
	e[1] = e[0]*60+e[1];

	if (s[1]>=e[1])
	{
		e[1] = e[1]+1440;
	}

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (e[1]-s[1])/60, (e[1]-s[1])%60  );

	return 0;
}