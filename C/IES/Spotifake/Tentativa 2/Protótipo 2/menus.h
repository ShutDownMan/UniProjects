#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "start.h"
#include "ui_manipulation.h"

//- MAIN MENU -//

/// this enum contains the choices available in main menu
typedef enum mainMenuChoices {
	MusicsMenu,
	PlaylistsMenu,
	ExitApplication
} MainMenuChoices;

/// this struct contains all UI elements present in main menu
typedef struct mainMenuUI {
	MenuUI *info;
	UIElement *mainMenuHeader; //< Page Header
	UIElement *musicMenuButton, *playlistMenuButton, *exitAppButton; //< Buttons
} MainMenuUI;

/**
	@brief main menu logic of application
	@param db, app database
	@precondition db is initialized and not NULL
	@postcondition main menu will be shown
*/
void mainMenu(AppDatabase *db);

/**
	@brief initializes main menu's ui elements struct
	@return struct initialized
	@precondition NONE
	@postcondition struct is initialized and returned
*/
MainMenuUI *initializeMainMenuUI();

/**
	@brief draws main menu's ui elements on screen
	@param mainMenuUI has all menu's UI elements
	@precondition mainMenuUI is initialized and not NULL
	@postcondition menu is shown on screen
*/
void drawMainMenu(MainMenuUI *mainMenuUI);

//- MUSICS MENU -//

typedef enum musicsMenuChoices {
	NewMusicMenu,
	SearchMusicMenu,
	ExitMusicsMenu
} MusicsMenuChoices;

typedef struct musicsMenuUI {
	MenuUI *info;
	UIElement *musicsMenuHeader; //< Page Header
	UIElement *newMusicMenuButton, *searchMusicMenuButton, *exitMenuButton; //< Buttons
} MusicsMenuUI;

void musicsMenu(AppDatabase *db);

MusicsMenuUI *initializeMusicsMenuUI();

void drawMusicsMenu(MusicsMenuUI *musicsMenuUI);

void freeMusicsMenuUI(MusicsMenuUI *musicsMenuUI);

//- PLAYLISTS MENU -//

typedef enum playlistsMenuChoices {
	NewPlaylistMenu,
	SearchPlaylistMenu,
	ExitPlaylistsMenu
} PlaylistsMenuChoices;

typedef struct playlistsMenuUI {
	MenuUI *info;
	UIElement *playlistsMenuHeader; //< Page Header
	UIElement *newPlaylistMenuButton, *searchPlaylistMenuButton, *exitMenuButton; //< Buttons
} PlaylistsMenuUI;

void playlistsMenu(AppDatabase *db);

PlaylistsMenuUI *initializePlaylistsMenuUI();

void drawPlaylistsMenu(PlaylistsMenuUI *playlistsMenuUI);

void freePlaylistsMenuUI(PlaylistsMenuUI *playlistsMenuUI);

//- NEW MUSIC MENU -//

typedef enum newMusicMenuChoices {
	SaveChangesNewMusic,
	ClearNewMusic,
	TitleNewMusicFormInput,
	SingerNewMusicFormInput,
	AuthorNewMusicFormInput,
	GenreNewMusicFormInput,
	YearNewMusicFormInput,
	DurationNewMusicFormInput,
	RatingNewMusicFormInput,
	ExitNewMusicMenu
} NewMusicMenuChoices;

typedef struct newMusicMenuUI {
	MenuUI *info;
	UIElement *newMusicMenuHeader; //< Page Header
	UIElement *saveChangesButton, *cancelButton, *exitMenuButton; //< Buttons
	UIElement *titleForm, *singerForm, *authorForm, *genreForm, *yearForm, *durationForm, *ratingForm; //< Forms
} NewMusicMenuUI;

void newMusicMenu(AppDatabase *db);

NewMusicMenuUI *initializeNewMusicMenuUI();

void drawNewMusicMenu(NewMusicMenuUI *newMusicMenuUI);

void freeNewMusicMenuUI(NewMusicMenuUI *newMusicMenuUI);

#endif // MENUS_H