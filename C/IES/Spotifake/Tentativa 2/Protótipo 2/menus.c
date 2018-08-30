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
				newMusicMenu(db);

				setSelectedUIElem(musicsMenuUI->info->selectedElement, FALSE);
				musicsMenuUI->info->selectedElement = musicsMenuUI->musicsMenuHeader;
				setSelectedUIElem(musicsMenuUI->info->selectedElement, TRUE);

				drawMusicsMenu(musicsMenuUI);
				choice = NONE;
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

void playlistsMenu(AppDatabase *db) {
	PlaylistsMenuUI *playlistsMenuUI = initializePlaylistsMenuUI();
	char charInput;
	MusicsMenuChoices choice = NONE;

	drawPlaylistsMenu(playlistsMenuUI);

	do {
		charInput = getch();

		menuUIArrowControl(playlistsMenuUI->info, charInput);
		drawPlaylistsMenu(playlistsMenuUI);

		if(charInput == RETURN_KEY && playlistsMenuUI->info->selectedElement) {
			if(playlistsMenuUI->info->selectedElement == playlistsMenuUI->newPlaylistMenuButton) {
				choice = NewPlaylistMenu;
			} else if(playlistsMenuUI->info->selectedElement == playlistsMenuUI->searchPlaylistMenuButton) {
				choice = SearchPlaylistMenu;
			} else if(playlistsMenuUI->info->selectedElement == playlistsMenuUI->exitMenuButton) {
				choice = ExitPlaylistsMenu;
			}
		}

		switch(choice) {
			case NewPlaylistMenu:
				// TODO: Load New Music Menu
				break;
			case SearchPlaylistMenu:
				// TODO: Load Search Musics Menu
				break;
			case ExitPlaylistsMenu:
				// TODO: Add exit confirmation
				break;
			default: break;
		}

	} while(choice != ExitPlaylistsMenu);

	freePlaylistsMenuUI(playlistsMenuUI);
}

PlaylistsMenuUI *initializePlaylistsMenuUI() {
	PlaylistsMenuUI *playlistsMenuUI = malloc(sizeof(PlaylistsMenuUI));

	playlistsMenuUI->info = createMenuUI();

	PageHeader *musicsMenuHeader = createPageHeader("Playlist Menu", 6);

	Button *newPlaylistMenuButton = createButton("[N]ew Playlist");
	newPlaylistMenuButton->alignment = -1;

	Button *searchPlaylistMenuButton = createButton("[S]earch Playlist");
	searchPlaylistMenuButton->alignment = 1;

	Button *exitMenuButton = createButton("[E]xit Musics Menu");
	exitMenuButton->alignment = -1;
	exitMenuButton->borders = FALSE;

	UIElement *playlistsMenuHeaderElem = createUIElem(musicsMenuHeader, PageHeaderElem);
	UIElement *newPlaylistMenuButtonElem = createUIElem(newPlaylistMenuButton, ButtonElem);
	UIElement *searchPlaylistMenuButtonElem = createUIElem(searchPlaylistMenuButton, ButtonElem);
	UIElement *exitMenuButtonElem = createUIElem(exitMenuButton, ButtonElem);

	newPlaylistMenuButtonElem->hotkey = 'n';
	searchPlaylistMenuButtonElem->hotkey = 's';
	exitMenuButtonElem->hotkey = 'e';

	playlistsMenuUI->info->uiElements = createList();
	addToList(playlistsMenuUI->info->uiElements, playlistsMenuHeaderElem);
	addToList(playlistsMenuUI->info->uiElements, newPlaylistMenuButtonElem);
	addToList(playlistsMenuUI->info->uiElements, searchPlaylistMenuButtonElem);
	addToList(playlistsMenuUI->info->uiElements, exitMenuButtonElem);

	playlistsMenuHeaderElem->down = newPlaylistMenuButtonElem;

	newPlaylistMenuButtonElem->up = playlistsMenuHeaderElem;
	newPlaylistMenuButtonElem->right = searchPlaylistMenuButtonElem;
	newPlaylistMenuButtonElem->down = exitMenuButtonElem;

	searchPlaylistMenuButtonElem->up = playlistsMenuHeaderElem;
	searchPlaylistMenuButtonElem->left = newPlaylistMenuButtonElem;
	searchPlaylistMenuButtonElem->down = exitMenuButtonElem;

	exitMenuButtonElem->up = newPlaylistMenuButtonElem;

	playlistsMenuUI->playlistsMenuHeader = playlistsMenuHeaderElem;
	playlistsMenuUI->newPlaylistMenuButton = newPlaylistMenuButtonElem;
	playlistsMenuUI->searchPlaylistMenuButton = searchPlaylistMenuButtonElem;
	playlistsMenuUI->exitMenuButton = exitMenuButtonElem;

	playlistsMenuUI->info->selectedElement = playlistsMenuHeaderElem;
	setSelectedUIElem(playlistsMenuHeaderElem, TRUE);

	return playlistsMenuUI;
}

