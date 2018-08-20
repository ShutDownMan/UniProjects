#ifndef START_H
#define START_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

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

struct musicaDatabase;

typedef struct playlist {
	char titulo[STRMAX];
	char proprietario[STRMAX];
	struct musicaDatabase *musicas;
} Playlist;

typedef struct musicaDatabase {
	Musica **db_musicas;
	int tamanho, espacoAlocado, final;
} MusicaDatabase;

typedef struct playlistDatabase {
	Playlist **db_playlists;
	int tamanho, espacoAlocado, final;
} PlaylistDatabase;

typedef struct appDatabase {
	MusicaDatabase *musicas;
	PlaylistDatabase *playlists;
} AppDatabase;

#include "pesquisa.h"

AppDatabase *inicializaDB();

//- MUSICA -//

MusicaDatabase *novaDBMusicas(char fileName[]);

MusicaDatabase *inicializaMusicaDatabase();

void adicionaMusica(MusicaDatabase *musicas, Musica *musica);

Musica *lerMusica(FILE *f);

Musica *lerMusicaUI();

//- PLAYLIST -//

PlaylistDatabase *novaDBPlaylists(char fileName[], MusicaDatabase *musicas);

Playlist *lerPlaylist(FILE *f, MusicaDatabase *musicas);

void adicionaMusicaPlaylist(Playlist *playlist, Musica *musica);

void adicionaPlaylist(PlaylistDatabase *playlists, Playlist *playlist);

Playlist *lerPlaylistUI(AppDatabase *db);

char escolhaAdicionaMusica();

#endif // START_H