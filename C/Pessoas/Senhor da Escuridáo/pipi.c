#include <stdio.h>

void multiNum() {
	int num,res=0,multi=1;

	scanf("%d",&num);
	while(num!=-1){
		res+=num*multi;
		multi*=10;
		scanf("%d", &num);
	}
	printf("%d\n", res);
}
void multiNumInv() {
	int res = 0,num;

	scanf("%d",&num);
	while(num != -1){
		res *= 10;
		res += num;
		scanf("%d", &num);
	}
	printf("%d\n", res);
}
int somaDigdin() {
	int res,num;

	scanf("%d",&num);
	while(num != -1){
		res = 0;
		while(num != 0){
			res += num % 10;
			num = num / 10;
		}
		printf("%d\n", res);
		scanf("%d",&num);
	}
}
void printLine(int n, char c) {
	int i;

	for (i = 0; i < n; ++i) {
		printf("%c", c);
	}
}
void numSei() {
	int i, num;
	char car;

	scanf("%d %c", &num, &car);
	while(num != -1) {
		for(i = 1; i <= num; ++i) {
			printLine(i, car);
			printf("\n");
		}

		scanf("%d %c", &num, &car);
	}
}
void numSeiInvAindaNaoSabendo() {
	int i, num;
	char car;

	scanf("%d %c", &num, &car);
	while(num != -1) {
		for(i = num; i >= 0; --i) {
			printLine(i, car);
			printf("\n");
		}

		scanf("%d %c", &num, &car);
	}
}
void escravoCriadorDePiramide() {
	int num, i;
	char car;

	scanf("%d %c", &num, &car);
	while(num != -1){
		for (i = 1; i <= num; ++i){
			printLine(num - i,' ');
			printLine(2*i - 1, car);
			printf("\n");

		}

		scanf("%d %c", &num, &car);
	}
}
void escravoCriadorDePiramideInv() {
	int num, i;
	char car;

	scanf("%d %c", &num, &car);
	while(num != -1){
		for (i = 1; i <= num; ++i){
			printLine(i - 1,' ');
			printLine((num-i)*2 + 1, car);
			printf("\n");

		}

		scanf("%d %c", &num, &car);
	}
}
void quadraticos() {
	int num, i;
	char car;

	scanf("%d %c", &num, &car);
	while(num != -1){
		printLine(num,car);
		printf("\n");
		for (i = 0; i < num-2; ++i){
			printf("%c", car);
			printLine(num - 2,'O');
			printf("%c",car);
			printf("\n");

		}
		printLine(num,car);
		printf("\n");
		scanf("%d %c", &num, &car);
	}
}

int main() {
	/// 1.
//	multiNum();

	/// 2.
//	multiNumInv();

	/// 3.
//	somaDigdin();

	/// 4.
//	numSei();

	/// 5.
//	numSeiInvAindaNaoSabendo();

	/// 6.
//	escravoCriadorDePiramide();

	/// 7.
//	escravoCriadorDePiramideInv();

	/// 8.
	quadraticos();

}
