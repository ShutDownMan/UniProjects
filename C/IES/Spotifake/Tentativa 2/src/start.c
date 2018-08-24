#include "start.h"

void mainMenu() {
	MainMenuUI *mainMenuUI = initializeMainMenuUI();
//	ArrowDirection *arrowDirection;
	int choice;

	setupConsole();

	gotoXY(CONSOLE_WIDTH-15, 8);
	printf("Spotifake v0.01\n");

	do {
//		system("cls");
		gotoXY(0, 0);
		printHorizontalDivision();

		printButton(mainMenuUI->musicButton);
		printButton(mainMenuUI->playlistButton);
		printButton(mainMenuUI->exitButton);
		printf("\n");
		printHorizontalDivision();

		choice = getch();

//		printf("\n");
//		printf("%d\n", choice);
//		arrowDirection = getArrowDirection();
		if(mainMenuUI->buttonsPositions[mainMenuUI->selectedPosition->y][mainMenuUI->selectedPosition->x])
			mainMenuUI->buttonsPositions[mainMenuUI->selectedPosition->y][mainMenuUI->selectedPosition->x]->selected = FALSE;
		switch(choice) {
			case LEFT_ARROW_KEY:
				if(mainMenuUI->selectedPosition->x-1 >= 0) {
					mainMenuUI->selectedPosition->x--;
				}
				break;
			case RIGHT_ARROW_KEY:
				if(mainMenuUI->selectedPosition->x+1 < mainMenuUI->buttonsWidth) {
					mainMenuUI->selectedPosition->x++;
				}
				break;
			case UP_ARROW_KEY:
				if(mainMenuUI->selectedPosition->y-1 >= 0) {
					mainMenuUI->selectedPosition->y--;
				}
				break;
			case DOWN_ARROW_KEY:
				if(mainMenuUI->selectedPosition->y+1 < mainMenuUI->buttonsHeight) {
					mainMenuUI->selectedPosition->y++;
				}
				break;
			case RETURN_KEY:
				choice = mainMenuButtonSelect(mainMenuUI->buttonsPositions[mainMenuUI->selectedPosition->y][mainMenuUI->selectedPosition->x]);
				break;
			default: break;
		}
		if(mainMenuUI->buttonsPositions[mainMenuUI->selectedPosition->y][mainMenuUI->selectedPosition->x])
			mainMenuUI->buttonsPositions[mainMenuUI->selectedPosition->y][mainMenuUI->selectedPosition->x]->selected = TRUE;
//		printf("%d\n", choice);
	} while(choice != EXIT_KEY);

}

MainMenuUI *initializeMainMenuUI() {
	MainMenuUI *mainMenuUI = malloc(sizeof(MainMenuUI));
	mainMenuUI->selectedPosition = createPosition(0, 0);

	mainMenuUI->musicButton = createButton("MUSIC");
	mainMenuUI->playlistButton = createButton("PLAYLIST");
	mainMenuUI->exitButton = createButton("EXIT");

	mainMenuUI->buttonsPositions[0][0] = mainMenuUI->musicButton;
	mainMenuUI->buttonsPositions[0][1] = mainMenuUI->playlistButton;
	mainMenuUI->buttonsPositions[1][0] = mainMenuUI->exitButton;
	mainMenuUI->buttonsPositions[1][1] = mainMenuUI->playlistButton;

	mainMenuUI->buttonsHeight = 2;
	mainMenuUI->buttonsWidth = 2;

	mainMenuUI->musicButton->selected = TRUE;

	mainMenuUI->musicButton->x = 1;
	mainMenuUI->musicButton->y = 2;

	mainMenuUI->playlistButton->x = 11;
	mainMenuUI->playlistButton->y = 2;

	mainMenuUI->exitButton->x = 1;
	mainMenuUI->exitButton->y = 6;

	return mainMenuUI;
}

MainMenuOptions mainMenuButtonSelect(Button *buttonSelected) {
	MainMenuOptions choice = getMainMenuOptions(buttonSelected->text);

	switch(choice) {
		case MUSIC:
			printf("Music menu...\n");
			break;
		case PLAYLIST:
			printf("Playlist menu...\n");
			break;
		case EXIT:
			printf("Exiting program...\n");
			return EXIT_KEY;
			break;
		default: break;
	}
}

MainMenuOptions getMainMenuOptions(char *str) {
	if(!strcmp(str, "MUSIC")) return MUSIC;
	if(!strcmp(str, "PLAYLIST")) return PLAYLIST;
	if(!strcmp(str, "EXIT")) return EXIT;

	return -1;
}