void drawPlaylistsMenu(PlaylistsMenuUI *playlistsMenuUI) {
	COORD cursorPos;

	system("cls");

	printPageHeader(UIElementToPageHeader(playlistsMenuUI->playlistsMenuHeader));

	printf("\n\n");
	printButton(UIElementToButton(playlistsMenuUI->newPlaylistMenuButton));

	cursorPos = getCursorPosition();
	cursorPos.Y += -3;
	gotoXY(cursorPos.X, cursorPos.Y);
	printButton(UIElementToButton(playlistsMenuUI->searchPlaylistMenuButton));

	printf("\n\n");
	printButton(UIElementToButton(playlistsMenuUI->exitMenuButton));
}

void freePlaylistsMenuUI(PlaylistsMenuUI *playlistsMenuUI) {
	freeMenuUI(playlistsMenuUI->info);
}

//- NEW MUSIC MENU -//

void newMusicMenu(AppDatabase *db) {
	NewMusicMenuUI *newMusicMenuUI = initializeNewMusicMenuUI();
	char charInput;
	NewMusicMenuChoices choice = NONE;

	drawNewMusicMenu(newMusicMenuUI);

	do {
		charInput = getch();

		menuUIArrowControl(newMusicMenuUI->info, charInput);
		drawNewMusicMenu(newMusicMenuUI);

		if(charInput == RETURN_KEY && newMusicMenuUI->info->selectedElement) {
			if(newMusicMenuUI->saveChangesButton == newMusicMenuUI->info->selectedElement) {
				choice = SaveChangesNewMusic;
			}
			if(newMusicMenuUI->cancelButton == newMusicMenuUI->info->selectedElement) {
				choice = CancelNewMusic;
			}
			if(newMusicMenuUI->exitMenuButton == newMusicMenuUI->info->selectedElement) {
				choice = ExitNewMusicMenu;
			}
		}

		switch(choice) {
			case SaveChangesNewMusic:
				// TODO: Load New Music Menu
				break;
			case CancelNewMusic:
				// TODO: Load Search Musics Menu
				break;
			case ExitNewMusicMenu:
				// TODO: Add exit confirmation
				break;
			default: break;
		}

	} while(choice != ExitNewMusicMenu);

	freeNewMusicMenuUI(newMusicMenuUI);
}

