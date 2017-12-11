#include <stdio.h>
#include <string.h>

int GetCQuant(char foodName[]);

char tableNames[7][16] = {
	{"suco de laranja"},
	{"morango fresco"},
	{"mamao"},
	{"goiaba vermelha"},
	{"manga"},
	{"laranja"},
	{"brocolis"}
};

char tableValues[7] = {
	120,
	85,
	85,
	70,
	56,
	50,
	34
};

int main(int argc, char const *argv[])
{
	int n, i;

	int cDoDia;

	int curQuant = 0;
	char curFood[16];

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;
		}

		cDoDia = 0;

		for (i = 0; i < n; ++i)
		{
			scanf("%d %s", &curQuant, &curFood);

			cDoDia += GetCQuant(curFood) * curQuant;
		}

		//printf("Vit C do dia: %d\n", cDoDia);

		if(cDoDia > 130) {
			printf("Menos %d mg\n", cDoDia-130);
			continue;
		}

		if(cDoDia < 110) {
			printf("Mais %d mg\n", 110-cDoDia);
			continue;
		}

		printf("%d mg\n", cDoDia);
	}

	return 0;
}

int GetCQuant(char foodName[]) {
	int i;

	for (i = 0; i < 7; ++i)
	{
		if(strcmp(foodName, tableNames[i]) == 0) {
			return tableValues[i];
		}
	}
	return 0;
}