#include <stdio.h>

int main()
{
	int paraNatal = 360, mes, dia, offset[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
	
	while(scanf("%d %d", &mes, &dia) != EOF)
	{
		paraNatal = 360 - (offset[mes-1]+dia);
		if(paraNatal == 1)	printf("E vespera de natal!\n");
		if(paraNatal < 0)	printf("Ja passou!\n");
		if(paraNatal == 0)	printf("E natal!\n");
		if(paraNatal > 1)	printf("Faltam %d dias para o natal!\n", paraNatal);
	}
	return 0;
}