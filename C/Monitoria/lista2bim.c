#include <stdio.h>

/// 1.
void makeNum() {
	int num, res, multiplier;

	res = 0;
	multiplier = 1;

	scanf("%d", &num);
	while(num != -1) {
		res += num * multiplier;
		multiplier *= 10;

		scanf("%d", &num);
	}

	printf("%d\n", res);
}

/// 2.
void makeNum2() {
	int num, res;

	res = 0;

	scanf("%d", &num);
	while(num != -1) {
		res *= 10;
		res += num;

		scanf("%d", &num);
	}

	printf("%d\n", res);
}

/// 3.
void calcDigitSum() {
	int sum, num;

	scanf("%d", &num);
	while(num != -1) {
		for(sum = 0; num; num /= 10) {
			sum += num%10;
		}

		printf("%d\n", sum);
		scanf("%d", &num);
	}
}

/// 4.
void printLine(int length, char c);
void drawLeftTriang() {
	int i, lines;
	char c;

	scanf("%d %c", &lines, &c);
	while(lines != -1) {
		for(i = 0; i < lines; ++i) {
			printLine(i+1, c);
			printf("\n");
		}

		scanf("%d %c", &lines, &c);
	}
}

void printLine(int length, char c) {
	int i;
	for (i = 0; i < length; ++i) {
		printf("%c", c);
	}
}

/// 5.
void drawInvertedLeftTriang() {
	int i, lines;
	char c;

	scanf("%d %c", &lines, &c);
	while(lines != -1) {
		for(i = 0; i < lines; ++i) {
			printLine(lines-i, c);
			printf("\n");
		}

		scanf("%d %c", &lines, &c);
	}
}

/// 6.
void drawEquiTriang() {
	int i, lines;
	char c;

	scanf("%d %c", &lines, &c);
	while(lines != -1) {
		for(i = 1; i <= lines; ++i) {
			printLine(lines-i, ' ');
			printLine(2*i - 1, c);
			printf("\n");
		}

		scanf("%d %c", &lines, &c);
	}
}

/// 7.
void drawInvertedEquiTriang() {
	int i, lines;
	char c;

	scanf("%d %c", &lines, &c);
	while(lines != -1) {
		for(i = 1; i <= lines; ++i) {
			printLine(i-1, ' ');
			printLine((lines-i)*2 + 1, c);
			printf("\n");
		}

		scanf("%d %c", &lines, &c);
	}
}

/// 8.
void drawSquare() {
	int i, j, dimension;
	char c;

	scanf("%d %c", &dimension, &c);
	while(dimension != -1) {

		for(i = 0; i < dimension; ++i) {
			printf("%c", c);
		}
		printf("\n");

		for(i = 0; i < dimension-2; ++i) {
			printf("%c", c);
			for(j = 0; j < dimension-2; ++j) {
				printf(" ");
			}
			printf("%c\n", c);
		}

		for(i = 0; i < dimension; ++i) {
			printf("%c", c);
		}
		printf("\n");

		scanf("%d %c", &dimension, &c);
	}
}

/// 9.
void printASCII() {
	int i, qnt;
	char c;

	scanf("%d %c", &qnt, &c);
	while(qnt != -1) {

		for(i = 0; i < qnt; ++i) {
			printf("%c", c+i);
		}
		printf("\n");

		scanf("%d %c", &qnt, &c);
	}
}

int main(int argc, char const *argv[]) {

	/// 1.
//	makeNum();

	/// 2.
//	makeNum2();

	/// 3.
//	calcDigitSum();

	/// 4.
//	drawLeftTriang();

	/// 5.
//	drawInvertedLeftTriang();

	/// 6.
//	drawEquiTriang();

	/// 7.
//	drawInvertedEquiTriang();

	/// 8.
//	drawSquare();

	/// 9.
//	printASCII();

	return 0;
}