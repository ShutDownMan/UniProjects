#include "start.h"

/// inicializa database
AppDatabase *inicializaDB() {
	AppDatabase *novaDb = malloc(sizeof(AppDatabase));

	novaDb->musicas = NULL;
	novaDb->playlists = NULL;

	return novaDb;
}

//- MUSICA -//

/// lê musicas do arquivo
MusicaDatabase *novaDBMusicas(char fileName[]) {
	int i;
	FILE *f = fopen(fileName, "r+");
	MusicaDatabase *musicas = inicializaMusicaDatabase();

	for(i = 0; !feof(f); ++i) {
		adicionaMusica(musicas, lerMusica(f));
	}

	fclose(f);

	return musicas;
}

/// inicializa MusicaDatabase
MusicaDatabase *inicializaMusicaDatabase() {
	MusicaDatabase *musicas = malloc(sizeof(MusicaDatabase));

	musicas->db_musicas = NULL;
	musicas->tamanho = 0;
	musicas->espacoAlocado = 0;
	musicas->final = 0;

	return musicas;
}

/// lê musica do arquivo
Musica *lerMusica(FILE *f) {
	Musica *novaMusica = malloc(sizeof(Musica));

	fscanf(f, " %[^;]; ", novaMusica->titulo);
	fscanf(f, " %[^;]; ", novaMusica->interprete);
	fscanf(f, " %[^;]; ", novaMusica->autor);
	fscanf(f, " %d ; ", &novaMusica->ano);
	fscanf(f, " %[^;]; ", novaMusica->genero);
	fscanf(f, " %d ; ", &novaMusica->duracao);
	fscanf(f, " %d ; ", &novaMusica->avaliacao);

	novaMusica->ativo = 1;

	return novaMusica;
}

/// adiciona música a database
void adicionaMusica(MusicaDatabase *musicas, Musica *musica) {
	if(musicas->tamanho+1 > musicas->espacoAlocado) {
		if(!musicas->espacoAlocado) {
			musicas->espacoAlocado = 1;
			musicas->db_musicas = malloc(sizeof(Musica*));
		} else {
			musicas->espacoAlocado *= 2;
			musicas->db_musicas = realloc(musicas->db_musicas, sizeof(Musica*)*(musicas->espacoAlocado));
		}
	}
	musicas->db_musicas[musicas->final++] = musica;
	musicas->tamanho++;
}

/// lê nova música da tela
Musica *lerMusicaUI() {
	Musica *novaMusica = malloc(sizeof(Musica));
	char str[STRMAX];

	printf("--------------\n");
	printf("Titulo: ");
	scanf(" %[^\n]%*c", novaMusica->titulo);

	printf("Interprete: ");
	scanf(" %[^\n]%*c", novaMusica->interprete);

	printf("Autor: ");
	scanf(" %[^\n]%*c", novaMusica->autor);

	printf("Ano: ");
	scanf(" %d", &novaMusica->ano);

	printf("Genero: ");
	scanf(" %[^\n]%*c", novaMusica->genero);

	printf("duracao: ");
	scanf(" %d", &novaMusica->duracao);

	printf("Avaliacao: ");
	scanf(" %d", &novaMusica->avaliacao);

	printf("\n");

	novaMusica->ativo = 1;

	return novaMusica;
}

//- PLAYLIST -//

// lê playlists do arquivo
PlaylistDatabase *novaDBPlaylists(char fileName[], MusicaDatabase *musicas) {
	int i, j;
	FILE *f = fopen(fileName, "r+");
	PlaylistDatabase *playlists = malloc(sizeof(PlaylistDatabase));

	playlists->db_playlists = NULL;
	playlists->tamanho = 0;
	playlists->espacoAlocado = 0;
	playlists->final = 0;

	for(i = 0; !feof(f); ++i) {
		adicionaPlaylist(playlists, lerPlaylist(f, musicas));
	}

	fclose(f);

	return playlists;
}

/// lê musica do arquivo
Playlist *lerPlaylist(FILE *f, MusicaDatabase *musicas) {
	Playlist *novaPlaylist = malloc(sizeof(Playlist));
	char str[STRMAX];
	int i, ind, n;

	fscanf(f, " %[^;]; ", novaPlaylist->titulo);
	fscanf(f, " %[^;]; ", novaPlaylist->proprietario);
	fscanf(f, " { %[^}]}; ", str);

	novaPlaylist->musicas = inicializaMusicaDatabase();

	for(i = 0; i < strlen(str); i += n) {
		sscanf(str+i, " %d ,%n", &ind, &n);
		printf("%d\n", ind);
		adicionaMusicaPlaylist(novaPlaylist, musicas->db_musicas[ind]);
		printMusica(musicas->db_musicas[ind]);
	}

	return novaPlaylist;
}

void adicionaMusicaPlaylist(Playlist *playlist, Musica *musica) {
	if(playlist && musica) {
		adicionaMusica(playlist->musicas, musica);
	}
}

/// adiciona playlista a lista de playlists
void adicionaPlaylist(PlaylistDatabase *playlists, Playlist *playlist) {
	if(playlists->tamanho+1 > playlists->espacoAlocado) {
		if(!playlists->espacoAlocado) {
			playlists->espacoAlocado = 1;
			playlists->db_playlists = malloc(sizeof(Playlist*));
		} else {
			playlists->espacoAlocado *= 2;
			playlists->db_playlists = realloc(playlists->db_playlists, sizeof(Playlist*)*(playlists->espacoAlocado));
		}
	}
	playlists->db_playlists[playlists->final++] = playlist;
	playlists->tamanho++;
}

/// lê playlist da tela
Playlist *lerPlaylistUI(AppDatabase *db) {
	Playlist *novaPlaylist = malloc(sizeof(Playlist));
	char str[STRMAX];

	novaPlaylist->musicas = inicializaMusicaDatabase();

	printf("Titulo playlist: ");
	scanf("%[^\n]%*c", novaPlaylist->titulo);
	printf("Proprietario playlist: ");
	scanf("%[^\n]%*c", novaPlaylist->proprietario);

	while(escolhaAdicionaMusica(novaPlaylist)) {
		Musica *musica = acharMusicaUI(db);
		adicionaMusicaPlaylist(novaPlaylist, musica);
	}
	adicionaPlaylist(db->playlists, novaPlaylist);

	return novaPlaylist;
}

char escolhaAdicionaMusica(Playlist *novaPlaylist) {
	char escolha;

	system("cls");
	printf("Titulo playlist: %s\n", novaPlaylist->titulo);
	printf("Proprietario playlist: %s\n\n", novaPlaylist->proprietario);

	printf("Deseja adicionar uma nova musica a Playlist?\n[S] para continuar\n");
	scanf(" %c", &escolha);
	fflush(stdin);

	escolha = (toupper(escolha) == 'S');

	return escolha;
}
