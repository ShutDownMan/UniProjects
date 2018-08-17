#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim(char str[]) {
	int i;
	for(i = strlen(str)-1; i >= 0 && isspace(str[i]); --i)
		;
	str[i+1] = '\0';
}

int main(void) {
	int i, year;
	const char *genre;
	char title[256], author[256];
	FILE *f = fopen("100worst.txt", "r+");
	const char *genres[7] = {"Rock", "Rap", "EDM", "Classical", "Hip hop", "Pop", "Reggae"};

	for(i = 0; !feof(f); ++i) {
		fscanf(f, " %*d - %[^;];%[^;]; %d ", title, author, &year);
		trim(title);
		genre = genres[rand() % 7];
		printf("%-s;%-s;%-s;%d;%-s;%d;%d;\n", title, " UNSPECIFIED", author, year, genre, rand() & 250, rand() % 5 + 1);
	}

	return 0;
}