#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "DBTEST.h"

int main(int argc, char const *argv[]) {
	char choice;

	openFile();

	while(1) {
		choice = mainMenu();

		switch(choice) {

			case 'l': LoadEntries();
			break;

			case 's': SaveEntries();
			break;

			case 'e': EditDBs();
			break;

			case 'e': return 0;
			break;

			default: fputs("Not a valid command\n", stdout);
			break;
		}
	}

	return 0;
}

void EditDBs() {
	char choice;

	while(1) {
		choice = showDBsMenu();

		switch(choice) {
			case 'c': CreateEntry();
			break;

			case 'r': ReadEntry();
			break;

			case 'u': UpdateEntry();
			break;

			case 'd': DeleteEntry();
			break;

			case 'e': return 0;
			break;

			default: fputs("Not a valid command\n", stdout);
			break;
		}
	}	
}

void editDB(char dbIndex) {
	char choice;

	while(1) {
		choice = dbMenu();

		switch(choice) {
			case 'c': CreateEntry();
			break;

			case 'r': ReadEntry();
			break;

			case 'u': UpdateEntry();
			break;

			case 'd': DeleteEntry();
			break;

			case 'e': return 0;
			break;

			default: fputs("Not a valid command\n", stdout);
			break;
		}
	}
}

void LoadEntries() {
	printf("Loading from studentsDB...\n");
	LoadStudentsDB();
}

void LoadStudentsDB() {
	int i;
	char currentLine[LINESIZE];
	Student currentStudent;

	fseek(studentsDB.file, SDB_HEADER_OFFSET, SEEK_SET);

	i = 0;
	while(fgets(currentLine, LINESIZE, studentsDB.file) != NULL) {
		sscanf(currentLine, "%d \"%32c\" \"%32c\" %d %d", &currentStudent.index,
			currentStudent.name, currentStudent.group, &currentStudent.experience,
			&currentStudent.karma);
		currentStudent.linePosition = ftell(studentsDB.file) - 86;

		trim(currentStudent.name, 32);
		trim(currentStudent.group, 32);

		printf("Line stamp: %d\n", ftell(studentsDB.file)-86);
		printf("Index: %d\n", currentStudent.index);
		printf("Name: %s\n", currentStudent.name);
		printf("Group: %s\n", currentStudent.group);
		printf("Experience: %d\n", currentStudent.experience);
		printf("Karma: %d\n", currentStudent.karma);
		printf("------------------------------\n");

		students[i] = currentStudent;
		i++;
	}
}

void SaveEntries() {

}

void CreateEntry() {
	Student newStudent;
	char studentName[LINESIZE];
	char groupName[LINESIZE];

	fflush(studentsDB.file);
	printf("Enter student name: ");
	gets(studentName);
	fflush(studentsDB.file);
	printf("Enter group name: ");
	gets(groupName);

	//fseek(studentsDB.file, 0, SEEK_END);

	//newStudent.linePosition = ftell(studentsDB.file);
	newStudent.index = studentsDB.entryNum++;
	strcpy(newStudent.name, studentName);
	strcpy(newStudent.group, groupName);
	newStudent.experience = 0;
	newStudent.karma = 1000;

	//fprintf(studentsDB.file, "%04d \"%-32s\" \"%-32s\" %04d %04d\n", (studentsDB.entryNum++)+1, studentName, groupName, 0, 1000);
	//fprintf(stdout, "%04d \"%-32s\" \"%-32s\" %d %d\n", studentsDB.entryNum, studentName, groupName, 0, 1000);
	//updStudentDBHeader();
}

void ReadEntry() {
	char choice;

	while(1) {
		choice = searchMenu();

		switch(choice) {
			case 'i': searchByIndex();
			break;

			case 'n': searchByName();
			break;

			case 'g': searchByGroup();
			break;

			case 'e': return;
			break;

			default: fputs("Not a valid command\n", stdout);
			break;
		}
	}
}

