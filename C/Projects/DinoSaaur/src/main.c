#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include "ui_manipulation.h"

#define MAX_FLOORS 8

typedef enum dinosaurState {
	WALKING,
	JUMPING,
	CRAWLING,
	NONE
} DinosaurState;

typedef struct dinosaur {
	int x, y;
	int spriteOffsetX, spriteOffsetY;
	Sprite *sprite;
	DinosaurState dinosaurState;
} Dinosaur;

typedef struct floor {
	int x, y;
	int spriteOffsetX, spriteOffsetY;
	Sprite *sprite;
} Floor;

Dinosaur *initializeDinosaur();

Floor **initializeFloors(Floor *floors[]);

int main(int argc, char const *argv[]) {
	Dinosaur *dinosaur;
	Floor *floors[MAX_FLOORS];
	int i, choice;

	setupConsole();

	dinosaur = initializeDinosaur();
	initializeFloors(floors);

	while(1) {
		system("cls");
		for(i = 0; i < MAX_FLOORS; ++i) {
			printSprite(floors[i]->sprite, floors[i]->x+floors[i]->spriteOffsetX, floors[i]->y+floors[i]->spriteOffsetY);
//			floors[i]->x++;
		}
		printSprite(dinosaur->sprite, dinosaur->x+dinosaur->spriteOffsetX, dinosaur->y+dinosaur->spriteOffsetY);
		Sleep(200);
	}

/*	do {
		if(kbhit()) {
			c = getch();
		}
			case LEFT_ARROW_KEY:
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
	} while(choice != EXIT_KEY);
*/

	getch();
	return 0;
}

Dinosaur *initializeDinosaur() {
	Dinosaur *newDinosaur = malloc(sizeof(Dinosaur));

	newDinosaur->x = 10;
	newDinosaur->y = 18;
	newDinosaur->spriteOffsetX = -5;
	newDinosaur->spriteOffsetY = -18;
	newDinosaur->sprite = readSprite("dinosaur_idle.txt");
	newDinosaur->dinosaurState = NONE;

	return newDinosaur;
}

Floor **initializeFloors(Floor *floors[]) {
	int i;
	Floor *newFloor = malloc(sizeof(Floor));

	newFloor->x = 0;
	newFloor->y = 18;
	newFloor->spriteOffsetX = 0;
	newFloor->spriteOffsetY = -18;
	newFloor->sprite = readSprite("floor.txt");

	floors[0] = newFloor;

	for(i = 1; i < MAX_FLOORS; ++i) {
		floors[i] = malloc(sizeof(Floor));

		*floors[i] = *floors[0];

		floors[i]->x += i*22;
	}

	return floors;
}