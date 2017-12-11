#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

#define LINESIZE 1024

void openFile();

void writeLine();

char menu();

void scanNWrite();

void readNPrint();

FILE *DB;

int main(int argc, char const *argv[]) {
	char choice;

	openFile();

	while(1) {
		choice = menu();

		switch(choice) {
			case 'w': scanNWrite();
			break;

			case 'r': readNPrint();
			break;

			case 'e': return 0;
			break;

			default: fputs("Not a valid command\n", stdout);
			break;
		}
	}

	return 0;
}

void openFile() {
	DB = fopen("./text_file.txt", "w+");

	if(DB == NULL) {
		fprintf(stdout, "Error opening DB file\n");
	}
}

void writeLine(char line[]) {
	fprintf(DB, "%s", line);
}

void scanNWrite() {
	char line[LINESIZE];

	fputs("Enter a line of text\n", stdout);

	fgets(line, LINESIZE, stdin);

	writeLine(line);
}

void readNPrint() {
	char line[LINESIZE];

	fputs("Reading file:\n", stdout);

	rewind(DB);
	while(fgets(line, LINESIZE, DB) != NULL) {
		fputs(line, stdout);
	}
}

char menu() {
	char choice;

	fputs("(W)rite to file\n", stdout);
	fputs("(R)ead file\n", stdout);
	fputs("(E)xit\n", stdout);

	do {
		if(fscanf(stdin, "%c ", &choice) == EOF) break;

	} while(!strchr("wre", tolower(choice)));

	return tolower(choice);
}