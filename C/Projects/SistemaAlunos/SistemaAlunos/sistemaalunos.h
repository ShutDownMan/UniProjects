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

// MAIN //

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: printa na saida padrão o menu principal
char mainMenu();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: printa na saida padrão comandos válidos
void showHelpMain();

// CRUD //

// CREATE FUNCTIONS //

/// Entrada: uma lista encadeada
/// Pré-condição: nenhuma
/// Pós-condição: auxulia no armazenamento dos dados do estudante
void createForm(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: lê da entrada padrão os dados do estudante
Student *readStudent();

/// Entrada: uma lista encadeada e um estudante
/// Pré-condição: nenhuma
/// Pós-condição: auxilia na inserção estudante na lista encadeada
int insert(List *list, Student *stdnt);

/// Entrada: um nó e um estudante
/// Pré-condição: nenhuma
/// Pós-condição: insere estudante na lista encadeada
Node *insertNode(Node *node, Student *stdnt);

/// Entrada: um estudante
/// Pré-condição: nenhuma
/// Pós-condição: cria nó a partir de estudante
Node *createNode(Student *stdnt);

// SEARCH FUNCTIONS //

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void search(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
char searchMenu();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void printList(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void printStudent(Student *stdnt);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void showHelpSearch();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void printList(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
Student *searchID(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
Student *findFromID(List *list, int id);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
Student *searchName(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
Student *findFromName(List *list, char name[]);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
List *searchCourse(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
List *findFromCourse(List *list, char course[]);

// UPDATE FUNCTIONS //

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void update(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
char updateMenu();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void showHelpUpdate();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
Student *findStudent(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void updateID(Student *stdnt);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void updateName(Student *stdnt);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void updateCourse(Student *stdnt);

// DELETE FUNCTIONS //

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void delet(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
char deleteMenu();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
int isValidDelete(char c);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void showHelpDelete();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void deleteEntry(List *list, Student* student);

// HELPER FUNCIONS //

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
int contains(char c, char validCmds[]);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
int isValidString(char name[]);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void cls();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void confirm();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
int isEmpty(Node *node);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
List *createList();

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void freeList(List *list);

/// Entrada: nenhuma
/// Pré-condição: nenhuma
/// Pós-condição: nenhuma
void freeNodes(Node *node);

#endif // SISTEMAALUNOS_H
