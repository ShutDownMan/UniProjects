#include "menus.h"

//- MAIN MENU -//

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

//- MUSICS MENU -//

void musicsMenu(AppDatabase *db) {
	MusicsMenuUI *musicsMenuUI = initializeMusicsMenuUI();
	char charInput;
	MusicsMenuChoices choice = NONE;

	drawMusicsMenu(musicsMenuUI);

	do {
		charInput = getch();

		menuUIArrowControl(musicsMenuUI->info, charInput);
		drawMusicsMenu(musicsMenuUI);

		if(charInput == RETURN_KEY && musicsMenuUI->info->selectedElement) {
			if(musicsMenuUI->info->selectedElement == musicsMenuUI->newMusicMenuButton) {
				choice = NewMusicMenu;
			} else if(musicsMenuUI->info->selectedElement == musicsMenuUI->searchMusicMenuButton) {
				choice = SearchMusicMenu;
			} else if(musicsMenuUI->info->selectedElement == musicsMenuUI->exitMenuButton) {
				choice = ExitMusicsMenu;
			}
		}

		switch(choice) {
			case NewMusicMenu:
				// TODO: Load New Music Menu
				break;
			case SearchMusicMenu:
				// TODO: Load Search Musics Menu
				break;
			case ExitMusicsMenu:
				// TODO: Add exit confirmation
				break;
			default: break;
		}

	} while(choice != ExitMusicsMenu);

	freeMusicsMenuUI(musicsMenuUI);
}

MusicsMenuUI *initializeMusicsMenuUI() {
	MusicsMenuUI *musicsMenuUI = malloc(sizeof(MusicsMenuUI));

	musicsMenuUI->info = createMenuUI();

	PageHeader *musicsMenuHeader = createPageHeader("Musics Menu", 6);

	Button *newMusicMenuButton = createButton("[N]ew Music");
	newMusicMenuButton->alignment = -1;

	Button *searchMusicMenuButton = createButton("[S]earch Music");
	searchMusicMenuButton->alignment = 1;

	Button *exitMenuButton = createButton("[E]xit Musics Menu");
	exitMenuButton->alignment = -1;
	exitMenuButton->borders = FALSE;

	UIElement *musicsMenuHeaderElem = createUIElem(musicsMenuHeader, PageHeaderElem);
	UIElement *newMusicMenuButtonElem = createUIElem(newMusicMenuButton, ButtonElem);
	UIElement *searchMusicMenuButtonElem = createUIElem(searchMusicMenuButton, ButtonElem);
	UIElement *exitMenuButtonElem = createUIElem(exitMenuButton, ButtonElem);

	newMusicMenuButtonElem->hotkey = 'n';
	searchMusicMenuButtonElem->hotkey = 's';
	exitMenuButtonElem->hotkey = 'e';

	musicsMenuUI->info->uiElements = createList();
	addToList(musicsMenuUI->info->uiElements, musicsMenuHeaderElem);
	addToList(musicsMenuUI->info->uiElements, newMusicMenuButtonElem);
	addToList(musicsMenuUI->info->uiElements, searchMusicMenuButtonElem);
	addToList(musicsMenuUI->info->uiElements, exitMenuButtonElem);

	musicsMenuHeaderElem->down = newMusicMenuButtonElem;

	newMusicMenuButtonElem->up = musicsMenuHeaderElem;
	newMusicMenuButtonElem->right = searchMusicMenuButtonElem;
	newMusicMenuButtonElem->down = exitMenuButtonElem;

	searchMusicMenuButtonElem->up = musicsMenuHeaderElem;
	searchMusicMenuButtonElem->left = newMusicMenuButtonElem;
	searchMusicMenuButtonElem->down = exitMenuButtonElem;

	exitMenuButtonElem->up = newMusicMenuButtonElem;

	musicsMenuUI->musicsMenuHeader = musicsMenuHeaderElem;
	musicsMenuUI->newMusicMenuButton = newMusicMenuButtonElem;
	musicsMenuUI->searchMusicMenuButton = searchMusicMenuButtonElem;
	musicsMenuUI->exitMenuButton = exitMenuButtonElem;

	musicsMenuUI->info->selectedElement = musicsMenuHeaderElem;
	setSelectedUIElem(musicsMenuHeaderElem, TRUE);

	return musicsMenuUI;
}

void drawMusicsMenu(MusicsMenuUI *musicsMenuUI) {
	COORD cursorPos;

	system("cls");

	printPageHeader(UIElementToPageHeader(musicsMenuUI->musicsMenuHeader));

	printf("\n\n");
	printButton(UIElementToButton(musicsMenuUI->newMusicMenuButton));

	cursorPos = getCursorPosition();
	cursorPos.Y += -3;
	gotoXY(cursorPos.X, cursorPos.Y);
	printButton(UIElementToButton(musicsMenuUI->searchMusicMenuButton));

	printf("\n\n");
	printButton(UIElementToButton(musicsMenuUI->exitMenuButton));
}

void freeMusicsMenuUI(MusicsMenuUI *musicsMenuUI) {
	freeMenuUI(musicsMenuUI->info);
}

//- PLAYLISTS MENU -//