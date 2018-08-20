#include "pesquisa.h"

//- READ -//

Musica *acharMusicaUI(AppDatabase *db) {
	Musica *musicaEcontrada = NULL;
	PesquisarMusicaOpcoes escolha;
	PesquisarMusicaFiltros *filtros;
	OrdenacaoInfo *ordenacao;

	filtros = acharMusicaMenuFiltrosPadroes();
	ordenacao = acharMusicaMenuOrdenacaoPadrao();

	do {
		escolha = acharMusicaOpcoesMenu();

		switch(escolha) {
			case ModificarFiltros:
				escolhaModificarFiltrosMusicaMenu(filtros);
				break;
			case ModificarOrdenacao:
				escolhaModificarOrdenacaoMusicaMenu(ordenacao);
				break;
			case FazerPesquisa:
				musicaEcontrada = pesquisarMusica(db->musicas, filtros, ordenacao);
				break;
			default: break;
		}
	} while(escolha != SairMusicaOpcoes);


	if(!musicaEcontrada)
		printf("Música não encontrada.\n");

	free(filtros);
	free(ordenacao);

	return musicaEcontrada;
}

PesquisarMusicaFiltros *acharMusicaMenuFiltrosPadroes() {
	int i;
	PesquisarMusicaFiltros *filtros = malloc(sizeof(PesquisarMusicaFiltros)*PesquisarMusicaFiltrosTamanho);

	for(i = 0; i < PesquisarMusicaFiltrosTamanho; ++i) {
		filtros[i] = 1;
	}

	return filtros;
}

OrdenacaoInfo *acharMusicaMenuOrdenacaoPadrao() {
	OrdenacaoInfo *ordenacao = malloc(sizeof(OrdenacaoInfo));

	ordenacao->tipo = Avaliacao;
	ordenacao->ehCrescente = 1;

	return ordenacao;
}

void escolhaModificarFiltrosMusicaMenu(PesquisarMusicaFiltros filtros[]) {
	int num;

	do {
		system("cls");
		printf("Filtros: \n");
		printf("  (1)-> [%c]Titulo", filtros[0] ? 'X' : ' ');
		printf("  (2)-> [%c]Interprete\n", filtros[1] ? 'X' : ' ');
		printf("  (3)-> [%c]Autor", filtros[2] ? 'X' : ' ');
		printf("   (4)-> [%c]Genero\n", filtros[3] ? 'X' : ' ');
		printf("  (0)-> [%c]Sair\n\n");

		printf("comando: ");
		fflush(stdin);
		scanf("%d", &num);
		if(num < 0 || num > PesquisarMusicaFiltrosTamanho) {
			printf("Digite um comando valido!\n");
			getch();
		} else if(num) {
			filtros[num-1] = filtros[num-1] ? 0 : 1;
		}
	} while(num);
}

PesquisarMusicaOpcoes acharMusicaOpcoesMenu() {
	int num;

	do {
		system("cls");
		printf("Opcoes: \n");
		printf("(1)-> Modificar Filtros\n");
		printf("(2)-> Modificar Ordenacao\n");
		printf("(3)-> Fazer Pesquisa\n");
		printf("(0)-> Sair\n");

		printf("comando: ");
		fflush(stdin);
		scanf("%d", &num);
		if(num < 0 || num > SairMusicaOpcoes) {
			printf("Digite um comando valido!\n");
			getch();
		} else if(num) {
			return (PesquisarMusicaOpcoes)(num-1);
		}
	} while(num);

	return SairMusicaOpcoes;
}

void escolhaModificarOrdenacaoMusicaMenu(OrdenacaoInfo *ordenacao) {
	int num;
	char escolha;

	do {
		system("cls");
		printf("Tipo escolhido: (%d) %s\n", ordenacao->tipo+1, ordenacao->ehCrescente ? "crescente" : "decrescente");
		printf("Opcoes: \n");
		printf("(1)-> Ano\n");
		printf("(2)-> Duracao\n");
		printf("(3)-> Avaliacao\n");

		printf("comando: ");
		fflush(stdin);
		scanf("%d", &num);
		if(num <= 0 || num > SairMusicaOpcoes) {
			printf("Digite um comando valido!\n");
			num = 1;
			getch();
		} else {
			printf("Ordem crescente ou decrescente?\n[S] para crescente\n");
			scanf(" %c", &escolha);
			fflush(stdin);

			ordenacao->ehCrescente = (toupper(escolha) == 'S');
			ordenacao->tipo = (PesquisarMusicaOrdenacao)(num-1);

			num = 0;
		}
	} while(num);
}

Musica *pesquisarMusica(MusicaDatabase *musicas, PesquisarMusicaFiltros filtros[], OrdenacaoInfo *info) {
	MusicaDatabase *listaMusicas = inicializaMusicaDatabase();
	char str[STRMAX], sair = 0;
	char **tags = NULL;
	int i, tagsTam = 0;

	printf("Digite sua pesquisa: ");
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	listaMusicas = pesquisarTodasMusicasComTags(musicas, tags, filtros);
	do {
		printaPesquisa(listaMusicas, filtros, ordenacao);
		pesquisaPorListaMusica(listaMusicas, ordenacao);
		tags = separarTags(str, &tagsTam);


		getch();
	} while(!sair && listaMusicas->tamanho > 1);

	for(i = 0; i < tagsTam; ++i) {
		free(tags[i]);
	}
	free(tags);
	free(listaMusicas);

}

void printaPesquisa(MusicaDatabase *musicas) {
	int i;

	for(i = 0; i < musicas->tamanho; ++i) {
		if(musicas->db_musicas[i]) {
			printMusica(musicas->db_musicas[i]);
		}
	}
}

char **separarTags(char str[], int *tam) {
	int i, offs, n;
	char tag[STRMAX];
	char **novaLista;

	*tam = 1;
	novaLista = malloc(sizeof(char*) * (*tam));

	for(i = offs = 0; offs < strlen(str); ++i, offs += n) {
		if(i+1 > *tam) {
			*tam *= 2;
			novaLista = realloc(novaLista, sizeof(char*) * (*tam));
		}
		sscanf(str+offs, " %s%n", tag, &n);
		if(strlen(tag) > 0) {
			novaLista[i] = strcpy(malloc(sizeof(char)*strlen(tag)+1), tag);
		}
	}
	*tam = i;
	novaLista = realloc(novaLista, sizeof(char*) * (*tam));

	return novaLista;
}

MusicaDatabase *pesquisarTodasMusicasComTags(MusicaDatabase *musicas, char *tags[], PesquisarMusicaFiltros filtros[]) {

}

void printaPesquisa() {

}

void pesquisaPorListaMusica(MusicaDatabase *musicas, OrdenacaoInfo *ordenacao) {

}

void printMusica(Musica *musica) {
	printf("--------------\n");
	printf("Titulo: %s\n", musica->titulo);
	printf("Interprete: %s\n", musica->interprete);
	printf("Autor: %s\n", musica->autor);
	printf("Ano: %d\n", musica->ano);
	printf("Genero: %s\n", musica->genero);
	printf("duracao: %d:%02d\n", musica->duracao/60, musica->duracao%60);
	printf("Avaliacao: %d\n\n", musica->avaliacao);
}