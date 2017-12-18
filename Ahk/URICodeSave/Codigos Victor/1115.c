#include <stdio.h>

double x, y;

int main () {

	scanf("%lf%lf", &x, &y);

	while(x!=0 && y!=0)
	{
		if (y>0)
		{
			if(x>0)
			{
				printf("primeiro\n");
			}
			else
			{
				printf("segundo\n");
			}
		}
		if (y<0)
		{
			if(x>0)
			{
				printf("quarto\n");
			}
			else
			{
				printf("terceiro\n");
			}
		}
		scanf("%lf%lf", &x, &y);
	}


return 0;
}