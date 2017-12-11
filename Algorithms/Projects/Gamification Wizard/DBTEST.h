#ifndef DBTEST_H_	/* Include guard */
#define DBTEST_H_
#define LINESIZE 1024
#define SDB_HEADER_OFFSET 66

#define StudentsDB 00
#define NotasDB 01

typedef struct {
	FILE *file;
	int entryNum;
} Database;

typedef struct {
	int index;
	char name[LINESIZE];
	char group[LINESIZE];
	int experience;
	int karma;
	int linePosition;
} Student;

Database studentsDB;
Database notasDB;
Student students[64];

char mainMenu();
char searchMenu();
char searchByIndex();
char searchByName();
char searchByGroup();

void trim();

void EditDBs();
void dbMenu();

void LoadEntries();
void LoadStudentsDB();

void SaveEntries();
void SaveStudentsDB();

void CreateEntry();

void ReadEntry();

void UpdateEntry();

void DeleteEntry();

void openFile();

void updStudentDBHeader();


#endif