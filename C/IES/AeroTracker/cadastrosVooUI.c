#include "cadastrosVooUI.h"

void cadastrosVoo() {
	char escolha = 0;

	escolha = escolhaCadastrosVoo();
	do {
		switch(escolha) {
			case 'i':
				inserirVoo();
				break;
			case 'c':
//				consultarVoo();
				break;
			case '0':
				system("cls");
				printf("\nSaindo do menu de cadastros de voo.\n\n");
				system("pause");
				break;
			default:
				printf("Nao eh uma opcao valida!\n\n");
				system("pause");
				break;
		}

	} while(escolha != '0' && (escolha = escolhaCadastrosVoo()));
}

char escolhaCadastrosVoo() {
	char escolha, choiceList[3] = "0ic";

	telaCadastrosVoo();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	if(!isdigit(escolha)) return tolower(escolha);

	return choiceList[escolha-'0'];
}

void telaCadastrosVoo() {
	system("cls");

	printf("1) (I)nserir Voo\n");
	printf("2) (C)onsultar Voo\n");
	printf("\n");
	printf("0) Sair do Menu de Cadastros\n");
}