NewMusicMenuUI *initializeNewMusicMenuUI() {
	NewMusicMenuUI *newMusicMenuUI = malloc(sizeof(NewMusicMenuUI));

	newMusicMenuUI->info = createMenuUI();

	PageHeader *newMusicMenuHeader = createPageHeader("New Music Menu", 6);

	Button *saveChangesButton = createButton("[S]ave Changes");
	saveChangesButton->alignment = -1;

	Button *cancelButton = createButton("[C]ancel");
	cancelButton->alignment = 1;

	Button *exitMenuButton = createButton("[E]xit New Music Menu");
	exitMenuButton->alignment = -1;
	exitMenuButton->borders = FALSE;

	Form *titleForm = createForm("Title:");
	titleForm->alignment = -1;

	Form *singerForm = createForm("Singer:");
	singerForm->alignment = -1;

	Form *authorForm = createForm("Author:");
	authorForm->alignment = -1;

	Form *genreForm = createForm("Genre:");
	genreForm->alignment = -1;

	UIElement *newMusicMenuHeaderElem = createUIElem(newMusicMenuHeader, PageHeaderElem);
	UIElement *titleFormElem = createUIElem(titleForm, FormElem);
	UIElement *singerFormElem = createUIElem(singerForm, FormElem);
	UIElement *authorFormElem = createUIElem(authorForm, FormElem);
	UIElement *genreFormElem = createUIElem(genreForm, FormElem);
	UIElement *saveChangesButtonElem = createUIElem(saveChangesButton, ButtonElem);
	UIElement *cancelButtonElem = createUIElem(cancelButton, ButtonElem);
	UIElement *exitMenuButtonElem = createUIElem(exitMenuButton, ButtonElem);

	saveChangesButtonElem->hotkey = 's';
	cancelButtonElem->hotkey = 'c';
	exitMenuButtonElem->hotkey = 'e';

	newMusicMenuUI->info->uiElements = createList();
	addToList(newMusicMenuUI->info->uiElements, newMusicMenuHeaderElem);
	addToList(newMusicMenuUI->info->uiElements, titleFormElem);
	addToList(newMusicMenuUI->info->uiElements, singerFormElem);
	addToList(newMusicMenuUI->info->uiElements, authorFormElem);
	addToList(newMusicMenuUI->info->uiElements, genreFormElem);
	addToList(newMusicMenuUI->info->uiElements, saveChangesButtonElem);
	addToList(newMusicMenuUI->info->uiElements, cancelButtonElem);
	addToList(newMusicMenuUI->info->uiElements, exitMenuButtonElem);

	newMusicMenuHeaderElem->down = titleFormElem;

	titleFormElem->up = newMusicMenuHeaderElem;
	titleFormElem->down = singerFormElem;

	singerFormElem->up = titleFormElem;
	singerFormElem->down = authorFormElem;

	authorFormElem->up = singerFormElem;
	authorFormElem->down = genreFormElem;

	genreFormElem->up = authorFormElem;
	genreFormElem->down = saveChangesButtonElem;

	saveChangesButtonElem->up = genreFormElem;
	saveChangesButtonElem->right = cancelButtonElem;
	saveChangesButtonElem->down = exitMenuButtonElem;

	cancelButtonElem->up = newMusicMenuHeaderElem;
	cancelButtonElem->left = saveChangesButtonElem;
	cancelButtonElem->down = exitMenuButtonElem;

	exitMenuButtonElem->up = saveChangesButtonElem;

	newMusicMenuUI->newMusicMenuHeader = newMusicMenuHeaderElem;
	newMusicMenuUI->titleForm = titleFormElem;
	newMusicMenuUI->singerForm = singerFormElem;
	newMusicMenuUI->authorForm = authorFormElem;
	newMusicMenuUI->genreForm = genreFormElem;
	newMusicMenuUI->saveChangesButton = saveChangesButtonElem;
	newMusicMenuUI->cancelButton = cancelButtonElem;
	newMusicMenuUI->exitMenuButton = exitMenuButtonElem;

	newMusicMenuUI->info->selectedElement = newMusicMenuHeaderElem;
	setSelectedUIElem(newMusicMenuHeaderElem, TRUE);

	return newMusicMenuUI;
}

void drawNewMusicMenu(NewMusicMenuUI *newMusicMenuUI) {
	COORD cursorPos;

	system("cls");

	printPageHeader(UIElementToPageHeader(newMusicMenuUI->newMusicMenuHeader));

	printf("\n\n");
	printForm(UIElementToForm(newMusicMenuUI->titleForm));
	printf("\n");
	printForm(UIElementToForm(newMusicMenuUI->singerForm));
	printf("\n");
	printForm(UIElementToForm(newMusicMenuUI->authorForm));
	printf("\n");
	printForm(UIElementToForm(newMusicMenuUI->genreForm));

	printf("\n\n");
	printButton(UIElementToButton(newMusicMenuUI->saveChangesButton));

	cursorPos = getCursorPosition();
	cursorPos.Y += -3;
	gotoXY(cursorPos.X, cursorPos.Y);
	printButton(UIElementToButton(newMusicMenuUI->cancelButton));


	printf("\n\n");
	printButton(UIElementToButton(newMusicMenuUI->exitMenuButton));
}

void freeNewMusicMenuUI(NewMusicMenuUI *newMusicMenuUI) {
	freeMenuUI(newMusicMenuUI->info);
}