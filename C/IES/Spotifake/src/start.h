#ifndef START_H
#define START_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRMAX 255

typedef struct musica {
	char titulo[STRMAX];
	char interprete[STRMAX];
	char autor[STRMAX];
	char genero[STRMAX];
	int ano;
	int duracao;
	unsigned char avaliacao;
} Musica;

typedef struct playlist {
	Musica **listaMusicas;
	int length;
	char titulo[STRMAX];
	char proprietario[STRMAX];
} Playlist;

typedef struct musicaDatabase {
	Musica **db_musicas;
	int tamanho, espacoAlocado;
} MusicaDatabase;

typedef struct playlistDatabase {
	Playlist **db_playlists;
	int tamanho, espacoAlocado;
} PlaylistDatabase;

typedef struct appDatabase {
	MusicaDatabase *musicas;
	PlaylistDatabase *playlists;
} AppDatabase;

AppDatabase *inicializaDB();

MusicaDatabase *novaDBMusica(char fileName[]);

void adicionaMusica(MusicaDatabase *musicas, Musica *musica);

void printMusica(Musica *musica);

Musica *lerMusica(FILE *f);

Musica *lerMusicaUI();

#endif // START_H