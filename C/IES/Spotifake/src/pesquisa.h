#ifndef PESQUISA_H
#define PESQUISA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "start.h"

typedef enum pesquisarMusicaOpcoes {
	ModificarFiltros,
	ModificarOrdenacao,
	FazerPesquisa,
	SairMusicaOpcoes
} PesquisarMusicaOpcoes;

typedef enum pesquisarMusicaFiltros {
	Titulo,
	Interprete,
	Autor,
	Genero,
	PesquisarMusicaFiltrosTamanho
} PesquisarMusicaFiltros;

typedef enum pesquisarMusicaOrdenacao {
	Ano,
	Duracao,
	Avaliacao
} PesquisarMusicaOrdenacao;

typedef struct ordenacaoInfo {
	PesquisarMusicaOrdenacao tipo;
	int ehCrescente;
} OrdenacaoInfo;

//- READ -//

Musica *acharMusicaUI(AppDatabase *db);

PesquisarMusicaFiltros *acharMusicaMenuFiltrosPadroes();

OrdenacaoInfo *acharMusicaMenuOrdenacaoPadrao();

void escolhaModificarFiltrosMusicaMenu(PesquisarMusicaFiltros filtros[]);

PesquisarMusicaOpcoes acharMusicaOpcoesMenu();

void escolhaModificarOrdenacaoMusicaMenu(OrdenacaoInfo *ordenacao);

Musica *pesquisarMusica(MusicaDatabase *musicas, PesquisarMusicaFiltros filtros[], OrdenacaoInfo *info);

char **separarTags(char str[], int *tam);



void printMusica(Musica *musica);



#endif // PESQUISA_H