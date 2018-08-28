#include "ui_main.h"

//- SETUP -//

void setupUI() {
	Sprite *dinosaurSprite = readSprite("sprites\\dinosaur_idle.txt");
	UIEntity *dinosaurUIEntity = createUIEntity(dinosaurSprite, 10, 18);
	setupConsole();

	mainCanvas = setupCanvas(SCREEEN_HEIGHT, SCREEEN_WIDTH);
	addDinamicArray(mainCanvas->sprites, dinosaurUIEntity);
}

//- UPDATE -//

void updateUI() {
	int i;
	char *differenceScreen = generateDifferenceScreen(mainCanvas);

	Sleep(200);
}

