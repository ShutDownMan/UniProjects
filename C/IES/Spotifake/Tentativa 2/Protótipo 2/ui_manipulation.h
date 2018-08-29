#ifndef UI_MANIPULATION
#define UI_MANIPULATION

#define bool unsigned char

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80

#define E_KEY 101

#define RETURN_KEY 13

#define CONSOLE_WIDTH 65

#define NONE -1

typedef struct position {
	int x, y;
} Position;

typedef enum uiElementType {
	PageHeaderElem,
	ButtonElem
} UIElementType;

typedef struct uiElement {
	void *element;
	UIElementType type;
	struct uiElement *left, *up, *right, *down;
} UIElement;

typedef struct pageHeader {
	bool selected;
	unsigned int height;
	char *contextText, *appVersion;
} PageHeader;

typedef struct button {
	Position *position;
	bool selected, fixed, borders;
	char *text, alignment;
} Button;


Position *createPosition(int x, int y);

void setupConsole();

//- PAGEHEADER -//

PageHeader *createPageHeader(char *contextText, int height);

void printPageHeader(PageHeader *pageHeader);

//- BUTTON -//

Button *createButton(char *text);

void printButton(Button *button);

char *printHorizontalLimit(int textSize, int selected);

void printHorizontalDivision();

//- CONSOLE -//

void gotoXY(int x, int y);

COORD getCursorPosition();

//- UIELEMENT -//

UIElement *createUIElem(void *element, UIElementType type);

PageHeader *UIElementToPageHeader(UIElement *elem);

Button *UIElementToButton(UIElement *elem);

void setSelectedUIElem(UIElement *elem, bool selected);

#endif // UI_MANIPULATION