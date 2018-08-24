#include "ui_manipulation.h"

void setupConsole() {
	HANDLE hOut;
	COORD consoleSize;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	SetConsoleTitle("Dinosaaur");

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

void gotoXY(int x, int y) {
	HANDLE han;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	han = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(han, pos);
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

void printSprite(Sprite *sprite, int x, int y) {
	int row;

	for(row = 0; row < sprite->height; ++row) {
		gotoXY(x, y+row);
		if(x < 0) {
			if(fabs(x) < strlen(sprite->m_sprite[row])) {
				printf("%s", sprite->m_sprite[row]-x);
			}
		} else {
			printf("%s", sprite->m_sprite[row]);
		}
	}
}