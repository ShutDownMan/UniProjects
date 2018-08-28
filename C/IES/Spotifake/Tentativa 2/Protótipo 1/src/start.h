#ifndef START_H
#define START_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#include "uielem.h"
#include "string_manipulation.h"

typedef struct mainMenuUI {
	Button *musicButton, *playlistButton, *exitButton;
	Button *buttonsPositions[2][2];
	Position *selectedPosition;
	int buttonsHeight, buttonsWidth;
} MainMenuUI;

typedef enum mainMenuOptions {
	MUSIC,
	PLAYLIST,
	EXIT
} MainMenuOptions;

void mainMenu();

MainMenuUI *initializeMainMenuUI();

MainMenuOptions mainMenuButtonSelect(Button *buttonSelected);

MainMenuOptions getMainMenuOptions(char *str);


#endif // START_H