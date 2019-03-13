#include "inserirVooUI.h"

void inserirVoo() {
	VooInfo *novoVoo = createVooInfo();
	char cadastroConcluido = 0;

	while(!cadastroConcluido) {
		telaCabecalhoInserirVoo();

		if(novoVoo->prefixo[0] == '\0') {
			printaSeparador();
			lerPrefixoVoo(novoVoo);
			continue;
		} else {
			printf("Prefixo: %s\n", novoVoo->prefixo);
		}

		if(novoVoo->origem[0] == '\0') {
			printaSeparador();
			lerOrigemVoo(novoVoo);
			continue;
		} else {
			printf("Origem: (%s)%s\n", novoVoo->origemSigla, novoVoo->origem);
		}

		if(novoVoo->destino[0] == '\0') {
			printaSeparador();
			lerDestinoVoo(novoVoo);
			continue;
		} else {
			printf("Destino: (%s)%s\n", novoVoo->destinoSigla, novoVoo->destino);
		}

		if(novoVoo->partida.hh == -1) {
			printaSeparador();
			lerPartidaVoo(novoVoo);
			continue;
		} else {
			printf("Partida: %02d:%02d\n", novoVoo->partida.hh, novoVoo->partida.mm);
		}

		if(novoVoo->chegada.hh == -1) {
			printaSeparador();
			lerChegadaVoo(novoVoo);
			continue;
		} else {
			printf("Chegada: %02d:%02d\n", novoVoo->chegada.hh, novoVoo->chegada.mm);
		}

		if(novoVoo->duracao.hh == -1) {
			printaSeparador();
			lerDuracaoVoo(novoVoo);
			continue;
		} else {
			printf("Duracao: %02d:%02d\n", novoVoo->duracao.hh, novoVoo->duracao.mm);
		}

		if(novoVoo->modeloAeronave[0] == '\0') {
			printaSeparador();
			lerModeloAeronaveVoo(novoVoo);
			continue;
		} else {
			printf("Modelo aeronave: %s\n", novoVoo->modeloAeronave);
		}

		cadastroConcluido = mostrarCadastroVooOpcoes(novoVoo);

	}
}

void telaCabecalhoInserirVoo() {
	system("cls");

	printf("Insira as informacoes do voo a seguir.\n");
	printf("\n");
}

void printaSeparador() {
	printf("---------------------------\n");
}

void lerPrefixoVoo(VooInfo *novoVoo) {
	printf("Prefixo: ");
	fflush(stdin);
	scanf("%[^\n]%*c", novoVoo->prefixo);

	if(!ehValidoPrefixo(novoVoo->prefixo)) {
		printf("\nPrefixo fornecido e invalido!\n");
		system("pause");

		novoVoo->prefixo[0] = '\0';
	}
}

char ehValidoPrefixo(char prefixo[]) {
	return (prefixo[0] != '\0' && strlen(prefixo) < MAX_PREFIXO_LENGTH);
}

void lerOrigemVoo(VooInfo *novoVoo) {
	printf("Sigla Origem: ");
	fflush(stdin);
	scanf("%[^\n]%*c", novoVoo->origemSigla);

	if(!ehValidoSiglaAeroporto(novoVoo->origemSigla)) {
		printf("\nSigla fornecida e invalida!\n");
		system("pause");

		novoVoo->origemSigla[0] = '\0';
		return;
	}

	printf("Origem: ");
	fflush(stdin);
	scanf("%[^\n]%*c", novoVoo->origem);

	if(!ehValidoNomeAeroporto(novoVoo->origem)) {
		printf("\nOrigem fornecida e invalida!\n");
		system("pause");

		novoVoo->origemSigla[0] = '\0';
		novoVoo->origem[0] = '\0';
	}
}

char ehValidoSiglaAeroporto(char sigla[]) {
	if(strlen(sigla) < MAX_AEROPORTO_SIGLA_LENGTH) {
		return (isalpha(sigla[0]) && isalpha(sigla[1]) && isalpha(sigla[2]));
	}
	return 0;
}

char ehValidoNomeAeroporto(char nome[]) {
	int i;

	if(nome[0] != '\0' && strlen(nome) < MAX_AEROPORTO_NAME_LENGTH) {
		for(i = 0; nome[i]; ++i) {
			if(!isalnum(nome[i]) && nome[i] != ' ') return 0;
		}
		return 1;
	}
	return 0;
}

