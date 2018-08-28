#include "ui_manipulation.h"

void setupConsole() {
	HANDLE hOut;
	COORD consoleSize;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	SetConsoleTitle("UI");

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;

	// Create a COORD to hold the buffer size:
	COORD bufferSize = {100, 100};

	// Change the internal buffer size:
	SetConsoleScreenBufferSize(hOut, bufferSize);

	/// Change windows font size
    CONSOLE_FONT_INFOEX font; //CONSOLE_FONT_INFOEX is defined in some windows header
    GetCurrentConsoleFontEx(hOut, TRUE, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
//    printf("%d And %d\n", font.dwFontSize.X, font.dwFontSize.Y);
    font.dwFontSize.X = 500;
    font.dwFontSize.Y = 10;
    SetCurrentConsoleFontEx(hOut, TRUE, &font);
//    printf("%d And %d\n", font.dwFontSize.X, font.dwFontSize.Y);
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

Canvas *setupCanvas(int height, int width) {
	Canvas *newCanvas = malloc(sizeof(Canvas));

	newCanvas->sprites = createDinamicArray();
	newCanvas->screen = malloc(sizeof(char)*height*width);
	newCanvas->height = height;
	newCanvas->width = width;

	return newCanvas;
}

void gotoXY(int x, int y) {
	HANDLE han;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	han = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(han, pos);
}

Position *createPosition(int x, int y) {
	Position *newPosition = malloc(sizeof(Position));

	newPosition->x = x;
	newPosition->y = y;

	return newPosition;
}

Sprite *readSprite(char *fileName) {
	Sprite *newSprite = malloc(sizeof(Sprite));
	FILE *f;
	char str[STRMAX];
	int i, alocSize = 1, width;
	newSprite->m_sprite = malloc(sizeof(char*)*alocSize);

	if(f = fopen(fileName, "r+")) {
		for(i = 0; !feof(f); ++i) {
			fscanf(f, "%[^\n]%*c", str);
			if(i+1 > alocSize) {
				alocSize *= 2;
				newSprite->m_sprite = realloc(newSprite->m_sprite, sizeof(char*)*alocSize);
			}
			newSprite->m_sprite[i] = strcpy(malloc(sizeof(char)*(strlen(str)+1)), str);
		}
		alocSize = i;
		newSprite->m_sprite = realloc(newSprite->m_sprite, sizeof(char*)*alocSize);
	}

	newSprite->height = alocSize;

	return newSprite;
}

char *generateDifferenceScreen(Canvas *canvas) {
	char *newScreen = malloc(sizeof(char)*canvas->height*canvas->width);
	Sprite *currentSprite;
	int i, row, col;

	for(i = 0; i < canvas->sprites->size; ++i) {
		currentSprite = canvas->sprites->m_array[i];
		if(currentSprite) {
			printOnCanvas(canvas, sprite);
		}
	}

	for(row = 0; row < canvas->height; ++row) {
		for(col = 0; col < canvas->width; ++col) {
			
		}
	}
}

void printOnCanvas(Canvas *canvas, Sprite *sprite) {

}