#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAXROW 64
#define MAXCOL 64
#define MAX 256

#define SCREEN_SIZE 12

#define OFFSET_X 1
#define OFFSET_Y 1

typedef enum {
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd'
} Direction;

typedef enum {
	HEAD_UP = '^',
	HEAD_DOWN = 'v',
	HEAD_LEFT = '<',
	HEAD_RIGHT = '>',
	BODY = 254, // ■
	FOOD = 233,  // Θ
} Symbols;

typedef struct Node {
	int x, y;
} Node;

typedef struct Snake {
	int size;
	Node direction;
	Node nodes[MAX];

	int lives, delayToGrow, timesToGrow;
} Snake;

typedef struct Food {
	int timeToDecay;
	Node position;
} Food;

typedef struct Game {
	Snake snake;
	Food food;
	int score;
} Game;

void startupSequence(Game* game, int screen[][MAXCOL], int width, int height);
void drawScreen(Game* game, int screen[][MAXCOL], int width, int height);
void moveSnake(Game* game, int screen[][MAXCOL], int width, int height);
void printScreen(FILE* f, int screen[][MAXCOL], int width, int height);
void onUpdate(Game game, int screen[][MAXCOL], int width, int height);
void clearScreen(int screen[][MAXCOL], int width, int height);
int  touchSnake(Snake snake, int x, int y, int start);
void changeDirection(char c, Snake* snake);
char getHeadDirection(Snake snake);
void relocateFood(Game* game);
void setupGrow(Snake* snake);
void debugVars(Game* game);
void gotoXY(int x, int y);
int  gameOver(Game game);
void grow(Snake* snake);
Snake createSnake(void);
time_t time(time_t *t);
void setupConsoleUI();

int main(int argc, char const *argv[]) {
	time_t t;
	int screen[MAXROW][MAXCOL];
	Game game;
	
	srand((unsigned) time(&t));

	setupConsoleUI();

	startupSequence(&game, screen, SCREEN_SIZE, SCREEN_SIZE);
	
	onUpdate(game, screen, SCREEN_SIZE, SCREEN_SIZE);

	system("pause");

	return 0;
}

void setupConsoleUI() {

	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitle(TEXT("SNAAAAAAAAAAAAAAAAKE"));

	// Set up the required window size:
	SMALL_RECT windowSize = {0, 0, 26, 14};
	
	// Change the console window size:
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	// Create a COORD to hold the buffer size:
	COORD bufferSize = {27, 15};

	// Change the internal buffer size:
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void printScreen(FILE* f, int screen[][MAXCOL], int width, int height) {
	int i, j;
	char c;
	//Symbols sym;

	gotoXY(0, 0);
	putc(218, f); // ┌

	for (i = 0; i < width; ++i) {
		fprintf(f, "%c%c", 196, 196); // ──
	}
	fprintf(f, "%c%c\n", 196, 191); // ─┐

	for (i = 0; i < height; ++i) {

		putc(179, f); // │

		for (j = 0; j < width; ++j) {
			c = screen[i][j];

			fprintf(f, " %c", c);
		}
		fprintf(f, " %c\n", 179); // │
	}

	putc(192, f); // └

	for (i = 0; i < width; ++i) {
		fprintf(f, "%c%c", 196, 196); // ──
	}
	fprintf(f, "%c%c\n", 196, 217); // ─┘
}


Snake createSnake(void) {
	int i;
	Snake newSnake;

	newSnake.size = 4;
	newSnake.direction.x = 1;
	newSnake.direction.y = 0;
	for (i = 0; i < 4; ++i) {
		newSnake.nodes[i].x = newSnake.size - i;
		newSnake.nodes[i].y = 0;
	}

	newSnake.lives = 3;
	newSnake.timesToGrow = 0;
	newSnake.delayToGrow = 4;

	return newSnake;
}

Food spawnFood(void) {
	Food newFood = {15, {rand() % SCREEN_SIZE, rand() % SCREEN_SIZE}};

	return newFood;
}

void clearScreen(int screen[][MAXCOL], int width, int height) {
	int i, j;

	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			if(screen[i][j]) {
				gotoXY(OFFSET_X + j*2, OFFSET_Y + i);
				printf(" ");
			}
			screen[i][j] = 0;
		}
	}
}

void startupSequence(Game* game, int screen[][MAXCOL], int width, int height) {
	int i;

	printf("Press any key to start the game...\n");
	if(getch()) {
		printf("Game starts in");

		for (i = 3; i > 0; --i) {
			printf(" %d..", i);
			Sleep(1000);
		}
		printf("\n");

		game->snake = createSnake();

		game->food = spawnFood();

		system("cls");
		clearScreen(screen, width, height);
		drawScreen(game, screen, SCREEN_SIZE, SCREEN_SIZE);
		printScreen(stdout, screen, SCREEN_SIZE, SCREEN_SIZE);
	}
}

