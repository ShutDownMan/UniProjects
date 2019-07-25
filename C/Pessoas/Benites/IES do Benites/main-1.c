#include "Voo.h"
#include "Participante.h"
#include "Aeronave.h"


int main(){
	Lista_Voo *l1 = malloc(sizeof(Lista_Voo)); 
	Lista_Participante *l2 = malloc(sizeof(Lista_Participante));
	Lista_Aeronave *l3 = malloc(sizeof(Lista_Aeronave));
	char consulta[50], arquivo[50];
	int a, b, n, tam, test=1;
	Voo *v;
	Participante *p;
	Aeronave *aer;
	l1->primeiro = NULL;
	l1->ultimo = NULL;
	l2->primeiro = NULL;
	l2->ultimo = NULL;
	l3->primeiro = NULL;
	l3->ultimo = NULL;
	time_t hora;
	struct tm *hora_atual; 
	time(&hora);
	hora_atual = localtime(&hora);

	while(1){
		
		printf("\n	|Aeroporto|\n");
		printf("\nSe deseja manipular a lista de voos digite 1.\n");
		printf("Se deseja manipular a lista de pessoas digite 2.\n");
		printf("Se deseja manipular a lista de aeronaves digite 3.\n");
		printf("Se deseja visualizar o painel de voos digite 4.\n");
	//	printf("Se deseja carregar um arquivo da memoria digite 3.\n");
		printf("Se deseja encerrar o programa digite 0.\n\n");
		
		scanf("%d", &a);
		scanf("%*c");
		system("cls");
		
		
		switch (a){
			
			case(0):{
				exit(1);
				break;
			}
			
			case(1):{
				test = 1;
				while(test){
					printf("\n		|Voos|\n");
					printf("\nDigite 1 para inserir um voo no final da lista\n");
					printf("Digite 2 para remover um voo no inicio da lista.\n");
					printf("Digite 3 para remover um voo no final da lista.\n");
					printf("Digite 4 para remover um voo em uma posicao especifica na lista.\n");
					printf("Digite 5 para consultar um voo na lista atraves do seu prefixo.\n");
					printf("Digite 6 para printar a lista.\n");
					printf("Digite 0 para retornar a tela de escolha das listas.\n\n");
	
					scanf("%d", &b);
					scanf("%*c");
					system("cls");
					printf("\n");
					
					switch(b){
						
						case(0):{
							test = 0;
							break;
						}
						
						case(1):{
							printf("Entre com os dados do voo.\n");
							fflush(stdin);
							v = scaneia_voo();
							if(!checa_prefixo(l1, v->prefixo)){
								insere_voo_final(l1, v);
								printf("Voo inserido.\n\n");
							}
							else{
								printf("Ja existe um voo com este prefixo na lista.\n");
							}
							break;
						}
						
						case(2):{
							if(vazia_voo(l1)){
								printf("A lista esta vazia.\n");
							}
							else{
								remove_voo_comeco(l1);
								printf("Voo removido.\n\n");
							}
							break;
						}
						
						case(3):{
							if(vazia_voo(l1)){
								printf("A lista esta vazia.\n");
							}
							else{
								remove_voo_final(l1);
								printf("Voo removido.\n\n");
							}						
							break;
						}
						
						case(4):{
							if(vazia_voo(l1)){
								printf("A lista esta vazia.\n");
							}
							else{
								printf("Entre com o numero da lista no qual esta o voo que sera removido\nNumero: ");
								scanf("%d", &n);
								fflush(stdin);
								tam = checa_tamanho_lista_voo(l1);
								while(tam < n){
									printf("A lista nao possui tamanho o suficiente para remover nesta posicao, por favor escolha outra posicao ou 0 caso nao queira remover nenhum elemento.\nNumero: ");
									scanf("%d", &n);
									printf("\n");
								}
								if(n!=0) {
									remove_voo_meio(l1, n);
									printf("Voo removido!\n");
								}else{
									printf("Nenhum voo removido!\n");
								}
								
								scanf("%*c");
								
							}						
							break;
						}
						
						case(5):{
							if(vazia_voo(l1)){
								printf("A lista esta vazia.\n");
							}
							else{
								printf("Entre com o prefixo do voo que deseja consultar\nPrefixo: ");
								fflush(stdin);
								scanf("%[^\n]%*c", consulta);
								printf("\n");
								consulta_voo(l1, consulta);
							}					
							break;
						}
						
						case(6):{
							printa_lista_voo(l1);
							break;
						}
							
							
					}			
					
					if(b!=0){
						scanf("%*c");
						system("cls");
					}
				}		
				break;
			}
			
		
			case(2):{
				
				test = 1;
				
				while(test){
					
					printf("\n		|Participantes|\n");
					printf("\nDigite 1 para inserir um participante no final da lista.\n");
					printf("Digite 2 para remover um participante no inicio da lista.\n");
					printf("Digite 3 para remover um participante no final da lista.\n");
					printf("Digite 4 para remover um participante em uma posicao especifica na lista.\n");
					printf("Digite 5 para consultar um participante na lista atraves do seu cpf.\n");
					printf("Digite 6 para printar a lista.\n");
					printf("Digite 0 para retornar a tela de escolha das listas.\n\n");
	
					scanf("%d", &b);
					scanf("%*c");
					system("cls");
					printf("\n");
					
					switch(b){
						
						case(0):{
							test = 0;
							break;
						}
						
						case(1):{
							printf("Entre com os dados da pessoa.\n");
							fflush(stdin);
							p = scaneia_participante();
							if(!checa_cpf(l2, p->cpf)){
								insere_participante_final(l2, p);
								printf("Pessoa inserida.\n\n");
							}
							else{
								printf("Ja existe um participante com este cpf.\n");
							}
							break;
						}
						
						case(2):{
							if(vazia_participante(l2)){
								printf("A lista esta vazia.\n");
							}
							else{
								remove_participante_comeco(l2);
								printf("Participante removido.\n\n");
							}
							break;
						}
						case(3):{
							if(vazia_participante(l2)){
								printf("A lista esta vazia.\n");
							}
							else{
								remove_participante_final(l2);
								printf("Participante removido.\n\n");
							}
							break;
						}
						
						case(4):{
							if(vazia_participante(l2)){
								printf("A lista esta vazia.\n");
							}
							else{
								printf("Entre com o numero da lista no qual esta o participante que sera removido\nNumero: ");
								scanf("%d", &n);
								printf("\n");
								fflush(stdin);
								tam = checa_tamanho_lista_participante(l2);
								while(tam < n){
									printf("A lista nao possui tamanho o suficiente para remover nesta posicao, por favor escolha outra posicao ou 0 caso nao queira remover nenhum elemento.\nNumero: ");
									scanf("%d", &n);
									printf("\n");
								}
								if(n!=0){
									remove_participante_meio(l2, n);
									printf("Participante removido!\n");
								}else{
									printf("Nenhum participante removido!\n");
								}
								scanf("%*c");
							}
							break;
						}
						case(5):{
							if(vazia_participante(l2)){
								printf("A lista esta vazia.\n");
							}
							else{
								printf("Entre com o cpf do participante que deseja consultar\nCPF: ");
								fflush(stdin);
								scanf("%[^\n]%*c", consulta);
								printf("\n");
								consulta_participante(l2, consulta);
							}
							break;
						}
						
						case(6):{
							printa_lista_participante(l2);
							break;
						}
					}
					
					if(b!=0){
						scanf("%*c");
						system("cls");
					}
					
				}
				
				break;
				
			}

			case(3):{
				test = 1;
				while(test){
					printf("\n		|Aeronaves|\n");
					printf("\nDigite 1 para inserir uma aeronave no final da lista\n");
					printf("Digite 2 para remover uma aeronave no inicio da lista.\n");
					printf("Digite 3 para remover uma aeronave no final da lista.\n");
					printf("Digite 4 para remover uma aeronave em uma posicao especifica na lista.\n");
					printf("Digite 5 para consultar uma aeronave na lista atraves do seu modelo.\n");
					printf("Digite 6 para printar a lista.\n");
					printf("Digite 0 para retornar a tela de escolha das listas.\n\n");
	
					scanf("%d", &b);
					scanf("%*c");
					system("cls");
					printf("\n");
					
					switch(b){
						
						case(0):{
							test = 0;
							break;
						}
						
						case(1):{
							printf("Entre com os dados da aeronave.\n");
							fflush(stdin);
							aer = scaneia_aeronave();
							insere_aeronave_final(l3, aer);
							printf("Aeronave inserida.\n\n");
							break;
						}
						
						case(2):{
							if(vazia_aeronave(l3)){
								printf("A lista esta vazia.\n");
							}
							else{
								remove_aeronave_comeco(l3);
								printf("Aeronave removida.\n\n");
							}
							break;
						}
						
						case(3):{
							if(vazia_aeronave(l3)){
								printf("A lista esta vazia.\n");
							}
							else{
								remove_aeronave_final(l3);
								printf("Aeronave removida.\n\n");
							}						
							break;
						}
						
						case(4):{
							if(vazia_aeronave(l3)){
								printf("A lista esta vazia.\n");
							}
							else{
								printf("Entre com o numero da lista no qual esta a aeronave que sera removida\nNumero: ");
								scanf("%d", &n);
								fflush(stdin);
								tam = checa_tamanho_lista_aeronave(l3);
								while(tam < n){
									printf("A lista nao possui tamanho o suficiente para remover nesta posicao, por favor escolha outra posicao ou 0 caso nao queira remover nenhum elemento.\nNumero: ");
									scanf("%d", &n);
									printf("\n");
								}
								if(n!=0) {
									remove_aeronave_meio(l3, n);
									printf("Aeronave removida!\n");
								}else{
									printf("Nenhuma aeronave removida!\n");
								}
								
								scanf("%*c");
								
							}						
							break;
						}
						
						case(5):{
							if(vazia_aeronave(l3)){
								printf("A lista esta vazia.\n");
							}
							else{
								printf("Entre com o modelo da aeronave que deseja consultar\nModelo: ");
								fflush(stdin);
								scanf("%[^\n]%*c", consulta);
								printf("\n");
								consulta_aeronave(l3, consulta);
							}					
							break;
						}
						
						case(6):{
							printa_lista_aeronave(l3);
							break;
						}
							
							
					}			
					
					if(b!=0){
						scanf("%*c");
						system("cls");
					}
				}		
				break;
			}

			case(4):{
				painel_de_voos(l1, hora_atual);
				scanf("%*c");
				system("cls");				
				break;
			}

			/*case(3):{
				
				printf("\nDigite o nome do arquivo: ");
				scanf("%[^\n]%*c", arquivo);
				printf("\n");
				ler_arquivo(arquivo, l1, l2);
				scanf("%*c");
				system("cls");
				
				break;
			}
			*/
			
		}

	}
	return 0;
}
