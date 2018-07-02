#include <stdio.h>

#define BYTE_SIZE 8

void convertBin();

void showBin(int x);

void printBinVet(int binVet[]);

int getOnBitSum(int binVet[]);

void getIntPointers();

void showIntPointers(int x);

void getDoublePointers();

void showDoublePointers(double x);

void getStrLen();

int showStrLen(char str[]);

void getFirstOcc();

char *findFirstOcc(char c, char str[]);

void getDigitSum();

int sumDigit(int num);

void getMinDigitSum();

void getSuperNext();

int superNext(int num);

void getOddNSum();

void showOddNSum(int num);

void getOddEvenQnt();

void oddEvenQnt(int num, int *total, int *oddQnt);

void getHighestTwo();

int main(int argc, char const *argv[]) {
	/// 1.
//	convertBin();

	/// 2.
//	getIntPointers();

	/// 3.
//	getDoublePointers();

	/// 4.
//	getStrLen();

	/// 5.
//	getFirstOcc();

	/// 6.
//	getDigitSum();

	/// 7.
//	getMinDigitSum();

	/// 8.
//	getSuperNext();

	/// 9.
//	getOddNSum();

	/// 11.
//	getOddEvenQnt();

	/// 12.
	getHighestTwo();

	return 0;
}

void convertBin() {
	int cdt, x;

	scanf("%d", &x);
	while(x != -1) {
		showBin(x);
		scanf("%d", &x);
	}
}

void showBin(int x) {
	int i;
	int binVet[32] = {0};

	for(i = 31; i && x; --i, x >>= 1) {
		binVet[i] = x & 1;
	}

	printBinVet(binVet);
}

void printBinVet(int binVet[]) {
	int i, j, index;

	for(i = 0; i < sizeof(int)*2; ++i) {
		for(j = 0; j < 4; ++j) {
			index = i*4 + j;

			printf("%d", binVet[index]);
		}
		printf(" ");
	}
	printf("= [%d]\n", getOnBitSum(binVet));
}

int getOnBitSum(int binVet[]) {
	int i, sum;

	for(i = sum = 0; i < 32; ++i) {
		sum += binVet[i];
	}

	return sum;
}

void getIntPointers() {
	int cdt, x;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &x);
		showIntPointers(x);
	}
}

void showIntPointers(int x) {
	int i;
	unsigned char *ptr;

	for(i = 0; i < sizeof(int); ++i) {
		ptr = ((char*)&x) + i;
		printf("[%p] = %02x\n", ptr, *ptr);
	}
	printf("\n");
}

void getDoublePointers() {
	int cdt;
	double x;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%lf", &x);
		showDoublePointers(x);
	}
}

void showDoublePointers(double x) {
	int i;
	unsigned char *ptr;

	for(i = 0; i < sizeof(double); ++i) {
		ptr = ((char*)&x) + i;
		printf("[%p] = %02x\n", ptr, *ptr);
	}
	printf("\n");
}

void getStrLen() {
	int cdt;
	char str[256];

	scanf("%d", &cdt);
	while(cdt--) {
		scanf(" %[^\n]%*c", str);
		showStrLen(str);
	}
}

int showStrLen(char str[]) {
	int i;

	for(i = 0; str[i]; i++)
		;

	printf("strLen(\"%s\") = %d\n", str, i);
}

void getFirstOcc() {
	int cdt;
	char str[256];

	scanf("%d", &cdt);
	while(cdt--) {
		scanf(" %[^\n]%*c", str);
		printf("('a') => %s\n", findFirstOcc('a', str));
	}
}

char *findFirstOcc(char c, char str[]) {
	int i;

	for(i = 0; str[i]; ++i) {
		if(str[i] == c) {
			return str + i;
		}
	}

	return NULL;
}

void getDigitSum() {
	int num;

	scanf("%d", &num);
	while(num != -1) {
		printf("sum(%d) = %d\n", num, sumDigit(num));
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

void getMinDigitSum() {
	int num, minSum;

	scanf("%d", &num);
	while(num != -1) {
		minSum = num;
		while(minSum >= 10) {
			minSum = sumDigit(minSum);
		}
		printf("minSum(%d) = %d\n", num, minSum);
		scanf("%d", &num);
	}
}

void getSuperNext() {
	int num;

	scanf("%d", &num);
	while(num != -1) {
		printf("superNext(%d) = %d\n", num, superNext(num));
		scanf("%d", &num);
	}
}

int superNext(int num) {
	int multiplier, resNum;

	multiplier = 1;
	for(resNum = 0; num; num /= 10) {
		resNum += ((num%10 + 1)%10) * multiplier;
		multiplier *= 10;
	}

	return resNum;
}

void getOddNSum() {
	int cdt, num;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &num);
		showOddNSum(num);
	}
}

void showOddNSum(int num) {
	int i, sum;
	int rNum = num*num*num;

	sum = 0;
	for(i = 1; sum < rNum; i += 2) {
		if(i/2 >= num) {
			sum -= i - num*2;
		}
		sum += i;
	}

	i -= 2*num;

	printf("%d^3 = ", num);
	while(num--) {
		printf("%d%s", i, (num) ? " + " : "\n");
		i += 2;
	}
}

void getOddEvenQnt() {
	int cdt, total, odds, num;

	total = odds = 0;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &num);
		oddEvenQnt(num, &total, &odds);
	}

	printf("#pares = %d\n", total-odds);
	printf("#impares = %d\n", odds);
}

void oddEvenQnt(int num, int *total, int *oddQnt) {
	for(; num; num /= 10) {
		(*oddQnt) += ((num%10)%2);
		(*total)++;
	}
}

void getHighestTwo() {
	int cdt, num;
	int high, secHigh;

	high = secHigh = 0;

	scanf("%d", &cdt);
	while(cdt--) {
		scanf("%d", &num);
		if(num > secHigh) {
			if(num > high) {
				secHigh = high;
				high = num;
			} else {
				secHigh = num;
			}
		}
	}

	printf("Primeiro maior = %d\n", high);
	printf("Segundo maior = %d\n", secHigh);
}
