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

void search(List *list);

void printList(List *list);

void printStudent(Student *stdnt);

void searchID(List *list);

Student *findFromID(List *list, int id);

void searchName(List *list);

Student *findFromName(List *list, char name[]);

void searchCourse(List *list);

List *findFromCourse(List *list, char course[]);

// HELPER FUNCIONS //

char mainMenu();

int isValidMain(char c);

void showHelpMain();

char searchMenu();

int isValidSearch(char c);

void showHelpSearch();

void printList(List *list);

int isValidName(char name[]);

void cls();

void confirm();

int isEmpty(Node *node);

List *createList();

void freeList(List *list);

void freeNodes(Node *node);

#endif // SISTEMAALUNOS_H
