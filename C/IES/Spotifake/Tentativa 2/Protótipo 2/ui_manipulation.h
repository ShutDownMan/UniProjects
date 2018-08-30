#ifndef UI_MANIPULATION
#define UI_MANIPULATION

#define bool unsigned char

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "list.h"

#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80

#define E_KEY 101

#define RETURN_KEY 13

#define CONSOLE_WIDTH getConsoleWidth()

#define NONE -1

/// this struct contains simple x and y coordinates information
typedef struct position {
	int x, y;
} Position;

/// this enum contains all possible ui element types
typedef enum uiElementType {
	PageHeaderElem,
	ButtonElem
} UIElementType;

/// this struct contains an ui element attributes
typedef struct uiElement {
	void *element;
	UIElementType type;
	struct uiElement *left, *up, *right, *down;
	char hotkey;
} UIElement;

/// this struct contains attributes of a page header
typedef struct pageHeader {
	bool selected;
	unsigned int height;
	char *contextText, *appVersion;
} PageHeader;

/// this struct contains attributes of a button
typedef struct button {
	Position *position;
	bool selected, fixed, borders;
	char *text, alignment;
} Button;

typedef struct menuUI {
	List *uiElements;
	UIElement *selectedElement; //< selected element in UI
} MenuUI;

//- MENU UI -//

MenuUI *createMenuUI();

void menuUIArrowControl(MenuUI *menuUI, char charInput);

void freeMenuUI(MenuUI *menuUI);

//- INITIALIZE -//

Position *createPosition(int x, int y);

void setupConsole();

//- PAGEHEADER -//

PageHeader *createPageHeader(char *contextText, int height);

void printPageHeader(PageHeader *pageHeader);

void freePageHeader(PageHeader *pageHeader);

//- BUTTON -//

Button *createButton(char *text);

void printButton(Button *button);

void printRectangle(int x1, int y1, int x2, int y2, int selected);

void printHorizontalDivision();

void freeButton(Button *button);

//- CONSOLE -//

void gotoXY(int x, int y);

COORD getCursorPosition();

int getConsoleWidth();

//- UIELEMENT -//

UIElement *createUIElem(void *element, UIElementType type);

PageHeader *UIElementToPageHeader(UIElement *elem);

Button *UIElementToButton(UIElement *elem);

void setSelectedUIElem(UIElement *elem, bool selected);

void freeUIElem(UIElement *elem);

#endif // UI_MANIPULATION