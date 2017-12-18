#include <stdio.h>
#include <math.h>


int main ()
{
	int x = 0, alc = 0, gas = 0, die = 0;

	while(x != 4)
	{
		scanf("%d", &x);

		switch(x)
		{
			case 1:
			{
				alc++;
				break;
			}
			case 2:
			{
				gas++;
				break;
			}
			case 3:
			{
				die++;
				break;
			}
		}
	}
	printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", alc, gas, die);

	return 0;
}
