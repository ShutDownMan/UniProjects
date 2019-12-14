#include <stdio.h>
#include <stdlib.h>

#define PI 3.141312

unsigned int escolhaMenuMain();

void carteiraHabilitacao();

void mediaIdades();

void volumeCilindro();

void enterParaConfirmar();

int main(int argc, char const *argv[]) {
	unsigned int escolha;

	/// lê entrada do usuário e testa se é zero
	while(escolha = escolhaMenuMain()) {
		/// performa ação escolhida pelo usuário
		switch(escolha) {
			/// programa da carteira de habilitação
			case 1:
				carteiraHabilitacao();
			break;

			/// programa da média das idades
			case 2:
				mediaIdades();
			break;

			/// programa do volume do cilindro
			case 3:
				volumeCilindro();
			break;

			/// programas ainda não especificados
			case 4: case 5: case 6: case 7: 
			case 8: case 9: case 10:
				printf("Em andamento\n");
				/// pede confirmação do usuário
				enterParaConfirmar();
			break;

			/// opção escolhida é inválida
			default:
				printf("Opcao invalida.\n");
				/// pede confirmação do usuário
				enterParaConfirmar();
			break;
		}

	}

	return 0;
}

unsigned int escolhaMenuMain() {
	unsigned int escolha;

	/// limpa a tela
	system("cls");

	printf("Olá\n");
	printf("(1) programa carteira habilitacao\n");
	printf("(2) media das idades\n");
	printf("(3) volume do cilindro\n");
	printf("(0) sair\n");
	printf("Digite o numero do programa a ser executado: ");

	scanf(" %u", &escolha);

	return escolha;
}

void carteiraHabilitacao() {
	unsigned int idade;

	/// limpa a tela
	system("cls");

	printf("Por favor informe sua idade: ");
	scanf(" %u", &idade);
	printf("\n");

	/// se idade é menor que 18 \
	pessoa não possui carteira
	if(idade < 18) {
		printf("Menores de idade nao possuem carteira.\n");
	} else if(idade <= 65) {
		/// se idade maior que 18 e menor igual que 65 \
		renovação a cada 5 anos
		printf("O periodo de renovacao da sua carteira eh de 5 anos\n");
	} else {
		/// se idade maior que 65 a renovação acontece \
		a cada 3 anos
		printf("O periodo de renovacao da sua carteira eh de 3 anos\n");
	}

	printf("\n");

	/// pede confirmação do usuário
	enterParaConfirmar();
}

void mediaIdades() {
	unsigned int i, idadeAtual;
	double soma;

	printf("Digite uma idade: ");
	scanf(" %u", &idadeAtual);
	/// enquanto idadeAtual for diferente de zero
	for(i = soma = 0; idadeAtual; ++i) {
		/// calcula a soma de todas as idades
		soma += idadeAtual;

		printf("Digite mais uma idade: ");
		scanf(" %u", &idadeAtual);
	}

	printf("\n");
	/// a média é calculada como a divisão da \
	soma das idades pelo numero de idades informadas
	printf("A media das idades eh de %.0lf anos\n", soma/i);
	printf("\n");

	/// pede confirmação do usuário
	enterParaConfirmar();
}

void volumeCilindro() {
	double volume, raio;

	printf("Digite o raio do cilindro: ");
	scanf(" %lf", &raio);

	printf("\n");
	/// O volume é calculado como pi * raio^2 * altura
	printf("O volume do cilindro eh de %lf\n", PI * raio * raio * 10);
	printf("\n");

	/// pede confirmação do usuário
	enterParaConfirmar();
}

void enterParaConfirmar() {
	/// espera confirmação do usuário
	printf("aperte enter para continuar\n");
	/// limpa a entrada de "enters"
	while((getchar()) != '\n');
	/// espera confirmação do usuário
	getchar();
}