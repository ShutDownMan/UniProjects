#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include <sistemaalunos.h>

#define MAX 64

int main(int argc, char *argv[]) {
    List students = {.length = 0, .head = NULL, .tail = NULL};
    char c;

    while(c = mainMenu()) {
        switch (c) {
        case '?':
            showHelpMain();
            break;
        case 'C':
            createForm(&students);
            break;
        case 'R':
            search(&students);
            break;
        default:
            return 0;
            break;
        }
        confirm();
    }

    return 0;
}

// CRUD //

void createForm(List *list) {
    Student *newStudent;

    if((newStudent = readStudent())) {
        newStudent->ID = list->length++;

        printf("\n>Student data sucessfully stored.\n");
        printf(">Adding student data to list.\n\n");

        if(insert(list, newStudent)) {
            printf(">Student entry sucessfully added to list.\n");
        } else {
            printf(">There was a problem adding entry to list.\n");
        }

    } else {
        printf(">There was a problem reading student data.\n");
    }

}

Student *readStudent() {
    Student *newStudent = malloc(sizeof(Student));
    char str[MAX];

    cls();
    printf(">Type in student data: \n");

    printf("Name: ");
    scanf("%[^\n]%*c", str);
    newStudent->name = strcpy(malloc(sizeof(strlen(str)+1)), str);
    printf("Course: ");
    scanf("%[^\n]%*c", str);
    newStudent->course = strcpy(malloc(sizeof(strlen(str)+1)), str);

    return newStudent;
}

int insert(List *list, Student *stdnt) {
    if(isEmpty(list->head)) {
        list->head = createNode(stdnt);
        return 1;
    }

    list->tail = createNode(stdnt);
    return (int)insertNode(list->head, stdnt);
}

Node *insertNode(Node *node, Student *stdnt) {
    if(isEmpty(node)) return NULL;

    if(node->next) {
        insertNode(node->next, stdnt);
        return node;
    }

    node->next = createNode(stdnt);

    return node;
}

Node *createNode(Student *stdnt) {
    Node *newNode = malloc(sizeof(Node));

    newNode->student = stdnt;
    newNode->next = NULL;

    return newNode;
}

void search(List *list) {
    char c;

    while((c = searchMenu())) {
        switch (c) {
        case '?':
            showHelpSearch();
            break;
        case 'L':
            printList(list);
            break;
        case 'I':
            searchID(list);
            break;
        case 'N':
            searchName(list);
            break;
        case 'C':
            searchCourse(list);
            break;
        default:
            return;
            break;
        }
        confirm();
    }
}

void printList(List *list) {
    Node *curr;

    cls();
    printf(">List of entries (%d): \n", list->length);
    for(curr = list->head; curr; curr = curr->next) {
        printStudent(curr->student);
    }
}

void printStudent(Student *stdnt) {
    printf("[%04d]:", stdnt->ID);
    printf("\tName: %s\n", stdnt->name);
    printf("\tCourse: %s\n", stdnt->course);
    printf("\n");
}

void searchID(List *list) {
    Student *foundStudent;
    int id;

    cls();
    printf("Searching by ID:\n\n");
    printf(">Type in a valid ID: ");
    scanf("%d", &id);
    while(id < 0 || id >= list->length) {

        cls();
        printf("Searching by ID:\n\n");
        printf(">Invalid ID!\n");
        printf(">Type in a new ID: ");
        scanf("%d", &id);
    }

    cls();
    foundStudent = findFromID(list, id);
    if(foundStudent) {
        printf(">ID (%04d) have been found\n", id);
        printStudent(foundStudent);
    } else {
        printf(">There was a problem locating '%04d'\n", id);
    }
}

Student *findFromID(List *list, int id) {
    Node *tracer;
    int present;

    if(isEmpty(list->head)) return NULL;

    present = 0;
    for(tracer = list->head; tracer && !(present = (tracer->student->ID == id)); tracer = tracer->next)
        ;

    return tracer->student;
}

void searchName(List *list) {
    Student *foundStudent;
    char name[MAX];

    cls();
    printf("Searching by name:\n\n");
    printf(">Type in a valid name: ");
    scanf("%[^\n]%*c", name);
    while(!isValidName(name)) {

        cls();
        printf("Searching by name:\n\n");
        printf(">Invalid name!\n");
        printf(">Type in a new name: ");
        scanf("%[^\n]%*c", name);
    }

    cls();
    foundStudent = findFromName(list, name);
    if(foundStudent) {
        printf(">Name (%s) have been found\n", name);
        printStudent(foundStudent);
    } else {
        printf(">There was a problem locating '%s'\n", name);
    }
}

