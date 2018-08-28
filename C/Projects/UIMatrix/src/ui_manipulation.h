#ifndef UI_MANIPULATION
#define UI_MANIPULATION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>

#include "dinamic_array.h"

#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define EXIT_KEY 101

#define RETURN_KEY 13

#define CONSOLE_WIDTH 77

#define STRMAX 256

typedef struct position {
	int x, y;
} Position;

typedef struct sprite {
	char **m_sprite;
	int height;
} Sprite;

typedef struct canvas {
	DinamicArray *sprites;
	char *screen;
	int height, width;
} Canvas;

typedef struct uiEntity {
	Position *position;
	Sprite *sprite;
} UIEntity;

void setupConsole();

Canvas *setupCanvas(int height, int width);

void gotoXY(int x, int y);

Position *createPosition(int x, int y);

Sprite *readSprite(char *fileName);

UIEntity *createUIEntity(Sprite *sprite, int x, int y);

char *generateDifferenceScreen(Canvas *canvas);

#endif // UI_MANIPULATION