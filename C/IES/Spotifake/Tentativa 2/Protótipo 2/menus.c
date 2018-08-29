#include "menus.h"

//- MAIN MENU -//

void mainMenu(AppDatabase *db) {
	MainMenuUI *mainMenuUI = initializeMainMenuUI();
	char charInput;
	MainMenuChoices choice = NONE;

	drawMainMenu(mainMenuUI);

	do {
		charInput = getch();

		choice = uiArrowControl(mainMenuUI, charInput);
		drawMainMenu(mainMenuUI);

		switch(choice) {
			case MusicsMenu:
				// TODO: Load Musics Menu
				break;
			case PlaylistsMenu:
				// TODO: Load Playlists Menu
				break;
			case ExitApplication:
				// TODO: Add exit confirmation
				break;
			default: break;
		}

	} while(choice != ExitApplication);

	// TODO: Free mainMenuUI
}

void drawMainMenu(MainMenuUI *mainMenuUI) {
	COORD cursorPos;

	system("cls");

	printPageHeader(UIElementToPageHeader(mainMenuUI->mainMenuHeader));

	printf("\n\n");
	printButton(UIElementToButton(mainMenuUI->musicMenuButton));

	cursorPos = getCursorPosition();
	cursorPos.Y += -2;
	gotoXY(cursorPos.X, cursorPos.Y);
	printButton(UIElementToButton(mainMenuUI->playlistMenuButton));

	printf("\n\n");
	printButton(UIElementToButton(mainMenuUI->exitAppButton));
}

MainMenuUI *initializeMainMenuUI() {
	MainMenuUI *mainMenuUI = malloc(sizeof(MainMenuUI));

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

	mainMenuUI->selectedElement = mainMenuHeaderElem;
	setSelectedUIElem(mainMenuHeaderElem, TRUE);

	return mainMenuUI;
}

MainMenuChoices uiArrowControl(MainMenuUI *mainMenuUI, char charInput) {
	MainMenuChoices choice = NONE;

	setSelectedUIElem(mainMenuUI->selectedElement, FALSE);
	switch(charInput) {
		case LEFT_ARROW_KEY:
			if(mainMenuUI->selectedElement->left) {
				mainMenuUI->selectedElement = mainMenuUI->selectedElement->left;
			}
			break;
		case RIGHT_ARROW_KEY:
			if(mainMenuUI->selectedElement->right) {
				mainMenuUI->selectedElement = mainMenuUI->selectedElement->right;
			}
			break;
		case UP_ARROW_KEY:
			if(mainMenuUI->selectedElement->up) {
				mainMenuUI->selectedElement = mainMenuUI->selectedElement->up;
			}
			break;
		case DOWN_ARROW_KEY:
			if(mainMenuUI->selectedElement->down) {
				mainMenuUI->selectedElement = mainMenuUI->selectedElement->down;
			}
			break;
		case RETURN_KEY:
			if(mainMenuUI->selectedElement) {
				if(mainMenuUI->selectedElement == mainMenuUI->musicMenuButton) {
					return MusicsMenu;
				} else if(mainMenuUI->selectedElement == mainMenuUI->playlistMenuButton) {
					return PlaylistsMenu;
				} else if(mainMenuUI->selectedElement == mainMenuUI->exitAppButton) {
					return ExitApplication;
				}
			}
			case 'm':
				mainMenuUI->selectedElement = mainMenuUI->musicMenuButton;
				break;
			case 'p':
				mainMenuUI->selectedElement = mainMenuUI->playlistMenuButton;
				break;
			case 'e':
				mainMenuUI->selectedElement = mainMenuUI->exitAppButton;
				break;
			break;
		default: break;
	}
	setSelectedUIElem(mainMenuUI->selectedElement, TRUE);

	return choice;
}

//- MUSICS MENU -//

