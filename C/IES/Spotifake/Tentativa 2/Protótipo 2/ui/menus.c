#include "menus.h"

//- MAIN MENU -//

//- MUSICS MENU -//

//- PLAYLISTS MENU -//

void playlistsMenu(AppDatabase *db) {
	PlaylistsMenuUI *playlistsMenuUI = initializePlaylistsMenuUI();
	char charInput;
	PlaylistsMenuChoices choice = NONE;

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
	bool updateScreen = FALSE;
	NewMusicMenuChoices choice = NONE;

	drawNewMusicMenu(newMusicMenuUI);

	do {
		charInput = getch();

		menuUIArrowControl(newMusicMenuUI->info, charInput);
		drawNewMusicMenu(newMusicMenuUI);

		if(charInput == RETURN_KEY && newMusicMenuUI->info->selectedElement) {
			if(newMusicMenuUI->saveButton == newMusicMenuUI->info->selectedElement) {
				choice = SaveNewMusic;
			}
			if(newMusicMenuUI->cancelButton == newMusicMenuUI->info->selectedElement) {
				choice = ClearNewMusic;
			}
			if(newMusicMenuUI->titleForm == newMusicMenuUI->info->selectedElement) {
				choice = TitleNewMusicFormInput;
			}
			if(newMusicMenuUI->singerForm == newMusicMenuUI->info->selectedElement) {
				choice = SingerNewMusicFormInput;
			}
			if(newMusicMenuUI->authorForm == newMusicMenuUI->info->selectedElement) {
				choice = AuthorNewMusicFormInput;
			}
			if(newMusicMenuUI->genreForm == newMusicMenuUI->info->selectedElement) {
				choice = GenreNewMusicFormInput;
			}
			if(newMusicMenuUI->yearForm == newMusicMenuUI->info->selectedElement) {
				choice = YearNewMusicFormInput;
			}
			if(newMusicMenuUI->durationForm == newMusicMenuUI->info->selectedElement) {
				choice = DurationNewMusicFormInput;
			}
			if(newMusicMenuUI->ratingForm == newMusicMenuUI->info->selectedElement) {
				choice = RatingNewMusicFormInput;
			}
			if(newMusicMenuUI->exitMenuButton == newMusicMenuUI->info->selectedElement) {
				choice = ExitNewMusicMenu;
			}
		}

		setSelectedUIElem(newMusicMenuUI->info->selectedElement, FALSE);
		switch(choice) {
			case SaveNewMusic:
				// TODO: Load New Music Menu
				break;
			case ClearNewMusic:
				// TODO: Load Search Musics Menu
				break;
			case TitleNewMusicFormInput:
				plainTextFormInputRead(UIElementToForm(newMusicMenuUI->titleForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->singerForm;
				break;
			case SingerNewMusicFormInput:
				plainTextFormInputRead(UIElementToForm(newMusicMenuUI->singerForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->authorForm;
				break;
			case AuthorNewMusicFormInput:
				plainTextFormInputRead(UIElementToForm(newMusicMenuUI->authorForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->genreForm;
				break;
			case GenreNewMusicFormInput:
				plainTextFormInputRead(UIElementToForm(newMusicMenuUI->genreForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->yearForm;
				break;
			case YearNewMusicFormInput:
				numericFormInputRead(UIElementToForm(newMusicMenuUI->yearForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->durationForm;
				break;
			case DurationNewMusicFormInput:
				durationFormInputRead(UIElementToForm(newMusicMenuUI->durationForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->ratingForm;
				break;
			case RatingNewMusicFormInput:
				ratingFormInputRead(UIElementToForm(newMusicMenuUI->ratingForm));

				newMusicMenuUI->info->selectedElement = newMusicMenuUI->saveButton;
				break;

			case ExitNewMusicMenu:
				// TODO: Add exit confirmation
				break;
			default: break;
		}
		setSelectedUIElem(newMusicMenuUI->info->selectedElement, TRUE);
		if(choice != NONE && choice != ExitNewMusicMenu) {
			choice = NONE;
			updateScreen = TRUE;
		}
		if(updateScreen) drawNewMusicMenu(newMusicMenuUI);
		updateScreen = FALSE;

	} while(choice != ExitNewMusicMenu);

	freeNewMusicMenuUI(newMusicMenuUI);
}

NewMusicMenuUI *initializeNewMusicMenuUI() {
	NewMusicMenuUI *newMusicMenuUI = malloc(sizeof(NewMusicMenuUI));

	newMusicMenuUI->info = createMenuUI();

	PageHeader *newMusicMenuHeader = createPageHeader("New Music Menu", 6);

	Button *saveButton = createButton("[S]ave");
	saveButton->alignment = -1;

	Button *cancelButton = createButton("[C]lear");
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

	Form *yearForm = createForm("Year:");
	yearForm->alignment = -1;
	yearForm->inputSize = 4;

	Form *durationForm = createForm("Duration:");
//	durationForm->alignment = -1;
	durationForm->inputSize = 8;

	Form *ratingForm = createForm("Rating:");
	ratingForm->alignment = -1;
	ratingForm->inputSize = 5;

	UIElement *newMusicMenuHeaderElem = createUIElem(newMusicMenuHeader, PageHeaderElem);
	UIElement *titleFormElem = createUIElem(titleForm, FormElem);
	UIElement *singerFormElem = createUIElem(singerForm, FormElem);
	UIElement *authorFormElem = createUIElem(authorForm, FormElem);
	UIElement *genreFormElem = createUIElem(genreForm, FormElem);
	UIElement *yearFormElem = createUIElem(yearForm, FormElem);
	UIElement *durationFormElem = createUIElem(durationForm, FormElem);
	UIElement *ratingFormElem = createUIElem(ratingForm, FormElem);
	UIElement *saveButtonElem = createUIElem(saveButton, ButtonElem);
	UIElement *cancelButtonElem = createUIElem(cancelButton, ButtonElem);
	UIElement *exitMenuButtonElem = createUIElem(exitMenuButton, ButtonElem);

	saveButtonElem->hotkey = 's';
	cancelButtonElem->hotkey = 'c';
	exitMenuButtonElem->hotkey = 'e';

	newMusicMenuUI->info->uiElements = createList();
	addToList(newMusicMenuUI->info->uiElements, newMusicMenuHeaderElem);
	addToList(newMusicMenuUI->info->uiElements, titleFormElem);
	addToList(newMusicMenuUI->info->uiElements, singerFormElem);
	addToList(newMusicMenuUI->info->uiElements, authorFormElem);
	addToList(newMusicMenuUI->info->uiElements, genreFormElem);
	addToList(newMusicMenuUI->info->uiElements, yearFormElem);
	addToList(newMusicMenuUI->info->uiElements, durationFormElem);
	addToList(newMusicMenuUI->info->uiElements, ratingFormElem);
	addToList(newMusicMenuUI->info->uiElements, saveButtonElem);
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
	genreFormElem->down = yearFormElem;

	yearFormElem->up = genreFormElem;
	yearFormElem->right = durationFormElem;
	yearFormElem->down = ratingFormElem;

	durationFormElem->up = genreFormElem;
	durationFormElem->left = yearFormElem;
	durationFormElem->down = ratingFormElem;

	ratingFormElem->up = yearFormElem;
	ratingFormElem->down = saveButtonElem;

	saveButtonElem->up = ratingFormElem;
	saveButtonElem->right = cancelButtonElem;
	saveButtonElem->down = exitMenuButtonElem;

	cancelButtonElem->up = newMusicMenuHeaderElem;
	cancelButtonElem->left = saveButtonElem;
	cancelButtonElem->down = exitMenuButtonElem;

	exitMenuButtonElem->up = saveButtonElem;

	newMusicMenuUI->newMusicMenuHeader = newMusicMenuHeaderElem;
	newMusicMenuUI->titleForm = titleFormElem;
	newMusicMenuUI->singerForm = singerFormElem;
	newMusicMenuUI->authorForm = authorFormElem;
	newMusicMenuUI->genreForm = genreFormElem;
	newMusicMenuUI->yearForm = yearFormElem;
	newMusicMenuUI->durationForm = durationFormElem;
	newMusicMenuUI->ratingForm = ratingFormElem;
	newMusicMenuUI->saveButton = saveButtonElem;
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
	printForm(UIElementToForm(newMusicMenuUI->yearForm));
	printForm(UIElementToForm(newMusicMenuUI->durationForm));
	printf("\n\n");
	printForm(UIElementToForm(newMusicMenuUI->ratingForm));

	printf("\n\n");
	printButton(UIElementToButton(newMusicMenuUI->saveButton));

	cursorPos = getCursorPosition();
	cursorPos.Y += -3;
	gotoXY(cursorPos.X, cursorPos.Y);
	printButton(UIElementToButton(newMusicMenuUI->cancelButton));

	printf("\n\n");
	printButton(UIElementToButton(newMusicMenuUI->exitMenuButton));
}

char *durationFormInputRead(Form *form) {
	char *outputStr = malloc(sizeof(char)*form->inputSize+1);
	char inputStr[(form->inputSize-2)+1];
	char c = 0;
	int i, j, k;

	freeFormInput(form);

	gotoXY(form->inputPosition.X-1, form->inputPosition.Y);
	printf("%*c", form->inputSize+2, ' ');

	for(i = 0; i <= form->inputSize-2; ++i) {
		inputStr[i] = 0;
	}
	for(i = 0; i <= form->inputSize; ++i) {
		outputStr[i] = ' ';
	}
	outputStr[form->inputSize] = 0;

	c = getch();
	gotoXY(form->inputPosition.X, form->inputPosition.Y);
	printf("%s", outputStr);
	for(i = 0; c != RETURN_KEY; c = getch()) {
		gotoXY(form->inputPosition.X-1, form->inputPosition.Y);
		printf("%*c", form->inputSize+2, ' ');

		if(i < form->inputSize-2 && isdigit(c)) {
			inputStr[i++] = c;
		}
		if(c == BACKSPACE_KEY && i > 0) {
			inputStr[--i] = 0;
		}

		for(j = 0, k = i-1; j < form->inputSize; ++j, --k) {
			if(k >= 0) {
				if(j == 2 || j == 5)
					outputStr[(form->inputSize-1)-(j++)] = ':';
				outputStr[(form->inputSize-1)-j] = inputStr[k];
			} else {
				outputStr[(form->inputSize-1)-j] = ' ';
			}
		}

		gotoXY(form->inputPosition.X, form->inputPosition.Y);
		printf("%s", outputStr);
	}

	form->inputStr = outputStr;

	return outputStr;
}

char *ratingFormInputRead(Form *form) {
	int i, stars = 0;
	char c, *inputStr;

	gotoXY(form->inputPosition.X, form->inputPosition.Y);
	printf("%*c", form->inputSize, ' ');

	do {
		c = getch();
		if(isdigit(c) && c <= '5') {
			stars = c-'0';

			gotoXY(form->inputPosition.X, form->inputPosition.Y);
			printf("%*c", form->inputSize, ' ');

			gotoXY(form->inputPosition.X, form->inputPosition.Y);
			for(i = 0; i < c-'0'; ++i) {
				printf("*");
			}
		}

	} while(c != RETURN_KEY);

	inputStr = (char *)malloc(sizeof(char) * stars + 1);
	for(i = 0; i < stars; ++i) {
		inputStr[i] = '*';
	}
	inputStr[i] = 0;

	form->inputStr = inputStr;

	return inputStr;
}

void freeNewMusicMenuUI(NewMusicMenuUI *newMusicMenuUI) {
	freeMenuUI(newMusicMenuUI->info);
}