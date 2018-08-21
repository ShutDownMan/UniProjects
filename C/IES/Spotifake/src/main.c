#include <locale.h>
#include "start.h"

int main(void) {
	AppDatabase *db = inicializaDB();
	// inicializa db_musicas
	db->musicas = novaDBMusicas("musicas.txt");
	db->playlists = novaDBPlaylists("playlists.txt", db->musicas);

	setlocale(LC_ALL, "Portuguese");

	// TODO: Create
//	adicionaMusica(db->musicas, lerMusicaUI());
	adicionaPlaylist(db->playlists, lerPlaylistUI(db));

	// TODO: Read
	acharMusicaUI(db);
	//acharPlaylistUI(db);

	// TODO: Delete

	return 0;
}