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

typedef struct ordenacaoVet {
	Musica **musicas;
	int *valores;
	int tamanho;
} OrdenacaoVet;

//- READ -//

Musica *acharMusicaUI(AppDatabase *db);

PesquisarMusicaFiltros *acharMusicaMenuFiltrosPadroes();

OrdenacaoInfo *acharMusicaMenuOrdenacaoPadrao();

void escolhaModificarFiltrosMusicaMenu(PesquisarMusicaFiltros filtros[]);

PesquisarMusicaOpcoes acharMusicaOpcoesMenu();

void escolhaModificarOrdenacaoMusicaMenu(OrdenacaoInfo *ordenacao);

Musica *pesquisarMusica(MusicaDatabase *musicas, PesquisarMusicaFiltros filtros[], OrdenacaoInfo *info);

void printaPesquisa(MusicaDatabase *musicas, PesquisarMusicaFiltros filtros[], OrdenacaoInfo *ordInfo);

void ordenarListaMusica(OrdenacaoVet *listaMusica, int inverter);

void quickSort(OrdenacaoVet *listaMusica, int left, int right);

int ordenarHelper(OrdenacaoVet *listaMusica, int left, int right);

OrdenacaoVet *criaListaPorAtributo(MusicaDatabase *musicas, OrdenacaoInfo *ordInfo);

char **separarTags(char str[], int *tam);

MusicaDatabase *pesquisarTodasMusicasComTags(MusicaDatabase *musicas, char *tags[], int tagsTam, PesquisarMusicaFiltros filtros[]);

Musica *pesquisaPorListaMusica(MusicaDatabase *musicas, OrdenacaoInfo *ordenacao);


void printMusica(Musica *musica);


#endif // PESQUISA_H