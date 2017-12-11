#include <stdio.h> // Biblioteca para funções de input e output (entrada e saída de dados).
#include <string.h> 

int main() { // Função principal.

	double n[4], exame, media, mediaFinal;

	scanf("%lf %lf %lf %lf", &n[0], &n[1], &n[2], &n[3]);

	media = (2*n[0] + 3*n[1] + 4*n[2] + 1*n[3])/10.0;

	printf("Media: %.1lf\n", media);

	if(media >= 7.0){
		printf("Aluno aprovado.\n");
	}

	if(media < 5.0){
		printf("Aluno reprovado.\n");
	}

	if(media >= 5.0 && media < 7.0){
		printf("Aluno em exame.\n");

		scanf("%lf", &exame);

		mediaFinal = (media + exame) / 2.0;

		printf("Nota do exame: %.1lf\n", exame);

		if(mediaFinal >= 5.0){
			printf("Aluno aprovado.\n");
		}
		else
		{
			printf("Aluno reprovado.\n");
		}

		printf("Media final: %.1lf\n", mediaFinal);		

	}

	return 0;
}