#include "start.h"

/// inicializa database
AppDatabase *inicializaDB() {
	AppDatabase *novaDb = malloc(sizeof(AppDatabase));

	novaDb->musicas = NULL;
	novaDb->playlists = NULL;

	return novaDb;
}

/// Lê musicas do arquivo
MusicaDatabase *novaDBMusica(char fileName[]) {
	int i;
	FILE *f = fopen(fileName, "r+");
	MusicaDatabase *musicas = malloc(sizeof(MusicaDatabase));

	musicas->db_musicas = NULL;
	musicas->tamanho = 0;
	musicas->espacoAlocado = 0;

	for(i = 0; !feof(f); ++i) {
		adicionaMusica(musicas, lerMusica(f));
		printMusica(musicas->db_musicas[i]);
	}

	return musicas;
}

/// lê musica do arquivo
Musica *lerMusica(FILE *f) {
	Musica *novaMusica = malloc(sizeof(Musica));
	char str[STRMAX];

	fscanf(f, " %[^;]; ", novaMusica->titulo);
	fscanf(f, " %[^;]; ", novaMusica->interprete);
	fscanf(f, " %[^;]; ", novaMusica->autor);
	fscanf(f, " %d; ", &novaMusica->ano);
	fscanf(f, " %[^;]; ", novaMusica->genero);
	fscanf(f, " %d; ", &novaMusica->duracao);
	fscanf(f, " %d; ", &novaMusica->avaliacao);

	return novaMusica;
}

/// Adiciona música a database
void adicionaMusica(MusicaDatabase *musicas, Musica *musica) {
	printf("%d; %d;\n", musicas->tamanho, musicas->espacoAlocado);
	if(musicas->tamanho+1 > musicas->espacoAlocado) {
		if(!musicas->espacoAlocado) {
			musicas->espacoAlocado = 1;
			musicas->db_musicas = malloc(sizeof(Musica*));
		} else {
			musicas->espacoAlocado *= 2;
			musicas->db_musicas = realloc(musicas->db_musicas, sizeof(Musica*)*(musicas->espacoAlocado));
		}
	}
	musicas->db_musicas[musicas->tamanho++] = musica;
}

void printMusica(Musica *musica) {
	printf("--------------\n");
	printf("Titulo: %s\n", musica->titulo);
	printf("Interprete: %s\n", musica->interprete);
	printf("Autor: %s\n", musica->autor);
	printf("Ano: %d\n", musica->ano);
	printf("Genero: %s\n", musica->genero);
	printf("duracao: %d:%02d\n", musica->duracao/60, musica->duracao%60);
	printf("Avaliacao: %d\n", musica->avaliacao);
}

Musica *lerMusicaUI() {
	Musica *novaMusica = malloc(sizeof(Musica));
	char str[STRMAX];

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

	return novaMusica;
}

/*
/// lê playlist da tela
Playlist **adicionaPlaylist(Playlist **playlists, int *lengthPlaylists, Musica **musicas, int lengthMusicas) {
	(*lengthPlaylists)++;
	playlists = realloc(playlists, sizeof(Playlist*)*(*lengthPlaylists));

	playlists[(*lengthPlaylists)-1] = lerPlaylistUI();

	return playlists;
}

Playlist *lerPlaylistUI(Musica **musicas, int lengthMusicas) {
	Playlist *novaPlaylist = malloc(sizeof(Playlist));
	char str[STRMAX];

	printf("Titulo playlist: ");
	scanf("%[^\n]%*c", &str);
	printf("Titulo playlist: ");
	scanf("%[^\n]%*c", &str);
	while(choice()) {
		/// TODO: adiciona musica

	}
}

char choice() {
	char choice;

	printf("Deseja adicionar musica?\n[S] para continuar\n");
	scanf(" %c ", &choice);
	fflush(stdin);

	choice = (toupper(choice) == 'S');

	return choice;
}
*/