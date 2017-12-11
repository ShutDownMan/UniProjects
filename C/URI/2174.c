#include <stdio.h>

int CalcPokeVal(char pokeName[]);

int Contains(int val, int list[], int length);

int main(int argc, char const *argv[])
{
	int n, i;
	char currPokemon[1000];

	scanf("%d", &n);

	int pokePegos = n, pokeList[n];
	int pokeVal;

	for(i = 0; i < n; ++i)
	{
		scanf("%s", currPokemon);

		pokeVal = CalcPokeVal(currPokemon);

		//printf("Resultado: %d\n", pokeVal);

		if(Contains(pokeVal, pokeList, n)) {
			pokePegos--;
		} else {
			pokeList[i] = pokeVal;
		}

		//printf("Pokes Pegos: %d\n", pokePegos);

	}

	printf("Falta(m) %d pomekon(s).\n", 151-pokePegos);

	return 0;
}

int CalcPokeVal(char pokeName[]) {
	int result = 1, i = 0;

	for (i = 0; pokeName[i] != '\0'; ++i)
	{
		result *= pokeName[i];
	}

	return result;
}

int Contains(int val, int list[], int length) {
	int i;

	for (i = 0; i < length; ++i)
	{
		if (val == list[i])
		{
			return 1;
		}
	}

	return 0;
}