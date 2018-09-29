#ifndef MUSICS_MENU_H
#define MUSICS_MENU_H

#include "menus.h"

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

#endif //< MUSICS_MENU_H