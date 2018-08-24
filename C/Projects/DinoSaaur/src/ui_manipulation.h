#ifndef UI_MANIPULATION
#define UI_MANIPULATION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>

#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define EXIT_KEY 101

#define RETURN_KEY 13

#define CONSOLE_WIDTH 77

#define STRMAX 256

typedef struct sprite {
	char **m_sprite;
	int height;
} Sprite;

void setupConsole();

void gotoXY(int x, int y);

Sprite *readSprite(char *fileName);

void printSprite(Sprite *sprite, int x, int y);

#endif // UI_MANIPULATION