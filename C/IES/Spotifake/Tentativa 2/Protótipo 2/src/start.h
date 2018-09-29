#ifndef START_H
#define START_H

#include "list.h"

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
	unsigned int year, duration, ID;
	unsigned char rating, active;
} Music;

typedef struct playlist {
	char title[STRMAX];
	char owner[STRMAX];
	List *musics;
	unsigned int ID;
	unsigned char active;
} Playlist;

typedef struct filters {
	bool *filterList;
	int length;
} Filters;

//- INITIALIZE -//

/**
	@brief allocates memory and initializes attributes for AppDatabase
	@return a new AppDatabase "instance"
	@precondition NONE
	@postcondition a new AppDatabase is initialized and returned
*/
AppDatabase *initializeAppDatabase();

/**
	@brief allocates memory and initializes attributes for Music
	@return a new Music "instance"
	@precondition NONE
	@postcondition a new Music is initialized and returned
*/
Music *initializeMusic();

/**
	@brief allocates memory and initializes attributes for Playlist
	@return a new Playlist "instance"
	@precondition NONE
	@postcondition a new Playlist is initialized and returned
*/
Playlist *initializePlaylist();

/**
	@brief allocates memory and initializes attributes for Filters
	@return a new Filters "instance"
	@precondition NONE
	@postcondition a new Filters is initialized and returned
*/
Filters *initializeFilters();

/**
	@brief allocates memory and initializes attributes for List
	@return a new List "instance"
	@precondition NONE
	@postcondition a new List is initialized and returned
*/
//List *initializeList();

//- CREATE -//

/**
	@brief add item to list
	@param list, list to be modified
	@param item, item to be added
	@precondition list and item are initialized and not NULL
	@postcondition item is added to list
*/
//void addToList(List *list, void *item);

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

//- READ -//

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
	@brief gets an item from the list given an index
	@param list, list to be traversed
	@param index, index of the item
	@return item found or NULL if not found
	@precondition list is initialized and not NULL, index is non-negative
	@postcondition item found is returned
*/
//void *getListItemFromIndex(List *list, int index);

//- UPDATE -//

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

//- DELETE -//

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

/**
	@brief remove item from list
	@param list to be modified
	@param item to be removed
	@return TRUE if item was removed, FALSE if it wasn't
	@precondition list and item are initialized and not NULL
	@postcondition item is removed from list
*/
//bool removeItemFromList(List *list, void *item);

#endif