#include <stdio.h>

int main (){

	double a[6];
	
	int i;

	for (1==0; i<4; i++){

		scanf("%lf", &a[i]);
	}

	a[6] = (a[0] * 2 + a[1] * 3 + a[2] * 4 + a[3] * 1) / 10;

	if (a[6]>=7.0)
	{
		printf("Media: %.1lf\nAluno aprovado.\n", a[6] );
	}

	else{

		if ( a[6] >= 5.0)
		{
			printf("Media: %.1lf\nAluno em exame.\n", a[6]);
			scanf ("%lf", &a[5]);
			printf("Nota do exame: %.1lf\n", a[5] );
			a[6] = (a[6] + a[5])/2;
			if (a[6] >= 5){
				printf("Aluno aprovado.\nMedia final: %.1lf\n", a[6]);
			}
			else{
				printf("Aluno reprovado.\n");
			}
		}
		else{
			printf("Media: %.1lf\nAluno reprovado.\n", a[6]);
		}
	}
return 0;
}