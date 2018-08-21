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
	} while(escolha != SairMusicaOpcoes && !musicaEcontrada);


	if(!musicaEcontrada)
		printf("Musica nao encontrada.\n");

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
		printf("  (0)-> [%c]Voltar\n\n");

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
		printf("(0)-> Voltar\n");

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

void escolhaModificarOrdenacaoMusicaMenu(OrdenacaoInfo *ordInfo) {
	int num;
	char escolha;

	do {
		system("cls");
		printf("Tipo escolhido: (%d) %s\n", ordInfo->tipo+1, ordInfo->ehCrescente ? "crescente" : "decrescente");
		printf("Opcoes: \n");
		printf("(1)-> Ano\n");
		printf("(2)-> Duracao\n");
		printf("(3)-> Avaliacao\n");

		printf("comando: ");
		scanf(" %d", &num);
		fflush(stdin);
		if(num <= 0 || num > SairMusicaOpcoes) {
			printf("Digite um comando valido!\n");
			num = 1;
			getch();
		} else {
			printf("Ordem crescente ou decrescente?\n[S] para crescente\n");
			scanf(" %c", &escolha);
			fflush(stdin);

			ordInfo->ehCrescente = (toupper(escolha) == 'S');
			ordInfo->tipo = (PesquisarMusicaOrdenacao)(num-1);

			num = 0;
		}
	} while(num);
}

Musica *pesquisarMusica(MusicaDatabase *musicas, PesquisarMusicaFiltros filtros[], OrdenacaoInfo *ordInfo) {
	Musica *musicaEcontrada = NULL;
	MusicaDatabase *listaMusicas = inicializaMusicaDatabase();
	char str[STRMAX], sair = 0;
	char **tags = NULL;
	int i, tagsTam = 0;

	printf("Digite sua pesquisa: ");
	scanf(" %[^\n]%*c", str);
	fflush(stdin);

	tags = separarTags(str, &tagsTam);
	listaMusicas = pesquisarTodasMusicasComTags(musicas, tags, tagsTam, filtros);

	if(listaMusicas->tamanho > 0)
		musicaEcontrada = pesquisaPorListaMusica(listaMusicas, ordInfo);

	for(i = 0; i < tagsTam; ++i) {
		free(tags[i]);
	}
	free(tags);
	free(listaMusicas);

	return musicaEcontrada;
}

void printaPesquisa(MusicaDatabase *musicas, OrdenacaoInfo *ordInfo) {
	int i;
	OrdenacaoVet *listaMusicaOrdenada;

	listaMusicaOrdenada = criaListaPorAtributo(musicas, ordInfo);

	ordenarListaMusica(listaMusicaOrdenada, !ordInfo->ehCrescente);

	for(i = 0; i < listaMusicaOrdenada->tamanho; ++i) {
		printf("Musica [%d]:\n", i+1);
		if(listaMusicaOrdenada->musicas[i]->ativo) {
			printMusica(listaMusicaOrdenada->musicas[i]);
		}
	}

	free(listaMusicaOrdenada->musicas);
	free(listaMusicaOrdenada->valores);
	free(listaMusicaOrdenada);
}

OrdenacaoVet *criaListaPorAtributo(MusicaDatabase *musicas, OrdenacaoInfo *ordInfo) {
	OrdenacaoVet *listaMusicaOrdenada = malloc(sizeof(OrdenacaoVet));
	int i, inicio, fim, dir;

	listaMusicaOrdenada->tamanho = musicas->tamanho;
	listaMusicaOrdenada->musicas = malloc(sizeof(Musica*)*musicas->tamanho);
	listaMusicaOrdenada->valores = malloc(sizeof(int)*musicas->tamanho);

	for(i = 0; i < musicas->tamanho; ++i) {
		listaMusicaOrdenada->musicas[i] = musicas->db_musicas[i];
		switch(ordInfo->tipo) {
			case Ano:
				listaMusicaOrdenada->valores[i] = musicas->db_musicas[i]->ano;
				break;
			case Duracao:
				listaMusicaOrdenada->valores[i] = musicas->db_musicas[i]->duracao;
				break;
			case Avaliacao:
				listaMusicaOrdenada->valores[i] = musicas->db_musicas[i]->avaliacao;
				break;
			default: break;
		}
	}

	return listaMusicaOrdenada;
}

