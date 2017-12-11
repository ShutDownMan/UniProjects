#include <stdio.h>

int main() {

	double pos[2];

	scanf("%lf %lf", &pos[0], &pos[1]);

	if(pos[1] == 0.0 && pos[0] == 0.0)
	{
		printf("Origem\n");
		return 0;
	}

	if(pos[0] == 0)
	{
		printf("Eixo Y\n");
		return 0;
	}

	if(pos[1] == 0)
	{
		printf("Eixo X\n");
		return 0;
	}

	if(pos[0] > 0)
	{
		if(pos[1] > 0)
		{
			printf("Q1\n");
		}
		
		if(pos[1] < 0)
		{
			printf("Q4\n");
		}
	}
	
	if(pos[0] < 0)
	{
		if(pos[1] > 0)
		{
			printf("Q2\n");
		}
		
		if(pos[1] < 0)
		{
			printf("Q3\n");
		}
	}

	return 0;
}