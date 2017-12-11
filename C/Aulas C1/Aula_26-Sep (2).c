#include <stdio.h>
#include <string.h>

#define MAX 100

void alquant(char str[]) {
	int i, letterquant[MAX] = {0};

	for (i = 0; str[i]; ++i) {
		letterquant[str[i] - 'A']++;
	}

	printf("_______________\n");
	for (i = 'A'; i < 'Z'; ++i) {
		printf("#%c = %d\n", i, letterquant[i - 'A']);
	}

}

int main(int argc, char const *argv[]) {
	char str[MAX];

	gets(str);
	while(strcmp(str, "exit")) {
		alquant(str);

		gets(str);
	}

	return 0;
}