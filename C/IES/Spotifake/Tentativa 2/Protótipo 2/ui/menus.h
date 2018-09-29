#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "..\src\start.h"
#include "..\ui\ui_manipulation.h"

#include "main_menu.h"
#include "musics_menu.h"

//- MAIN MENU -//

//- MUSICS MENU -//

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
	SaveNewMusic,
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
	UIElement *saveButton, *cancelButton, *exitMenuButton; //< Buttons
	UIElement *titleForm, *singerForm, *authorForm, *genreForm, *yearForm, *durationForm, *ratingForm; //< Forms
} NewMusicMenuUI;

void newMusicMenu(AppDatabase *db);

NewMusicMenuUI *initializeNewMusicMenuUI();

void drawNewMusicMenu(NewMusicMenuUI *newMusicMenuUI);

char *durationFormInputRead(Form *form);

char *ratingFormInputRead(Form *form);

void freeNewMusicMenuUI(NewMusicMenuUI *newMusicMenuUI);

#endif // MENUS_H