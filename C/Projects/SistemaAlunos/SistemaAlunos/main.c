#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "sistemaalunos.h"

#define MAX 256

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
        case 'U':
            update(&students);
            break;
        case 'D':
            delet(&students);
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
    while(!isValidString(str)) {
        printf("Name: ");
        scanf("%[^\n]%*c", str);
    }
    newStudent->name = strcpy(malloc(sizeof(strlen(str))+1), str);

    printf("Course: ");
    scanf("%[^\n]%*c", str);
    while(!isValidString(str)) {
        printf("Course: ");
        scanf("%[^\n]%*c", str);
    }
    newStudent->course = strcpy(malloc(sizeof(strlen(str))+1), str);

    return newStudent;
}

int insert(List *list, Student *stdnt) {
    if(isEmpty(list->head)) {
        list->head = createNode(stdnt);
        return 1;
    }

    list->tail = createNode(stdnt);
    insertNode(list->head, stdnt);
    return 1;
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

    if(newNode) {
        newNode->student = stdnt;
        newNode->next = NULL;
    }

    return newNode;
}

// SEARCH FUNCTIONS //

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

Student *searchID(List *list) {
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

    return foundStudent;
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

Student *searchName(List *list) {
    Student *foundStudent;
    char name[MAX];

    cls();
    printf("Searching by name:\n\n");
    printf(">Type in a valid name: ");
    scanf("%[^\n]%*c", name);
    while(!isValidString(name)) {

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

    return foundStudent;
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

List *searchCourse(List *list) {
    List *foundStudents;
    char course[MAX];

    cls();
    printf("Searching by course:\n\n");
    printf(">Type in a valid course: ");
    scanf("%[^\n]%*c", course);
    while(!isValidString(course)) {

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

    return foundStudents;
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

// UPDATE FUNCTIONS //

void update(List *list) {
    Student *student;
    char c;

    while((c = updateMenu())) {
        switch (c) {
        case '?':
            showHelpUpdate();
            break;
        case 'F':
            student = findStudent(list);
            break;
        case 'I':
            updateID(student);
            break;
        case 'N':
            updateName(student);
            break;
        case 'C':
            updateCourse(student);
            break;
        case 'S':
            cls();
            printStudent(student);
            break;
        default:
            return;
            break;
        }
        confirm();
        if(student) {
            cls();
            printStudent(student);
        }
    }
}

char updateMenu() {
    char cmd;

    cls();
    printf("Update menu: \n\n");
    printf(">Type in a command: ");
    scanf("%c", &cmd);
    fflush(stdin);

    while(!isValidUpdate(toupper(cmd))) {
        cls();
        printf("Update menu: \n\n");
        printf(">Invalid command!\n");
        printf("(?) -> Shows help\n");
        printf(">Type in a new command: ");

        scanf("%c", &cmd);
        fflush(stdin);
    }

    return toupper(cmd);
}

int isValidUpdate(char c) {
    int i, present;
    char validCmds[MAX] = "FINCSE?";

    for(i = present = 0; validCmds[i] && !(present = (validCmds[i] == c)); i++)
        ;

    return present;
}

void showHelpUpdate() {
    cls();
    printf("Update menu: \n\n");
    printf("(F) -> Find entry\n");
    printf("(I) -> Update ID\n");
    printf("(N) -> Update name\n");
    printf("(C) -> Update course\n");
    printf("(S) -> Show found student\n");
    printf("(E) -> Exit\n");
    printf("(?) -> Shows help\n");
    confirm();
    cls();
}

Student *findStudent(List *list) {
    List *foundList = NULL;
    Student *foundStudent = NULL;
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
            foundStudent = searchID(list);
            break;
        case 'N':
            foundStudent = searchName(list);
            break;
        case 'C':
            foundList = searchCourse(list);
            foundStudent = findStudent(foundList);

            freeList(foundList);
            break;
        default:
            return foundStudent;
            break;
        }
        if(foundStudent)
            return foundStudent;
        confirm();
    }

    return foundStudent;
}

void updateID(Student *stdnt) {
    if(!stdnt) return;

    // This shouldn't be allowed

    cls();
    printStudent(stdnt);
    printf("\n>Type in a new ID: \n");
    scanf("%d", &stdnt->ID);

    printf("\n>ID sucessfully updated!\n");
}

void updateName(Student *stdnt) {
    char str[MAX];
    if(!stdnt) return;

    cls();
    printStudent(stdnt);
    printf("\n>Type in a valid name: \n");
    scanf("%[^\n]%*c", str);
    while(!isValidString(str)) {
        cls();
        printStudent(stdnt);
        printf(">Invalid name!\n");
        printf("\n>Type in a valid name: \n");
        scanf("%[^\n]%*c", str);
    }
    stdnt->name = strcpy(realloc(stdnt->name, (sizeof(strlen(str))+1)), str);

    printf("\n>Name sucessfully updated!\n");
}

void updateCourse(Student *stdnt) {
    char str[MAX];
    if(!stdnt) return;

    cls();
    printStudent(stdnt);
    printf("\n>Type in a valid course: \n");
    scanf("%[^\n]%*c", str);
    while(!isValidString(str)) {
        cls();
        printStudent(stdnt);
        printf(">Invalid course!\n");
        printf("\n>Type in a valid course: \n");
        scanf("%[^\n]%*c", str);
    }
    stdnt->course = strcpy(realloc(stdnt->course, (sizeof(strlen(str))+1)), str);

    printf("\n>Course sucessfully updated!\n");
}

// DELETE FUNCTIONS //

void delet(List *list) {
    Student *student;
    char c;

    while((c = deleteMenu())) {
        switch (c) {
        case '?':
            showHelpDelete();
            break;
        case 'F':
            student = findStudent(list);
            break;
        case 'S':
            printStudent(student);
            break;
        case 'D':
            deleteEntry(list, student);
            break;
        default:
            return;
            break;
        }
        confirm();
        if(student) {
            cls();
            printStudent(student);
        }
    }
}

char deleteMenu() {
    char cmd;

    cls();
    printf("Delete menu: \n\n");
    printf(">Type in a command: ");
    scanf("%c", &cmd);
    fflush(stdin);

    while(!isValidDelete(toupper(cmd))) {
        cls();
        printf("Delete menu: \n\n");
        printf(">Invalid command!\n");
        printf("(?) -> Shows help\n");
        printf(">Type in a new command: ");

        scanf("%c", &cmd);
        fflush(stdin);
    }

    return toupper(cmd);
}

int isValidDelete(char c) {
    int i, present;
    char validCmds[MAX] = "FSDE?";

    for(i = present = 0; validCmds[i] && !(present = (validCmds[i] == c)); i++)
        ;

    return present;
}

void showHelpDelete() {
    cls();
    printf("Update menu: \n\n");
    printf("(F) -> Find entry\n");
    printf("(S) -> Show entry\n");
    printf("(D) -> Delete entry\n");
    printf("(E) -> Exit\n");
    printf("(?) -> Shows help\n");
    confirm();
    cls();
}

void deleteEntry(List *list, Student* student) {
    Node **tracer, *old;
    char present = 0;

    if(!list || isEmpty(list->head)) return;

    for(tracer = &list->head; *tracer && !(present = ((*tracer)->student->ID == student->ID)); tracer = &(*tracer)->next)
        ;

    if(present) {
        old = *tracer;
        *tracer = (*tracer)->next;
        free(old->student);
        free(old);
    }
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
        printf("(?) -> Shows help\n");
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
    printf("(?) -> Shows help\n");
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
        printf("(?) -> Shows help\n");
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
    printf("(?) -> Shows help\n");
    confirm();
    cls();
}

int isValidString(char name[]) {
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