void ordenarListaMusica(OrdenacaoVet *listaMusica, int inverter) {
	int i;

	quickSort(listaMusica, 0, listaMusica->tamanho-1);

	if(inverter) {
		/// inverte vetor
		for(i = 0; i < listaMusica->tamanho/2; ++i) {
			Musica *tempM, **musicasL;
			int temp, *valoresL;

			musicasL = listaMusica->musicas;
			valoresL = listaMusica->valores;

			temp = valoresL[i]; valoresL[i] = valoresL[listaMusica->tamanho-i-1]; valoresL[listaMusica->tamanho-i-1] = temp;
			tempM = musicasL[i]; musicasL[i] = musicasL[listaMusica->tamanho-i-1]; musicasL[listaMusica->tamanho-i-1] = tempM;
			printf("%d and %d\n", i, listaMusica->tamanho-i-1);
		}
	}

}

void quickSort(OrdenacaoVet *listaMusica, int left, int right) {
	int j;
	if(left < right) {
		j = ordenarHelper(listaMusica, left, right);
		quickSort(listaMusica, left, j-1);
		quickSort(listaMusica, j+1, right);
	}
}

int ordenarHelper(OrdenacaoVet *listaMusica, int left, int right) {
	int pivo, j, k, temp;
	Musica *pivoM, *tempM;

	pivo = listaMusica->valores[right]; j = left;
	pivoM = listaMusica->musicas[right];
	for(k = left; k < right; k++) {
		if(listaMusica->valores[k] <= pivo) {
			temp = listaMusica->valores[j]; listaMusica->valores[j] = listaMusica->valores[k]; listaMusica->valores[k] = temp;
			tempM = listaMusica->musicas[j]; listaMusica->musicas[j] = listaMusica->musicas[k]; listaMusica->musicas[k] = tempM;
			j++;
		}
	}
	listaMusica->valores[right] = listaMusica->valores[j]; listaMusica->valores[j] = pivo;
	listaMusica->musicas[right] = listaMusica->musicas[j]; listaMusica->musicas[j] = pivoM;
	return j;
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

MusicaDatabase *pesquisarTodasMusicasComTags(MusicaDatabase *musicas, char *tags[], int tagsTam, PesquisarMusicaFiltros filtros[]) {
	MusicaDatabase *musicasEncontradas = inicializaMusicaDatabase();
	Musica *musicaAtual = NULL;
	int i, j, k, adiciona;
	char *tagAtual;

	for(i = 0; i < musicas->tamanho; ++i) {
		musicaAtual = musicas->db_musicas[i];
		if(musicaAtual->ativo) {
			adiciona = 1;
			for(j = 0; j < tagsTam; ++j) {
				if(filtros[0] && strstr(musicaAtual->titulo, tags[j])) { //< Titulo
				} else if(filtros[1] && strstr(musicaAtual->interprete, tags[j])) { //< Interprete
				} else if(filtros[2] && strstr(musicaAtual->autor, tags[j])) { //< Autor
				} else if(filtros[3] && strstr(musicaAtual->genero, tags[j])) { //< Genero
				} else adiciona = 0;
			}
			if(adiciona) adicionaMusica(musicasEncontradas, musicaAtual);
		}
	}

	return musicasEncontradas;
}

Musica *pesquisaPorListaMusica(MusicaDatabase *musicas, OrdenacaoInfo *ordInfo) {
	int escolha;

	do {
		printaPesquisa(musicas, ordInfo);
		printf("Digite o indice de uma musica\n");
		printf("(0) -> Voltar\n");
		printf("tam = %d\n", musicas->tamanho);
		scanf(" %d", &escolha);


		if(escolha < 0 || escolha > musicas->tamanho) {
			printf("Digite um numero valido!\n");
			getch();
		}

	} while(escolha < 0 || escolha > musicas->tamanho);

	if(escolha) {
		system("cls");
		printf("Musica escolhida:\n\n");
		printMusica(musicas->db_musicas[escolha-1]);
		getch();
		return musicas->db_musicas[escolha-1];
	}

	return NULL;
}

void printMusica(Musica *musica) {
	printf("Titulo: %s\n", musica->titulo);
	printf("Interprete: %s\n", musica->interprete);
	printf("Autor: %s\n", musica->autor);
	printf("Ano: %d\n", musica->ano);
	printf("Genero: %s\n", musica->genero);
	printf("duracao: %d:%02d\n", musica->duracao/60, musica->duracao%60);
	printf("Avaliacao: %d\n\n", musica->avaliacao);
}

//- PROCURAR PLAYLISTS -//



//- DELETAR MUSICAS -//



//- DELETAR PLAYLISTS -//