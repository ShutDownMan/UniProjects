#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "start.h"
#include "ui_manipulation.h"

typedef enum mainMenuChoices {
	MusicsMenu,
	PlaylistsMenu,
	ExitApplication
} MainMenuChoices;

typedef struct mainMenuUI {
	UIElement *mainMenuHeader, *musicMenuButton, *playlistMenuButton, *exitAppButton;
	UIElement *selectedElement;
} MainMenuUI;

void mainMenu(AppDatabase *db);

void drawMainMenu(MainMenuUI *mainMenuUI);

MainMenuUI *initializeMainMenuUI();

MainMenuChoices uiArrowControl(MainMenuUI *mainMenuUI, char charInput);

#endif // MENUS_H