void lerDestinoVoo(VooInfo *novoVoo) {
	printf("Sigla Destino: ");
	fflush(stdin);
	scanf("%[^\n]%*c", novoVoo->destinoSigla);

	if(!ehValidoSiglaAeroporto(novoVoo->destinoSigla)) {
		printf("\nSigla fornecida e invalida!\n");
		system("pause");

		novoVoo->destinoSigla[0] = '\0';
		return;
	}

	if(!strcmp(novoVoo->origemSigla, novoVoo->destinoSigla)) {
		printf("\nDestino e origem nao podem ser o mesmo!\n");
		system("pause");

		novoVoo->destinoSigla[0] = '\0';
		return;
	}

	printf("Destino: ");
	fflush(stdin);
	scanf("%[^\n]%*c", novoVoo->destino);

	if(!ehValidoNomeAeroporto(novoVoo->destino)) {
		printf("\nDestino fornecido e invalido!\n");
		system("pause");

		novoVoo->destinoSigla[0] = '\0';
		novoVoo->destino[0] = '\0';
	}
}

void lerPartidaVoo(VooInfo *novoVoo) {
	int readCheck = 0, hh, mm;

	printf("Horario da partida (hh:mm): ");
	fflush(stdin);
	scanf("%d:%d%n", &hh, &mm, &readCheck);
	novoVoo->partida.hh = hh;
	novoVoo->partida.mm = mm;

	if(!readCheck || !ehValidoHorario(novoVoo->partida)) {
		printf("\nHorario de partida fornecido e invalido!\n");
		system("pause");

		novoVoo->partida.hh = -1;
		novoVoo->partida.mm = -1;
	}
}

char ehValidoHorario(Hora horario) {
	return (horario.hh >= 0 && horario.hh < 24 &&
		horario.mm >= 0 && horario.mm < 59);
}

void lerChegadaVoo(VooInfo *novoVoo) {
	int readCheck = 0, hh, mm;

	printf("Horario de chegada (hh:mm): ");
	fflush(stdin);
	scanf("%d:%d%n", &hh, &mm, &readCheck);
	novoVoo->chegada.hh = hh;
	novoVoo->chegada.mm = mm;

	if(!readCheck || !ehValidoHorario(novoVoo->chegada)) {
		printf("\nHorario de chegada fornecido e invalido!\n");
		system("pause");

		novoVoo->chegada.hh = -1;
		novoVoo->chegada.mm = -1;
	}
}

void lerDuracaoVoo(VooInfo *novoVoo) {
	int readCheck = 0, hh, mm;

	printf("Duracao do voo (hh:mm): ");
	fflush(stdin);
	scanf("%d:%d%n", &hh, &mm, &readCheck);
	novoVoo->duracao.hh = hh;
	novoVoo->duracao.mm = mm;

	if(!readCheck || !ehValidoHorario(novoVoo->duracao)) {
		printf("\nDuracao fornecida e invalida!\n");
		system("pause");

		novoVoo->duracao.hh = -1;
		novoVoo->duracao.mm = -1;
	}
}

void lerModeloAeronaveVoo(VooInfo *novoVoo) {
	printf("Modelo aeronave: ");
	fflush(stdin);
	scanf("%[^\n]%*c", novoVoo->modeloAeronave);

	if(!ehValidoModeloAeronave(novoVoo->modeloAeronave)) {
		printf("\nAeronave fornecida e invalida!\n");
		system("pause");

		novoVoo->modeloAeronave[0] = '\0';
		return;
	}

}

char ehValidoModeloAeronave(char modeloAeronave[]) {
	int i;
	if(modeloAeronave[0] != '\0' && strlen(modeloAeronave) < MAX_MODELO_AERONAVE) {
		for(i = 0; modeloAeronave[i]; ++i) {
			if(!isalnum(modeloAeronave[i]) && modeloAeronave[i] != ' ') return 0;
		}
		return 1;
	}
	return 0;
}

char mostrarCadastroVooOpcoes(VooInfo *novoVoo) {
	char escolha = 0;

	escolha = escolhaInserirVoo(novoVoo);
	switch(escolha) {
		case 's':
//			salvarVoo(novoVoo);
			printaSeparador();
			printf("Funcionalidade ainda nao implementada!\n");
			printaSeparador();
			system("pause");
			return 0;
		case 'a':
//			alterarVoo();
			printaSeparador();
			printf("Funcionalidade ainda nao implementada!\n");
			printaSeparador();
			system("pause");
			return 0;
		case 'c':
		case '0':
			system("cls");
			printf("\nSaindo do menu de cadastro de voo.\n\n");
			system("pause");
			return 1;
		default:
			printaSeparador();
			printf("Nao eh uma opcao valida!\n\n");
			printaSeparador();
			system("pause");
			return 0;
	}

	return 1;
}

char escolhaInserirVoo(VooInfo *novoVoo) {
	char escolha, choiceList[3] = "0sa";

	printaSeparador();
	telaRodapeInserirVoo();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	if(!isdigit(escolha)) return tolower(escolha);

	return choiceList[escolha-'0'];
}

void telaRodapeInserirVoo() {
	printf("1) (S)alvar - 2) (A)lterar\n");
	printf("0) (C)ancelar Cadastro\n");
}