Student *findFromName(List *list, char name[]) {
    Node *tracer;
    int present;

    if(isEmpty(list->head)) return NULL;

    present = 0;
    for(tracer = list->head; tracer && !(present = !strcmp(tracer->student->name, name)); tracer = tracer->next)
        ;

    if(present)
        return tracer->student;
    return NULL;
}

void searchCourse(List *list) {
    List *foundStudents;
    char course[MAX];

    cls();
    printf("Searching by course:\n\n");
    printf(">Type in a valid course: ");
    scanf("%[^\n]%*c", course);
    while(!isValidName(course)) {

        cls();
        printf("Searching by course:\n\n");
        printf(">Invalid course!\n");
        printf(">Type in a new course: ");
        scanf("%[^\n]%*c", course);
    }

    cls();
    foundStudents = findFromCourse(list, course);
    if(!isEmpty(foundStudents->head)) {
        printf(">Students from course '%s' have been found:\n", course);
        printList(foundStudents);
    } else {
        printf(">There was a problem locating couse '%s'\n", course);
    }

    freeList(foundStudents);
}

List *findFromCourse(List *list, char course[]) {
    List *foundStudents;
    Node *tracer;

    if(isEmpty(list->head)) return NULL;

    foundStudents = createList();
    for(tracer = list->head; tracer; tracer = tracer->next) {
        if(!strcmp(tracer->student->course, course)) {
            insert(foundStudents, tracer->student);
        }
    }

    return foundStudents;
}

// HELPER FUNCIONS //

char mainMenu() {
    char cmd;

    cls();
    printf("Main menu: \n\n");
    printf(">Type in a command: ");
    scanf("%c", &cmd);
    fflush(stdin);

    while(!isValidMain(toupper(cmd))) {
        cls();
        printf("Main menu: \n\n");
        printf(">Invalid command!\n");
        printf("(?) -> shows help\n");
        printf(">Type in a new command: ");

        scanf("%c", &cmd);
        fflush(stdin);
    }

    return toupper(cmd);
}

int isValidMain(char c) {
    int i, present;
    char validCmds[MAX] = "CRUDE?";

    for(i = present = 0; validCmds[i] && !(present = (validCmds[i] == c)); i++)
        ;

    return present;
}

void showHelpMain() {
    cls();
    printf("Main menu: \n\n");
    printf("(C) -> Add new entry\n");
    printf("(R) -> Search entries\n");
    printf("(U) -> Edit entry\n");
    printf("(D) -> Delete entry\n");
    printf("(E) -> Exit\n");
    printf("(?) -> shows help\n");
    confirm();
    cls();
}

char searchMenu() {
    char cmd;

    cls();
    printf("Search menu: \n\n");
    printf(">Type in a command: ");
    scanf("%c", &cmd);
    fflush(stdin);

    while(!isValidSearch(toupper(cmd))) {
        cls();
        printf("Search menu: \n\n");
        printf(">Invalid command!\n");
        printf("(?) -> shows help\n");
        printf(">Type in a new command: ");

        scanf("%c", &cmd);
        fflush(stdin);
    }

    return toupper(cmd);
}

int isValidSearch(char c) {
    int i, present;
    char validCmds[MAX] = "LINCE?";

    for(i = present = 0; validCmds[i] && !(present = (validCmds[i] == c)); i++)
        ;

    return present;
}

void showHelpSearch() {
    cls();
    printf("Search menu: \n\n");
    printf("(L) -> List entries\n");
    printf("(I) -> Search by ID\n");
    printf("(N) -> Search by name\n");
    printf("(C) -> Search by course\n");
    printf("(E) -> Exit\n");
    printf("(?) -> shows help\n");
    confirm();
    cls();
}

int isValidName(char name[]) {
    int i, present;

    for(i = present = 0; name[i] && !(present = (!isalpha(name[i]) && name[i] != ' ')); i++)
        ;

    return !present;
}

void cls() {
    system("CLS");
}

void confirm() {
    printf("\n>Press any key to confirm\n");
    getch();
}

int isEmpty(Node *node) {
    return !node;
}

List *createList() {
    List *newList = malloc(sizeof(List));

    newList->length = 0;
    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

void freeList(List *list) {
    if(!list) return;

    freeNodes(list->head);
    free(list->head);
}

void freeNodes(Node *node) {
    if(isEmpty(node)) return;

    freeNodes(node->next);
    free(node);
}
