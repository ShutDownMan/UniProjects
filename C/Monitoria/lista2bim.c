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

	for(scanf("%d", &num); (num != -1); scanf("%d", &num)) {
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

/// 10.
void printASCIIFromTo() {
	int i, qnt, dir;
	char from, to;

	scanf(" %c %c ", &from, &to);
	while(from != '/' || to != '/') {
		dir = (to-from > 0) ? 1 : -1;
		qnt = (to-from)*dir;
		printf("[%c][%c]\n", from, to);
		for(i = 0; i <= qnt; ++i) {
			printf("%c", from + i*dir);
		}
		printf("\n");

		scanf(" %c %c ", &from, &to);
	}
}

/// 11.
void encripify() {
	int num, invNum;

	scanf("%d", &num);
	while(num != -1) {
		for(invNum = 0; num; num /= 10) {
			invNum *= 10;
			invNum += (num%10);
		}
		for(; invNum; invNum /= 10) {
			printf("%c", (invNum%10)+'A');
		}
		printf("\n");

		scanf("%d", &num);
	}
}

/// 12.
void calcFib() {
	int i, n;
	int first, second, next;

	scanf("%d", &n);
	while(n != -1) {
		first = second = 1;

		if(n--) printf("%d ", first);
		if(n--) printf("%d ", second);

		for(i = 0; i < n; ++i) {
			next = first + second;
			second = first;
			first = next;

			printf("%d ", first);
		}
		printf("\n");

		scanf("%d", &n);
	}
}

/// 13.
int sumDigit(int num);
void getMinDigitSum() {
	int num, minSum;

	scanf("%d", &num);
	while(num != -1) {
		minSum = num;

		while(minSum >= 10) {
			minSum = sumDigit(minSum);
		}
		printf("%d\n", minSum);

		scanf("%d", &num);
	}
}

int sumDigit(int num) {
	int sum;

	for(sum = 0; num; num /= 10) {
		sum += num%10;
	}

	return sum;
}

/// 14.
void checkPrime() {
	int i, num, isPrime;

	scanf("%d", &num);
	while(num != -1) {

		isPrime = 1;
		for(i = 2; i < num && isPrime; ++i) {
			isPrime = (num%i);
		}

		printf("%d\n", isPrime);
		scanf("%d", &num);
	}
}

/// 15.
int isPrimeNum();
void getPrimeSum() {
	int i, num, sum;

	scanf("%d", &num);
	while(num != -1) {

		sum = 0;
		for(i = 3; i < num ; ++i) {
			if(isPrimeNum(i))
				sum += i;
		}

		printf("%d\n", sum);
		scanf("%d", &num);
	}
}

int isPrimeNum(int num) {
	int i, isPrime;

	isPrime = 1;
	for(i = 2; i < num && isPrime; ++i) {
		isPrime = (num%i);
	}

	return isPrime;
}

/// 23.
void getOddNSum() {
	int i, num, start;

	scanf("%d", &num);
	while(num != -1) {

		start = (num-1)*(num-2) + 1;

		printf("%d^3 = ", num);
		for(i = 0; i < num; ++i) {
			printf("%d", start + 2*i);
			if(i < num-1)
				printf(" + ");
		}
		printf("\n");

		scanf("%d", &num);
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

	/// 10.
//	printASCIIFromTo();

	/// 11.
//	encripify();

	/// 12.
//	calcFib();

	/// 13.
//	getMinDigitSum();

	/// 14.
//	checkPrime();

	/// 15.
	getPrimeSum();


	/// 23.
//	getOddNSum();

	return 0;
}