#include <stdio.h>
#include <stdlib.h> // Manipulação de arquivos
#include <ctype.h> // "toupper"
#include <conio.h> // "getch"

#define MAXROW 8 // Tamanho máximo de linhas
#define MAXCOL 8 // Tamanho máximo de Colunas

// Pra simplificar na passagem de parametros
typedef struct Game {
	int screen[MAXROW][MAXCOL];
	int campoResposta[MAXROW][MAXCOL];

	// Pode-se adicionar mais

} Game;

void lerCampo(char fileName[], int campo[][MAXCOL]);
void startupSequence(Game* game);
char menu();
int main();

char menu() {
	int c;

	printf("Campo Minado");

	printf("\n\n1- Iniciar Game;\n2- Instrucoes;\n3- Sair;\n");

	fflush(stdin);
	scanf("%d", &c);
	while(c < 0 || c > 3) {
		printf("Digite uma entrada valida.\n");
		fflush(stdin);
		scanf("%d", &c);
	}

	return c;
}

void lerCampo(char fileName[], int campo[][MAXCOL]) {
	FILE *arq;
	int i, j;

	arq = fopen(fileName, "r");

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			fscanf(arq, "%d", &campo[i][j]);
		}
	}

	fclose(arq);
}

void printarCampo(int campo[][MAXCOL]) {
	int i, j;
	char c;

	system("cls");

	fprintf(stdout, "  %c", 218);

	for (i = 0; i < MAXCOL; ++i) {
		fprintf(stdout, "%c%c", 196, 'A'+i);
	}
	fprintf(stdout, "%c%c\n", 196, 191);

	for (i = 0; i < MAXROW; ++i) {

		fprintf(stdout, "%2d%c", i+1, 179);

		for (j = 0; j < MAXCOL; ++j) {
			fprintf(stdout, " %c", campo[i][j]);
		}
		fprintf(stdout, " %c%-2d\n", 179, i+1);
	}

	fprintf(stdout, "  %c", 192);

	for (i = 0; i < MAXCOL; ++i) {
		fprintf(stdout, "%c%c", 196, 'A'+i);
	}
	fprintf(stdout, "%c%c\n", 196, 217);
}

void calcCampo(int campo[][MAXCOL]) {
	int i, j, x, y;

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {

			if(campo[i][j] != -1) {
				
				campo[i][j] = 0;
				for (x = j-1; x <= j+1; ++x) {
					for (y = i-1; y <= i+1; ++y) {

						if(x >= 0 && x < MAXCOL && y >= 0 && y < MAXROW) {
							if(campo[y][x] == -1) campo[i][j]++;
						}
					}
				}
			}
		}
	}
}

void clearScreen(int screen[][MAXCOL]) {
	int i, j;

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			screen[i][j] = 254;
		}
	}
}

void startupSequence(Game* game) {

	lerCampo("campo.txt", game->campoResposta);
	clearScreen(game->screen);
	printarCampo(game->campoResposta);

	calcCampo(game->campoResposta);

}

void getCoord(int* row, char* col) {

	fflush(stdin);
	scanf("%d%c", row, col);
	*row = toupper(*row);
	while(*row <= 0 || *row > MAXROW || *col < 'A' || *col > 'H') {
		printf("Erro: Entrada invalida\nEntre com dados validos: ");
		fflush(stdin);
		scanf("%d%c", row, col);

		*row = toupper(*row);
	}

}

void revelarVizinhos(Game* game, int row, int col) {
	int i, j;

	game->screen[row][col] = '0';
	for (i = row-1; i <= row+1; ++i) {
		for (j = col-1; j <= col+1; ++j) {
			if(i >= 0 && i < MAXROW && j >= 0 && j < MAXCOL) {
				if(game->campoResposta[i][j] == 0 && game->screen[i][j] != '0') revelarVizinhos(game, i, j);
				game->screen[i][j] = '0'+game->campoResposta[i][j];
			}
		}
	}
}

int checkWin(Game* game) {
	int i, j;

	for (i = 0; i < MAXROW; ++i) {
		for (j = 0; j < MAXCOL; ++j) {
			if(game->campoResposta[i][j] != -1) {
				if(game->screen[i][j] == 254) return 0;
			}
		}
	}

	return 1;
}

int faz_jogada(Game* game, int row, int col){

	if(game->campoResposta[row][col] == -1) return -1;

	game->screen[row][col] = '0'+game->campoResposta[row][col];

	if(game->campoResposta[row][col] == 0) revelarVizinhos(game, row, col);

	return checkWin(game);
}

void gameOn(Game* game) {
	printarCampo(game->screen);
	printf("PARABENS, FODA-SE\n");
	system("pause");
}

void onUpdate(Game* game) {
	int row, gameState;
	char col;

	gameState = 0;
	while(!gameState) {
		printarCampo(game->screen);	
		printf("Digite a coordenada a ser revelada: \n");
		getCoord(&row, &col);
		//printf("%d %d\n", row-1, col-'A');

		gameState = faz_jogada(game, row-1, col-'A');
	}

	if(gameState == -1) {
		//gameOver(game);
	} else {
		gameOn(game);
	}


	system("cls");
	//printf("Game state = %d\n", gameState);
	main();
	// volta pro menu
}

void instrucoes(){
	system("cls");
	printf("\nDepois eu escrevo");
	printf("\nPressione qualquer tecla para voltar ao Menu Principal\n");
	getch();
	system("cls");
	main();
}

int main() {
	char escolhaMenu;
	Game game;

	switch(escolhaMenu = menu()) {
		case 1:
			startupSequence(&game);

			onUpdate(&game);
			break;
		case 2: 
			instrucoes();
			break;

		default: break;
	}

}