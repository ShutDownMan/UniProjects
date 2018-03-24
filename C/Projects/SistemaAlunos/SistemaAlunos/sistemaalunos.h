#ifndef SISTEMAALUNOS_H
#define SISTEMAALUNOS_H

typedef struct Student {
    int ID;
    char *name;
    char *course;
} Student;

typedef struct Node {
    Student *student;
    struct Node *next;
} Node;

typedef struct List {
    int length;
    Node *head;
    Node *tail;
} List;

// CRUD //

void createForm(List *list);

Student *readStudent();

int insert(List *list, Student *stdnt);

Node *insertNode(Node *node, Student *stdnt);

Node *createNode(Student *stdnt);

// SEARCH FUNCTIONS //

void search(List *list);

void printList(List *list);

void printStudent(Student *stdnt);

Student *searchID(List *list);

Student *findFromID(List *list, int id);

Student *searchName(List *list);

Student *findFromName(List *list, char name[]);

List *searchCourse(List *list);

List *findFromCourse(List *list, char course[]);

// UPDATE FUNCTIONS //

void update(List *list);

char updateMenu();

int isValidUpdate(char c);

void showHelpUpdate();

Student *findStudent(List *list);

void updateID(Student *stdnt);

void updateName(Student *stdnt);

void updateCourse(Student *stdnt);

// HELPER FUNCIONS //

char mainMenu();

int isValidMain(char c);

void showHelpMain();

char searchMenu();

int isValidSearch(char c);

void showHelpSearch();

void printList(List *list);

int isValidString(char name[]);

void cls();

void confirm();

int isEmpty(Node *node);

List *createList();

void freeList(List *list);

void freeNodes(Node *node);

#endif // SISTEMAALUNOS_H
