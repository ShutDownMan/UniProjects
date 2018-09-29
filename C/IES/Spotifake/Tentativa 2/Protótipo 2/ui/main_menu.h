#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "menus.h"

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

#endif //< MAIN_MENU_H