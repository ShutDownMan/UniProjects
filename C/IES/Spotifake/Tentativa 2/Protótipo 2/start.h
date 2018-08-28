#ifndef START_H
#define START_H

#define bool unsigned char

#define STRMAX 256

typedef struct appDatabase {
	List *db_musics;
	List *db_playlists;
} AppDatabase;

typedef struct music {
	char title[STRMAX];
	char singer[STRMAX];
	char author[STRMAX];
	char genre[STRMAX];
	unsigned int year, duration;
	unsigned char rating, active;
} Music;

typedef struct playlist {
	char title[STRMAX];
	char owner[STRMAX];
	List *musicas;
	unsigned char ativo;
} Playlist;

typedef struct filters {
	bool *filterList;
	int length;
} Filters;


/**
	@brief add music to database
	@param db, app database
	@param newMusic, music to be added
	@precondition db and newMusic are initialized and not NULL
	@postcondition newMusic is added to the music database
*/
void addNewMusicToDatabase(AppDatabase *db, Music *newMusic);

/**
	@brief add playlist to database
	@param db, app database
	@param newPlaylist, playlist to be added
	@precondition db and newPlaylist are initialized and not NULL
	@postcondition newPlaylist is added to the playlist database
*/
void addNewPlaylistToDatabase(AppDatabase *db, Playlist *newPlaylist);

/**
	@brief adds music no playlist
	@param playlist, playlist to be modified
	@param music, music to be added
	@precondition playlist and musica are initialized and not NULL
	@postcondition music is added to playlist
*/
void addMusicToPlaylist(Playlist *playlist, Music *music);

/**
	@brief searches and returns list of matching musics from the database
	@param db, app database
	@param searchStr, string containing user search
	@param filters, filters used for the search
	@return a list of (Music *)
	@precondition db and filters are initialized and not NULL
	@postcondition a list of music is allocated and returned
*/
List *searchMusicDatabase(AppDatabase *db, char *searchStr, Filters *filters);

/**
	@brief searches and returns list of matching playlists from the database
	@param db, app database
	@param searchStr, string containing user search
	@param filters, filters used for the search
	@return a list of (Playlist *)
	@precondition db and filters are initialized and not NULL
	@postcondition a list of music is allocated and returned
*/
List *searchPlaylistDatabase(AppDatabase *db, char *searchStr, Filters *filters);

/**
	@brief copies attributes from newMusic to oldMusic
	@param oldMusic, Music to be modified
	@param newMusic, attributes to be modified to
	@precondition oldMusic and newMusic are initialized and not NULL
	@postcondition all attributes are checked for changes and if any \
	oldMusic is modified
*/
void modifyMusic(Music *oldMusic, Music *newMusic);

/**
	@brief copies attributes from newPlaylist to oldPlaylist
	@param oldPlaylist, Playlist to be modified
	@param newPlaylist, attributes to be modified to
	@precondition oldPlaylist and newPlaylist are initialized and not NULL
	@postcondition all attributes are checked for changes and if any \
	oldPlaylist is modified
*/
void modifyPlaylist(Playlist *oldPlaylist, Playlist *newPlaylist);

/**
	@brief remove music from database
	@param db, database to be modified
	@param music, music to be removed
	@return TRUE if music was removed, FALSE if it wasn't
	@precondition db and music are initialized and NOT null
	@postcondition music is removed from database
*/
bool removeMusicFromDatabase(AppDatabase *db, Music *music);

/**
	@brief remove playlist from database
	@param db, database to be modified
	@param playlist, playlist to be removed
	@return TRUE if playlist was removed, FALSE if it wasn't
	@precondition db and playlist are initialized and NOT null
	@postcondition playlist is removed from database
*/
bool removePlaylistFromDatabase(AppDatabase *db, Playlist *playlist);

/**
	@brief remove music from playlist
	@param playlist, playlist to be modified
	@param music, music to be removed from the playlist
	@return TRUE if music was removed, FALSE if it wasn't
	@precondition playlist and music are initialized and NOT null
	@postcondition music is removed from the playlist
*/
bool removeMusicFromPlaylist(Playlist *playlist, Music *music);

#endif