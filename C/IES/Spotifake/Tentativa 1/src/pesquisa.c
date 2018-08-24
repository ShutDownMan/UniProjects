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
				musicaEcontrada = pesquisarMusicaUI(db->musicas, filtros, ordenacao);
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
		printf("  (0)-> Voltar\n\n");

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
		scanf(" %d", &num);
		fflush(stdin);
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

Musica *pesquisarMusicaUI(MusicaDatabase *musicas, PesquisarMusicaFiltros filtros[], OrdenacaoInfo *ordInfo) {
	Musica *musicaEcontrada = NULL;
	MusicaDatabase *listaMusicas = NULL;
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
	free(listaMusicas->db_musicas);
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
		if(((Musica**)listaMusicaOrdenada->ponteiros)[i]->ativo) {
			printMusica(listaMusicaOrdenada->ponteiros[i]);
		}
	}

	free(listaMusicaOrdenada->ponteiros);
	free(listaMusicaOrdenada->valores);
	free(listaMusicaOrdenada);
}

OrdenacaoVet *criaListaPorAtributo(MusicaDatabase *musicas, OrdenacaoInfo *ordInfo) {
	OrdenacaoVet *listaMusicaOrdenada = malloc(sizeof(OrdenacaoVet));
	int i, inicio, fim, dir;

	listaMusicaOrdenada->tamanho = musicas->tamanho;
	listaMusicaOrdenada->ponteiros = malloc(sizeof(Musica*)*musicas->tamanho);
	listaMusicaOrdenada->valores = malloc(sizeof(int)*musicas->tamanho);

	for(i = 0; i < musicas->tamanho; ++i) {
		listaMusicaOrdenada->ponteiros[i] = musicas->db_musicas[i];
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

			musicasL = (Musica **)listaMusica->ponteiros;
			valoresL = listaMusica->valores;

			temp = valoresL[i]; valoresL[i] = valoresL[listaMusica->tamanho-i-1]; valoresL[listaMusica->tamanho-i-1] = temp;
			tempM = musicasL[i]; musicasL[i] = musicasL[listaMusica->tamanho-i-1]; musicasL[listaMusica->tamanho-i-1] = tempM;
//			printf("%d and %d\n", i, listaMusica->tamanho-i-1);
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
	pivoM = listaMusica->ponteiros[right];
	for(k = left; k < right; k++) {
		if(listaMusica->valores[k] <= pivo) {
			temp = listaMusica->valores[j]; listaMusica->valores[j] = listaMusica->valores[k]; listaMusica->valores[k] = temp;
			tempM = listaMusica->ponteiros[j]; listaMusica->ponteiros[j] = listaMusica->ponteiros[k]; listaMusica->ponteiros[k] = tempM;
			j++;
		}
	}
	listaMusica->valores[right] = listaMusica->valores[j]; listaMusica->valores[j] = pivo;
	listaMusica->ponteiros[right] = listaMusica->ponteiros[j]; listaMusica->ponteiros[j] = pivoM;
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
//		printf("tam = %d\n", musicas->tamanho);
		scanf(" %d", &escolha);
		fflush(stdin);

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

void printaPesquisaPlaylist(PlaylistDatabase *playlists) {
	int i;

	for(i = 0; i < playlists->tamanho; ++i) {
		
	}

	free(listaPlaylistOrdenada->ponteiros);
	free(listaPlaylistOrdenada->valores);
	free(listaPlaylistOrdenada);
}

void printMusica(Musica *musica) {
	if(musica->ativo) {
/*		printf("%16s", musica->titulo);
		printf("%16s\n", musica->interprete);
		printf("%16s\n", musica->autor);
		printf("%4d\n", musica->ano);
		printf("%16s\n", musica->genero);
		printf("%3d:%02d\n", musica->duracao/60, musica->duracao%60);
		printf("%1d\n\n", musica->avaliacao);
*/
	    printf("Titulo: %s\n", musica->titulo);
	    printf("Interprete: %s\n", musica->interprete);
	    printf("Autor: %s\n", musica->autor);
	    printf("Ano: %d\n", musica->ano);
	    printf("Genero: %s\n", musica->genero);
	    printf("duracao: %d:%02d\n", musica->duracao/60, musica->duracao%60);
	    printf("Avaliacao: %d\n\n", musica->avaliacao);
	} else {
		printf("Musica selecionada foi deletada.\n");
	}
}

//- PROCURAR PLAYLISTS -//

Playlist *acharPlaylistUI(AppDatabase *db) {
	Playlist *playlistEcontrada = NULL;
	PlaylistDatabase *listaPlaylists = NULL;
	char str[STRMAX], sair = 0;
	char **tags = NULL;
	int i, tagsTam = 0;

	printf("Digite sua pesquisa: ");
	scanf(" %[^\n]%*c", str);
	fflush(stdin);

	tags = separarTags(str, &tagsTam);
	listaPlaylists = pesquisarTodasPlaylistsComTags(db->playlists, tags, tagsTam);

	if(listaPlaylists->tamanho > 0)
		playlistEcontrada = pesquisaPorListaPlaylist(listaPlaylists);

	for(i = 0; i < tagsTam; ++i) {
		free(tags[i]);
	}
	free(tags);
	free(listaPlaylists);
	free(listaPlaylists->db_playlists);
	free(listaPlaylists);

	return playlistEcontrada;
}

PlaylistDatabase *pesquisarTodasPlaylistsComTags(PlaylistDatabase *playlists, char *tags[], int tagsTam) {
/*	PlaylistDatabase *playlistsEncontradas = inicializaPlaylistDatabase();
	Playlist *playlistAtual = NULL;
	int i, j, k, adiciona;
	char *tagAtual;

	for(i = 0; i < playlists->tamanho; ++i) {
		playlistAtual = playlists->db_playlists[i];
		if(playlistAtual->ativo) {
			adiciona = 1;
			for(j = 0; j < tagsTam; ++j) {
				if(strstr(playlistAtual->titulo, tags[j])) {
				} else if(strstr(playlistAtual->proprietario, tags[j])) {
				} else adiciona = 0;
			}
			if(adiciona) adicionaPlaylist(playlistsEncontradas, playlistAtual);
		}
	}
*/
	return playlistsEncontradas;
}

Playlist *pesquisaPorListaPlaylist(PlaylistDatabase *playlists) {
/*	int escolha;

	do {
		printaPesquisaPlaylist(playlists, ordInfo);
		printf("Digite o indice de uma playlist\n");
		printf("(0) -> Voltar\n");
//		printf("tam = %d\n", playlists->tamanho);
		scanf(" %d", &escolha);
		fflush(stdin);

		if(escolha < 0 || escolha > playlists->tamanho) {
			printf("Digite um numero valido!\n");
			getch();
		}

	} while(escolha < 0 || escolha > playlists->tamanho);

	if(escolha) {
		system("cls");
		printf("Musica escolhida:\n\n");
		printMusica(playlists->db_playlists[escolha-1]);
		getch();
		return playlists->db_playlists[escolha-1];
	}
*/
	return NULL;
}

void printPlaylist(Playlist *playlist) {
	int i, duracao;
	if(playlist && playlist->ativo) {
		duracao = duracaoPlaylist(playlist);

		printf("Titulo playlist: %s\n", playlist->titulo);
		printf("Proprietario playlist: %s\n\n", playlist->proprietario);
		printf("Duracao da playlist: %d:%02d\n", duracao/60, duracao%60);
		printf("Quantidade de musicas na playlist: %d\n\n", playlist->musicas->tamanho);

		printf("Musicas na playlist:\n");
		printf("Nome  Autor  Interprete  Genero  Ano  Duracao  Avaliacao\n");
		for(i = 0; i < playlist->musicas->tamanho; ++i) {
			printMusica(playlist->musicas->db_musicas[i]);
		}

	} else {
		printf("Esta playlist foi removida\n");
	}
}

int duracaoPlaylist(Playlist *playlist) {
	int i, duracao;

	if(playlist && playlist->ativo) {
		for(i = duracao = 0; i < playlist->musicas->tamanho; ++i) {
			duracao += playlist->musicas->db_musicas[i]->duracao;
		}
	}

	return duracao;
}

//- DELETAR MUSICAS -//

void deletarMusicaUI(AppDatabase *db) {
	system("cls");
	printf("Pesquise pela musica que deseja deletar.\n");
	printf("Pressione qualquer tecla para continuar...\n");
	getch();
	Musica *musicaEcontrada = acharMusicaUI(db);

	if(musicaEcontrada) {
		musicaEcontrada->ativo = 0;
		printf("Musica deletada!\n");
		getch();
	}
}

//- DELETAR PLAYLISTS -//