char searchByIndex() {
	int indexToSearch;
	char currentLine[LINESIZE];

	fflush(stdin);
	printf("Index to search: ");
	fscanf(stdin, "%d", &indexToSearch);

	for(int i = 0; i < 100; ++i) {
		if (students[i].index == indexToSearch) {
			printf("Entry at position: %d\n", students[i].linePosition);
			break;
		} else if(&students[i] == NULL) {
			break;
		}
	}
}

char searchByName() {
	int hits;
	char nameToSearch[32];
	char currentLine[LINESIZE];

	fflush(stdin);
	printf("Name to search: ");
	gets(nameToSearch);
	printf("\nSearching for: %s\n", nameToSearch);

	hits = 1;
	for(int i = 0; i < 100; ++i) {
		if(strcmp(students[i].name, nameToSearch) == 0) {
			printf("Hit %d.:.\n", hits);
			printf("Entry at position: %d\n", students[i].linePosition);
			hits++;
		} else if(&students[i] == NULL) {
			break;
		}
	}
}

void trim(char text[], int textLength) {
	for (int i = textLength-1; i >= 0; --i) {
		if(text[i] != ' ' && i != textLength-1) {
			text[i+1] = '\0';
			break;
		}
	}
}

char searchByGroup() {

}

void UpdateEntry() {

}

void DeleteEntry() {

}

char mainMenu() {
	char choice;

	fputs("--------------\n", stdout);
	fputs("(L)oad entries\n", stdout);
	fputs("(S)ave entries\n", stdout);
	fputs("(E)dit databases\n", stdout);

	do {
		fflush(stdin);
		if(fscanf(stdin, "%c", &choice) == EOF) break;

	} while(!strchr("lse", tolower(choice)));

	return tolower(choice);

}

char showDBsMenu() {
	char choice;

	fputs("--------------\n", stdout);
	fputs("(S)tudents\n", stdout);
	fputs("(N)otas\n", stdout);
	fputs("(E)xit\n", stdout);

	do {
		fflush(stdin);
		if(fscanf(stdin, "%c", &choice) == EOF) break;

	} while(!strchr("sne", tolower(choice)));

	return tolower(choice);

}

char dbMenu() {
	char choice;

	fputs("--------------\n", stdout);
	fputs("(C)reate entry\n", stdout);
	fputs("(R)ead entry\n", stdout);
	fputs("(U)pdate entry\n", stdout);
	fputs("(D)elete entry\n", stdout);
	fputs("(E)xit\n", stdout);

	do {
		fflush(stdin);
		if(fscanf(stdin, "%c", &choice) == EOF) break;

	} while(!strchr("crude", tolower(choice)));

	return tolower(choice);
}

char searchMenu() {
	char choice;

	fputs("--------------\n", stdout);
	fputs("Search by:\n", stdout);
	fputs(" -(I)ndex\n", stdout);
	fputs(" -(N)ame\n", stdout);
	fputs(" -(G)roup\n", stdout);
	fputs(" -(E)xit\n", stdout);

	do {
		fflush(stdin);
		if(fscanf(stdin, "%c", &choice) == EOF) break;

		//printf("-%c", choice);

	} while(!strchr("inge", tolower(choice)));

	return tolower(choice);
}

void openFile() {
	studentsDB.file = fopen("./text_file.txt", "r+");

	if(studentsDB.file != NULL) {
		fscanf(studentsDB.file, "#entries:%d", &studentsDB.entryNum);
	} else {
		fprintf(stdout, "Error opening file\n");
	}
}

void updStudentDBHeader() {
	// Save file ptr position
	int posStamp = ftell(studentsDB.file);
	// Go to start of file
	rewind(studentsDB.file);
	// Overwrite header
	fprintf(studentsDB.file, "#entries:%04d", studentsDB.entryNum);
	// Restore file ptr position
	fseek(studentsDB.file, posStamp, SEEK_SET);
}