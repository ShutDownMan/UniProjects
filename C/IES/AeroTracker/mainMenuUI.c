#include "mainMenuUI.h"

/*!
	@brief mainMenuEscolha, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char mainMenuEscolha() {
	char escolha, choiceList[3] = "0cs";

	/// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
	telaMainMenu();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	/// se não é número, retorna a letra minuscula
	if(!isdigit(escolha)) return tolower(escolha);

	/// se for número, converte e retorna letra equivalente
	return choiceList[escolha-'0'];
}

/*!
	@brief telaMainMenu, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaMainMenu() {
	system("cls");

	printf("1) Menu (C)adastros\n");
	printf("2) Menu (S)tatus\n");
	printf("\n");
	printf("0) Sair do Programa\n");
}

void menuStatus() {
	system("cls");
	printf("menuStatus\n");
	printf("WORK IN PROGRESS...\n");
	system("pause");
}

void testarCadastros() {
	system("cls");
	printf("testarCadastros\n");
	printf("WORK IN PROGRESS...\n");
	system("pause");
}

/*!
	@brief confirmacaoSaidaMainMenu, pergunta ao usuário se este confirma \
	saída do programa
	@precondition nenhuma
	@postcondition nenhuma
*/
char confirmacaoSaidaMainMenu() {
	char escolha = 0;

	/// pergunta ao usuário se deseja mesmo sair
	system("cls");
	printf("Voce deseja sair do programa?\n");
	printf("S / N\n");

	/// lê resposta do usuário
	fflush(stdin);
	scanf("%c", &escolha);
	escolha = tolower(escolha);

	/// enquanto resposta for inválida
	while(escolha != 's' && escolha != 'n') {
		/// limpa tela e pergunta confirmação de saida
		system("cls");
		printf("Escolha invalida!\n");
		printf("Voce deseja sair do programa?\n");
		printf("S / N\n");

		/// lê resposta do usuário
		fflush(stdin);
		scanf("%c", &escolha);
		escolha = tolower(escolha);
	}

	/// se usuário deseja sair, retorna 1
	if(escolha == 's') return 1;

	/// caso contrário, retorna 0
	return 0;
}
