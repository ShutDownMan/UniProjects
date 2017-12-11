#include <stdio.h>
#include <Windows.h>

#define MAXROW 128
#define MAXCOL 128

#define FOR_X for (int x = 0; x < ordem; x++)
#define FOR_Y for (int y = 0; y < ordem; y++)

int createEnv(int env[][MAXCOL], int* ordem) {
	int i, j;

	printf("Digite a ordem do campo: \n");
	scanf("%d", ordem);

	for (i = 0; i < *ordem; ++i) {
		for (j = 0; j < *ordem; ++j) {
			env[i][j] = 0;
		}
	}

}

int fprintEnv(FILE* f, int env[][MAXCOL], int ordem) {
	int i, j;

	for (i = 0; i < ordem; ++i) {
		for (j = 0; j < ordem; ++j) {
			fprintf(f, "%1d ", env[i][j]);
		}
		fprintf(f, "\n");
	}

	return 0;
}

void printarGraphics(FILE* f, int env[MAXROW][MAXCOL], int ordem) {
	int i, j;
	char c;

	fprintf(f, "%c", 218);

	for (i = 0; i < ordem; ++i) {
		fprintf(f, "%c%c", 196, 196); // ──
	}
	fprintf(f, "%c%c\n", 196, 191); // ─┐

	for (i = 0; i < ordem; ++i) {

		fprintf(f, "%c", 179); // │

		for (j = 0; j < ordem; ++j) {
			c = (env[i][j]) ? 254 : ' '; // ■

			fprintf(f, " %c", c);
		}
		fprintf(f, " %c\n", 179); // │
	}

	fprintf(f, "%c", 192); // └

	for (i = 0; i < ordem; ++i) {
		fprintf(f, "%c%c", 196, 196); // ──
	}
	fprintf(f, "%c%c\n", 196, 217); // ─┘
}

int fscanEnv(FILE* f, int env[][MAXCOL], int ordem) {
	int i, j;

	for (i = 0; i < ordem; ++i) {
		for (j = 0; j < ordem; ++j) {
			fscanf(f, "%d", &env[i][j]);
		}
	}

	return 0;
}

int iterateEnv(int env[][MAXCOL], int ordem) {
	int y1, x1;
	int n, newEnv[MAXROW][MAXCOL];

	FOR_Y FOR_X {
		n = 0;
		for (y1 = y - 1; y1 <= y + 1; y1++)
			for (x1 = x - 1; x1 <= x + 1; x1++)
				if (env[(y1 + ordem) % ordem][(x1 + ordem) % ordem])
					n++;
 
		if (env[y][x]) n--;
		newEnv[y][x] = (n == 3 || (n == 2 && env[y][x]));
	}
	FOR_Y FOR_X env[y][x] = newEnv[y][x];
}


int main(int argc, char const *argv[]) {
	FILE* fenv;
	int i;
	int env[MAXROW][MAXCOL], ordem;

	if(!(fenv = fopen("environment.txt", "r"))) return 1;

	createEnv(env, &ordem);
	fscanEnv(fenv, env, ordem);
	fprintEnv(stdout, env, ordem);

	for (i = 0; 1; ++i) {
		system("cls");

		//fprintEnv(stdout, env, ordem);
		printarGraphics(stdout, env, ordem);
		iterateEnv(env, ordem);

		Sleep(300);
	}



	return 0;
}