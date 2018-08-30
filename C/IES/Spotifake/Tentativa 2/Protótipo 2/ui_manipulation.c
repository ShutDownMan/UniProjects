#include "ui_manipulation.h"

//- INITIALIZE -//

void setupConsole() {
	HANDLE hOut;
	COORD consoleSize;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	SetConsoleTitle("Spotifake");

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;

	COORD bufferSize = {66, 30};

	SetConsoleScreenBufferSize(hOut, bufferSize);

	SetConsoleCursorInfo(hOut, &ConCurInf);
}

Position *createPosition(int x, int y) {
	Position *newPosition = malloc(sizeof(Position));

	newPosition->x = 0;
	newPosition->y = 0;

	return newPosition;
}

//- MENU UI -//

MenuUI *createMenuUI() {
	MenuUI *newMenuUI = malloc(sizeof(MenuUI));

	newMenuUI->uiElements = NULL;
	newMenuUI->selectedElement = NULL;

	return newMenuUI;
}


void menuUIArrowControl(MenuUI *menuUI, char charInput) {
	int i;

	setSelectedUIElem(menuUI->selectedElement, FALSE);
	switch(charInput) {
		case LEFT_ARROW_KEY:
			if(menuUI->selectedElement->left) {
				menuUI->selectedElement = menuUI->selectedElement->left;
			}
			break;
		case RIGHT_ARROW_KEY:
			if(menuUI->selectedElement->right) {
				menuUI->selectedElement = menuUI->selectedElement->right;
			}
			break;
		case UP_ARROW_KEY:
			if(menuUI->selectedElement->up) {
				menuUI->selectedElement = menuUI->selectedElement->up;
			}
			break;
		case DOWN_ARROW_KEY:
			if(menuUI->selectedElement->down) {
				menuUI->selectedElement = menuUI->selectedElement->down;
			}
			break;
		default: break;
	}
	for(i = 0; i < menuUI->uiElements->size; ++i) {
		UIElement *elem = (UIElement *)getListItemFromIndex(menuUI->uiElements, i);
		if(elem->hotkey == charInput) {
			menuUI->selectedElement = elem;
		}
	}
	setSelectedUIElem(menuUI->selectedElement, TRUE);
}

//- PAGEHEADER -//

PageHeader *createPageHeader(char *contextText, int height) {
	PageHeader *newPageHeader = malloc(sizeof(PageHeader));

	newPageHeader->selected = FALSE;
	newPageHeader->height = height;
	newPageHeader->contextText = contextText;
	newPageHeader->appVersion = "Spotifake v0.01";

	return newPageHeader;
}

void printPageHeader(PageHeader *pageHeader) {
	int i;

	gotoXY(0, 0);
	printHorizontalLimit(CONSOLE_WIDTH-1, pageHeader->selected);

	gotoXY(4, 1);
	printf("%s", pageHeader->contextText);
	for(i = 1; i < pageHeader->height-1; ++i) {
		gotoXY(0, i);
		putchar('|');
		gotoXY(CONSOLE_WIDTH, i);
		putchar('|');
		if(i+1 >= pageHeader->height-1) {
			gotoXY(CONSOLE_WIDTH-(strlen(pageHeader->appVersion)+2), i);
			printf("%s\n", pageHeader->appVersion);
		}
	}

	gotoXY(0, pageHeader->height-1);
	printHorizontalLimit(CONSOLE_WIDTH-1, pageHeader->selected);
}

//- BUTTON -//

Button *createButton(char *text) {
	Button *newButton = (Button *)malloc(sizeof(Button));

	newButton->position = NULL;
	newButton->fixed = FALSE;
	newButton->selected = FALSE;
	newButton->text = text;
	newButton->alignment = 0;

	return newButton;
}

void printButton(Button *button) {
	int textSize = strlen(button->text);

	if(button->fixed) {
		gotoXY(button->position->x, button->position->y);
		printHorizontalLimit(textSize+2, button->selected);

		gotoXY(button->position->x, button->position->y+1);
		putchar('|');
		printf(" %s ", button->text);
		putchar('|');

		gotoXY(button->position->x, button->position->y+2);
		printHorizontalLimit(textSize+2, button->selected);
	} else {
		if(!button->borders) {
			if(button->alignment < 0) {
				gotoXY(0, -1);
				if(!button->selected)
					printf("< %s  ", button->text);
				else
					printf(">>%s<<", button->text);
			} else if(button->alignment > 0) {
				gotoXY(CONSOLE_WIDTH-(textSize+4)+1,  -1);
				if(!button->selected)
					printf("  %s >", button->text);
				else
					printf(">>%s<<", button->text);
			}
		} else {
			COORD startCursorPosition = getCursorPosition();
			if(button->alignment < 0) {
				startCursorPosition.X = 0;
			} else if(button->alignment > 0) {
				startCursorPosition.X = CONSOLE_WIDTH-(textSize+4)+1;
			}
			gotoXY(startCursorPosition.X, startCursorPosition.Y);
			printHorizontalLimit(textSize+2, button->selected);

			gotoXY(startCursorPosition.X, startCursorPosition.Y+1);
			putchar('|');
			printf(" %s ", button->text);
			putchar('|');

			gotoXY(startCursorPosition.X, startCursorPosition.Y+2);
			printHorizontalLimit(textSize+2, button->selected);
		}
	}
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD pos;

	GetConsoleScreenBufferInfo(hOut, &SBInfo);

	if(x >= 0) {
		pos.X = x;
	} else {
		pos.X = SBInfo.dwCursorPosition.X;
	}

	if(y >= 0) {
		pos.Y = y;
	} else {
		pos.Y = SBInfo.dwCursorPosition.Y;
	}

	SetConsoleCursorPosition(hOut, pos);
}

COORD getCursorPosition() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	GetConsoleScreenBufferInfo(hOut, &SBInfo);

	return SBInfo.dwCursorPosition;
}

UIElement *createUIElem(void *element, UIElementType type) {
	UIElement *newUIElement = malloc(sizeof(UIElement));

	newUIElement->element = element;
	newUIElement->type = type;

	newUIElement->left = NULL;
	newUIElement->up = NULL;
	newUIElement->right = NULL;
	newUIElement->down = NULL;

	return newUIElement;
}


PageHeader *UIElementToPageHeader(UIElement *elem) {
	if(elem->type == PageHeaderElem) {
		return ((PageHeader*)elem->element);
	}

	return NULL;
}

Button *UIElementToButton(UIElement *elem) {
	if(elem->type == ButtonElem) {
		return ((Button*)elem->element);
	}

	return NULL;
}

void setSelectedUIElem(UIElement *elem, bool selected) {
	switch(elem->type) {
		case PageHeaderElem:
			((PageHeader*)elem->element)->selected = selected;
			break;
		case ButtonElem:
			UIElementToButton(elem)->selected = selected;
			break;
		default: break;
	}
}
