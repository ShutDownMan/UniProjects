#ifndef UIELEM_H
#define UIELEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define EXIT_KEY 101

#define RETURN_KEY 13

#define CONSOLE_WIDTH 77

typedef struct position {
	int x, y;
} Position;

typedef struct button {
	int x, y, selected;
	char *text;
} Button;


Position *createPosition(int x, int y);

void setupConsole();

Button *createButton(char *text);

void printButton(Button *button);

char *printHorizontalLimit(int textSize, int selected);

void printHorizontalDivision();

void gotoXY(int x, int y);


#endif // UIELEM_H