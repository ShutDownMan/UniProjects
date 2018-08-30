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

void freeMenuUI(MenuUI *menuUI) {
	int i;
	for(i = 0; i < menuUI->uiElements->size; ++i) {
		UIElement *elem = (UIElement *)getListItemFromIndex(menuUI->uiElements, i);
		freeUIElem(elem);

	}
	freeList(menuUI->uiElements);
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
	printRectangle(0, 0, CONSOLE_WIDTH, pageHeader->height-1, pageHeader->selected);

	gotoXY(4, 1);
	printf("%s", pageHeader->contextText);
	gotoXY(CONSOLE_WIDTH-(strlen(pageHeader->appVersion)+2), pageHeader->height-2);
	printf("%s", pageHeader->appVersion);

	gotoXY(0, pageHeader->height);
}

void freePageHeader(PageHeader *pageHeader) {
	free(pageHeader);
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
		printRectangle(button->position->x, button->position->y, button->position->x+textSize+2, button->position->y+2, button->selected);

		gotoXY(button->position->x+1, button->position->y+1);
		printf(" %s ", button->text);
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
				startCursorPosition.X = CONSOLE_WIDTH-(textSize+2);
			}
			// printf("%d // %d\n", startCursorPosition.X+textSize+2, startCursorPosition.Y);
			printRectangle(startCursorPosition.X, startCursorPosition.Y, startCursorPosition.X+textSize+2, startCursorPosition.Y+2, button->selected);

			gotoXY(startCursorPosition.X+1, startCursorPosition.Y+1);
			printf("%s", button->text);
			gotoXY(startCursorPosition.X, startCursorPosition.Y+3);
		}
	}
}

void printRectangle(int x1, int y1, int x2, int y2, int selected) {
	int i, width = x2 - x1, height = y2 - y1;
	char *str;

	if(width >= 2) {
		str = malloc(sizeof(char)*width+1);

		str[0] = (selected) ? 201: 218;
		str[width-1] = (selected) ? 187 : 191;
		for(i = 1; i < width-1; ++i) {
			str[i] = (selected) ? 205 : 196;
		}

		str[width] = 0;
		gotoXY(x1, y1);
		printf("%s", str);

		for(i = 1; i < height; ++i) {
			gotoXY(x1, y1+i);
			putchar((selected) ? 186: 179);
			gotoXY(x2-1, y1+i);
			putchar((selected) ? 186: 179);
		}

		str[0] = (selected) ? 200: 192;
		str[width-1] = (selected) ? 188 : 217;
		for(i = 1; i < width-1; ++i) {
			str[i] = (selected) ? 205 : 196;
		}

		gotoXY(x1, y2);
		printf("%s", str);

		free(str);
	}
}

void printHorizontalDivision() {
	int i;

	for(i = 0; i < CONSOLE_WIDTH; ++i) {
		putchar('-');
	}
	printf("\n");
}

void freeButton(Button *button) {
	if(button->position)
		free(button->position);
	free(button);
}

//- CONSOLE -//

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

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return columns;
}

//- UI ELEMENT -//

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
			UIElementToPageHeader(elem)->selected = selected;
			break;
		case ButtonElem:
			UIElementToButton(elem)->selected = selected;
			break;
		default: break;
	}
}

void freeUIElem(UIElement *elem) {
	switch(elem->type) {
		case PageHeaderElem:
			freePageHeader(UIElementToPageHeader(elem));
			break;
		case ButtonElem:
			freeButton(UIElementToButton(elem));
			break;
		default: break;
	}
}