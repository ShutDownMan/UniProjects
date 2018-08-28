#include "uielem.h"

void setupConsole() {
	HANDLE hOut;
	COORD consoleSize;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	SetConsoleTitle("Spotifake");

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;

//	consoleSize = GetLargestConsoleWindowSize(hOut);
//	CONSOLE_WIDTH = consoleSize.X;

	SetConsoleCursorInfo(hOut, &ConCurInf);
}

Position *createPosition(int x, int y) {
	Position *newPosition = malloc(sizeof(Position));

	newPosition->x = 0;
	newPosition->y = 0;

	return newPosition;
}

Button *createButton(char *text) {
	Button *newButton = (Button *)malloc(sizeof(Button));

	newButton->x = 0;
	newButton->y = 0;
	newButton->selected = 0;
	newButton->text = text;

	return newButton;
}

void printButton(Button *button) {
	int textSize = strlen(button->text);

	gotoXY(button->x, button->y);
	printHorizontalLimit(textSize, button->selected);

	gotoXY(button->x, button->y+1);
	putchar('|');
	printf("%s", button->text);
	printf("|");

	gotoXY(button->x, button->y+2);
	printHorizontalLimit(textSize, button->selected);
}

char *printHorizontalLimit(int textSize, int selected) {
	int i;

	putchar('+');
	if(textSize > 3) {
		putchar(' ');
		for(i = 0; i < textSize-2; ++i) {
			putchar((selected) ? '=': '-');
		}
		putchar(' ');
	} else if(textSize > 1) {
		printf("--");
	} else {
		putchar('-');
	}

	putchar('+');
}

void printHorizontalDivision() {
	int i;

	for(i = 0; i < CONSOLE_WIDTH; ++i) {
		putchar('-');
	}
	printf("\n");
}

void gotoXY(int x, int y) {
	HANDLE han;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	han = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(han, pos);
}