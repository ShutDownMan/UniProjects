#include <locale.h>
#include "start.h"

typedef enum mainMenu {
	adicionarMusica,
	adicionarPlaylist,
	pesquisarMusica,
	pesquisarPlaylist,
	deletarMusica,
	deletarPlaylist,
	SairMainMenu
} MainMenu;

MainMenu escolhaMainMenu();

int main(void) {
	AppDatabase *db = inicializaDB();
	/// inicializa db_musicas
	db->musicas = novaDBMusicas("musicas.txt");
	db->playlists = novaDBPlaylists("playlists.txt", db->musicas);

	MainMenu escolha;

	setlocale(LC_ALL, "Portuguese");

	do {
		escolha = escolhaMainMenu();
		switch(escolha) {
			case adicionarMusica:
				adicionaMusica(db->musicas, lerMusicaUI());
				break;
			case adicionarPlaylist:
				adicionaPlaylist(db->playlists, lerPlaylistUI(db));
				break;
			case pesquisarMusica:
				acharMusicaUI(db);
				break;
			case pesquisarPlaylist:
				acharPlaylistUI(db);
				break;
			case deletarMusica:
				deletarMusicaUI(db);
				break;
			case deletarPlaylist:
//				deletarPlaylistUI(db);
				break;
			case SairMainMenu:
				system("cls");
				printf("Exiting program...\n");
				getch();
				break;

			default: break;
		}
	} while(escolha != SairMainMenu);

	return 0;
}

MainMenu escolhaMainMenu() {
	int num;

	do {
		system("cls");
		printf("Opcoes: \n");
		printf("(1)-> Adiciona Musica\n");
		printf("(2)-> Adiciona Playlist\n");
		printf("(3)-> Pesquisa Musica\n");
		printf("(4)-> Pesquisa Playlist\n");
		printf("(5)-> Deleta Musica\n");
		printf("(6)-> Deleta Playlist\n");
		printf("(0)-> Voltar\n");

		printf("comando: ");
		scanf(" %d", &num);
		fflush(stdin);
		if(num < 0 || num > SairMainMenu) {
			printf("Digite um comando valido!\n");
			getch();
		} else if(num) {
			return (MainMenu)(num-1);
		}
	} while(num);

	return SairMainMenu;
}