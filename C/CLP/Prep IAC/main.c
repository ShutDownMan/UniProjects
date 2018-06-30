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


int main(int argc, char const *argv[]) {

//	convertBin();

//	getIntPointers();

//	getDoublePointers();

//	getStrLen();

	getFirstOcc();

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
		findFirstOcc(str);
	}
}

char *findFirstOcc(char c, char str[]) {

	return NULL;
}