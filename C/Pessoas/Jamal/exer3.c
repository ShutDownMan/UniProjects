#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255
typedef struct fly{
	char id[MAX];
	char marca[MAX];
	char destino[MAX];
	char hora[MAX];
	char posicao[MAX];
    char chegada[MAX];
}fly;

void limpastdin()
{
  char c;
  while ((c = getchar() != '\n' && c != EOF));
}

void lervoo(fly V[MAX]){
	int i=0;

	FILE *arq;
	arq = fopen("voo.txt","r");

	while(!feof(arq))
	{
		fscanf(arq, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);
		//fscanf(arq, "%*c");	
		i++;
	}
   fclose(arq);
}

void Interface()
{
	printf("Digite 1 - para alterar o id\n");
	printf("Digite 2 - para alterar a empresa\n");
	printf("Digite 3 - para alterar o destino\n");
	printf("Digite 4 - para alterar a hora\n");
	printf("Digite 5 - para alterar a poricao\n");
	printf("Digite 6 - para alterar a chegada\n");
	printf("Digite outro valor - para voltar ao menu principal\n");
}

void Interface2()
{
	printf("Digite 1 - para verificar uma linha aerea\n");
	printf("Digite 2 - para verificar uma informacao\n");
	printf("Digite outro valor - para sair do programa\n");
}

void alteravoo(fly V[MAX]){
	char X[MAX];
	int i, x;
	int flag = 0;
	
	scanf("%[^\n]s", X);
	limpastdin();

	if(strcmp(X, "sair") == 0)
	{
		return;
	}

	for (i=0;i<118;i++)
    {
    	if (strcmp(V[i].id, X) == 0)
    	{
    		flag = 1;
    		break;
    	}
    }
  
    if(flag == 1)
    {
    	while(1)
    	{
    		system("cls");
    		printf("A linha aerea e:\n");
    		printf("%s;%s;%s;%s;%s;%s\n\n", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);
    		Interface();
    		scanf("%d", &x);
    		limpastdin();
    		switch(x)
    		{
    			case 1:
    			{
    				system("cls");
    				printf("digite o id\n");
   	 			    scanf("%[^\n]s", V[i].id);
    				limpastdin();
    				break;
    			}
    			case 2:
    			{
    				system("cls");
    				printf("digite o marca\n");
    				scanf("%[^\n]s", V[i].marca);
  	  				limpastdin();
  		  			break;
  		  		}
    			case 3:
    			{
    				system("cls");
    				printf("digite o destino\n");
    				scanf("%[^\n]s", V[i].destino);
    				limpastdin();
    				break;
    			}
    			case 4:
    			{
    				system("cls");
    				printf("digite o hora\n");
    				scanf("%[^\n]s", V[i].hora);
    				limpastdin();
    				break;
    			}
    			case 5:
    			{
    				system("cls");
    				printf("digite o posicao\n");
    				scanf("%[^\n]s", V[i].posicao);
    				limpastdin();
    				break;
    			}
    			case 6:
    			{
    				system("cls");
    				printf("digite o chegada\n");
    				scanf("%[^\n]s", V[i].chegada);
    				limpastdin();
    				break;
    			}
    			default:
    			{
    				return;
   				}
   			}
   		}
	}
	else
	{
		system("cls");
		printf("ID invalido, digite um novo ID\n");
		printf("Para sair digite a palavra 'sair'\n");
	 	alteravoo(V);
	}
}
	
void infovoo(fly V[MAX]){
	char X[MAX]; int i=0; int flag = 0;
	
	X[0] = '\0';
	system("cls");
	printf("Digite a informacao\n");
	scanf("%[^\n]s", X);
	limpastdin();	
	system("cls");
	printf("As linhas aereas com a informacao '%s':\n\n", X);

	for(i = 0; i<118; i++)
	{
		if(strcmp((V[i].marca),(X))==0)
		{
 			printf("\n%s;%s;%s;%s;%s;%s\n", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);	
   			flag = 1;
		}
		else if(strcmp((V[i].destino),(X))==0)
   		{
   			printf("%s;%s;%s;%s;%s;%s\n", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);
   			flag = 1;
		}	
		
		else if(strcmp((V[i].hora),(X))==0)
  		{
  			printf("%s;%s;%s;%s;%s;%s\n", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);
  			flag = 1;
		}	
		else if(strcmp((V[i].posicao),(X))==0)
    	{
    		printf("%s;%s;%s;%s;%s;%s\n", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);
    		flag = 1;
		}
		else if(strcmp((V[i].chegada),(X))==0)
    	{
    		printf("%s;%s;%s;%s;%s;%s\n", V[i].id, V[i].marca, V[i].destino, V[i].hora, V[i].posicao, V[i].chegada);
    		flag = 1;
		}
	}	

	if (flag == 0)
	{
		system("cls");
		printf("Informacao invalida\n");
		printf("\n\nPressione enter para voltar ao menu principal\n");
		getchar();
	}

	if (flag == 1)
	{
		printf("\n\nPressione enter para voltar ao menu principal\n");
		getchar();
	}
}

int main(){
	fly VG[MAX];
	int x;

	lervoo(VG);
	
	while (1)
	{
		system("cls");
		Interface2();
		scanf("%d", &x);
		limpastdin();
		switch(x)
		{
			case 1:
			{
				system("cls");
				printf("Digite o ID do voo para verificar a linha aerea\n");
				printf("Para sair digite a palavra'sair'\n");
				alteravoo(VG);
				break;		
			}
			case 2:
			{
				system("cls");
				infovoo(VG);
				break;
			}
			default:
			{
				system("cls");
				return 0;
			}
		}
	}
}