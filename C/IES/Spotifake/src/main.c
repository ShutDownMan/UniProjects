#include <stdio.h>
#include "start.h"

int main(void) {
	AppDatabase *db = inicializaDB();
	// inicializa db_musicas
	db->musicas = novaDBMusica("musicas.txt");

	// TODO: Create
	adicionaMusica(db->musicas, lerMusicaUI());
//	adicionaPlaylist(db_playlists, &playlistLength, db_musicas, musicasLength);

	// TODO: Read

	// TODO: Delete

	return 0;
}