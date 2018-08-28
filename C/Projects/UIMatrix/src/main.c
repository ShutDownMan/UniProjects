#include "ui_main.h"

int main(int argc, char const *argv[]) {

	setupUI();

	do {
		updateUI();
	} while(TRUE);

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