char getHeadDirection(Snake snake) {
	char headDir;
	Symbols sym;

	if(snake.direction.x)
		if(snake.direction.x > 0) headDir = HEAD_RIGHT; else
			headDir = HEAD_LEFT;
	if(snake.direction.y)
		if(snake.direction.y > 0) headDir = HEAD_DOWN; else
			headDir = HEAD_UP;

	return headDir;
}

void drawScreen(Game* game, int screen[][MAXCOL], int width, int height) {
	int i;
	char headDir;

	screen[game->food.position.y][game->food.position.x] = FOOD;

	headDir = getHeadDirection(game->snake);

	for (i = 1; i < game->snake.size; ++i) {
		screen[game->snake.nodes[i].y][game->snake.nodes[i].x] = BODY;
	}
	screen[game->snake.nodes[0].y][game->snake.nodes[0].x] = headDir;
}

void changeDirection(char c, Snake* snake) {
	Direction d;
	Node dir;

	switch(c) {
		case LEFT:
			dir.x = -1;
			dir.y = 0;
			break;
		case RIGHT:
			dir.x = 1;
			dir.y = 0;
			break;
		case UP:
			dir.x = 0;
			dir.y = -1;
			break;
		case DOWN:
			dir.x = 0;
			dir.y = 1;
			break;
	}

	if(snake->direction.x + dir.x && snake->direction.y + dir.y) {
		snake->direction.x = dir.x;
		snake->direction.y = dir.y;
	}
}

void relocateFood(Game* game) {
	game->food.position.x = rand() % SCREEN_SIZE;
	game->food.position.y = rand() % SCREEN_SIZE;

	while(touchSnake(game->snake, game->food.position.x, game->food.position.y, 0)) {
		game->food.position.x = rand() % SCREEN_SIZE;
		game->food.position.y = rand() % SCREEN_SIZE;
	}

	game->food.timeToDecay = 15;
}

void setupGrow(Snake* snake) {
	if(!snake->timesToGrow) {
		snake->delayToGrow = snake->size-1;
	}

	snake->timesToGrow++;
}

void grow(Snake* snake) {
	snake->timesToGrow--;

	if(snake->timesToGrow) {
		snake->delayToGrow = snake->size-1;
	}

	snake->size++;
}

void moveSnake(Game* game, int screen[][MAXCOL], int width, int height) {
	int i;
	int size = game->snake.size;
	Node* nodes = game->snake.nodes;
	Node direction = game->snake.direction;

	if(game->snake.timesToGrow > 0) {
		if(game->snake.delayToGrow == 0) {
			grow(&game->snake);
		} else {
			game->snake.delayToGrow--;
		}

	}

	for (i = game->snake.size; i > 0; --i) {
		game->snake.nodes[i].x = nodes[i-1].x;	
		game->snake.nodes[i].y = nodes[i-1].y;	
	}
	game->snake.nodes[0].x += direction.x;
	game->snake.nodes[0].y += direction.y;
	game->snake.nodes[0].x = (game->snake.nodes[0].x + width) % width;
	game->snake.nodes[0].y = (game->snake.nodes[0].y + height) % height;


	if(nodes[0].x == game->food.position.x && nodes[0].y == game->food.position.y) {
		setupGrow(&game->snake);
		relocateFood(game);
	}
}

int gameOver(Game game) {
	int i;

	if(touchSnake(game.snake, game.snake.nodes[0].x, game.snake.nodes[0].y, 3))
		return 1;
	return 0;
}

int touchSnake(Snake snake, int x, int y, int start) {
	int i;

	for (i = start; i < snake.size; ++i) {
		if(x == snake.nodes[i].x)
			if(y == snake.nodes[i].y)
				return 1;
	}
	return 0;
}

void onUpdate(Game game, int screen[][MAXCOL], int width, int height) {
	char c;

	while (1) {
		if(kbhit()) {
			c = getch();

			changeDirection(c, &(game.snake));
		}

		moveSnake(&game, screen, width, height);
		clearScreen(screen, SCREEN_SIZE, SCREEN_SIZE);
		drawScreen(&game, screen, SCREEN_SIZE, SCREEN_SIZE);
		printScreen(stdout, screen, SCREEN_SIZE, SCREEN_SIZE);
		//debugVars(&game);

		if(game.snake.size == SCREEN_SIZE*SCREEN_SIZE) return;
		if(gameOver(game)) return;

		Sleep(250);
	}
}

void gotoXY(int x, int y) {
	HANDLE han;
	COORD pos;

	//fflush(stdout);

	pos.X = x;
	pos.Y = y;

	han = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(han, pos);
}

void debugVars(Game* game) {
	printf("TTG = %2d\n", game->snake.timesToGrow);
	printf("DTG = %2d\n", game->snake.delayToGrow);
	printf("size = %2d\n", game->snake.size);

	printf("SP = %2d/%2d\n", game->snake.nodes[0].x, game->snake.nodes[0].y);
	printf("FP = %2d/%2d\n", game->food.position.x, game->food.position.y);
}