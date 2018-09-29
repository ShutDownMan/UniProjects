#include "main_menu.h"

void mainMenu(AppDatabase *db) {
	MainMenuUI *mainMenuUI = initializeMainMenuUI();
	char charInput;
	MainMenuChoices choice = NONE;

	drawMainMenu(mainMenuUI);

	do {
		charInput = getch();

		menuUIArrowControl(mainMenuUI->info, charInput);
		drawMainMenu(mainMenuUI);

		if(charInput == RETURN_KEY && mainMenuUI->info->selectedElement) {
			if(mainMenuUI->info->selectedElement == mainMenuUI->musicMenuButton) {
				choice = MusicsMenu;
			} else if(mainMenuUI->info->selectedElement == mainMenuUI->playlistMenuButton) {
				choice = PlaylistsMenu;
			} else if(mainMenuUI->info->selectedElement == mainMenuUI->exitAppButton) {
				choice = ExitApplication;
			}
		}

		switch(choice) {
			case MusicsMenu:
				musicsMenu(db);

				setSelectedUIElem(mainMenuUI->info->selectedElement, FALSE);
				mainMenuUI->info->selectedElement = mainMenuUI->mainMenuHeader;
				setSelectedUIElem(mainMenuUI->info->selectedElement, TRUE);

				drawMainMenu(mainMenuUI);
				choice = NONE;
				break;
			case PlaylistsMenu:
				playlistsMenu(db);

				setSelectedUIElem(mainMenuUI->info->selectedElement, FALSE);
				mainMenuUI->info->selectedElement = mainMenuUI->mainMenuHeader;
				setSelectedUIElem(mainMenuUI->info->selectedElement, TRUE);

				drawMainMenu(mainMenuUI);
				choice = NONE;
				break;
			case ExitApplication:
				// TODO: Add exit confirmation
				break;
			default: break;
		}

	} while(choice != ExitApplication);

	// TODO: Free mainMenuUI
}

MainMenuUI *initializeMainMenuUI() {
	MainMenuUI *mainMenuUI = malloc(sizeof(MainMenuUI));

	mainMenuUI->info = createMenuUI();

	PageHeader *mainMenuHeader = createPageHeader("Main Menu", 6);

	Button *musicMenuButton = createButton("[M]usics Menu");
	musicMenuButton->alignment = -1;

	Button *playlistMenuButton = createButton("[P]laylists Menu");
	playlistMenuButton->alignment = 1;

	Button *exitAppButton = createButton("[E]xit Application");
	exitAppButton->borders = FALSE;
	exitAppButton->alignment = -1;

	UIElement *mainMenuHeaderElem = createUIElem(mainMenuHeader, PageHeaderElem);
	UIElement *musicMenuButtonElem = createUIElem(musicMenuButton, ButtonElem);
	UIElement *playlistMenuButtonElem = createUIElem(playlistMenuButton, ButtonElem);
	UIElement *exitAppButtonElem = createUIElem(exitAppButton, ButtonElem);

	musicMenuButtonElem->hotkey = 'm';
	playlistMenuButtonElem->hotkey = 'p';
	exitAppButtonElem->hotkey = 'e';

	mainMenuUI->info->uiElements = createList();
	addToList(mainMenuUI->info->uiElements, mainMenuHeaderElem);
	addToList(mainMenuUI->info->uiElements, musicMenuButtonElem);
	addToList(mainMenuUI->info->uiElements, playlistMenuButtonElem);
	addToList(mainMenuUI->info->uiElements, exitAppButtonElem);

	mainMenuHeaderElem->down = musicMenuButtonElem;

	musicMenuButtonElem->up = mainMenuHeaderElem;
	musicMenuButtonElem->right = playlistMenuButtonElem;
	musicMenuButtonElem->down = exitAppButtonElem;

	playlistMenuButtonElem->left = musicMenuButtonElem;
	playlistMenuButtonElem->up = mainMenuHeaderElem;
	playlistMenuButtonElem->down = exitAppButtonElem;

	exitAppButtonElem->up = musicMenuButtonElem;
	exitAppButtonElem->right = playlistMenuButtonElem;

	mainMenuUI->mainMenuHeader = mainMenuHeaderElem;
	mainMenuUI->musicMenuButton = musicMenuButtonElem;
	mainMenuUI->playlistMenuButton = playlistMenuButtonElem;
	mainMenuUI->exitAppButton = exitAppButtonElem;

	mainMenuUI->info->selectedElement = mainMenuHeaderElem;
	setSelectedUIElem(mainMenuHeaderElem, TRUE);

	return mainMenuUI;
}

void drawMainMenu(MainMenuUI *mainMenuUI) {
	COORD cursorPos;

	system("cls");

	gotoXY(0, 0);
	printPageHeader(UIElementToPageHeader(mainMenuUI->mainMenuHeader));

	printf("\n\n");
	printButton(UIElementToButton(mainMenuUI->musicMenuButton));

	cursorPos = getCursorPosition();
	cursorPos.Y += -3;
	gotoXY(cursorPos.X, cursorPos.Y);
	printButton(UIElementToButton(mainMenuUI->playlistMenuButton));

	printf("\n\n");
	printButton(UIElementToButton(mainMenuUI->exitAppButton));
}
