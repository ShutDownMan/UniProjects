#include "musics_menu.h"

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