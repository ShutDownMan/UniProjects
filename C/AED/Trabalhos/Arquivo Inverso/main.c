#include <stdio.h>
#include <conio.h>

#include "InvertionFileManipulation.h"

typedef enum {
    Exit = 0,
    PrintStopWordList,
    PrintWordInvertedFile,
    FindWordInFiles
} MainMenuChoices;

MainMenuChoices mainMenu();

int main(int argc, const char *argv[]) {
    FILE *txtFilesFile = NULL;
    FILE *stopWordsFile = NULL;

    if (argc != 3) return 1;

    if(!(txtFilesFile = fopen(argv[1], "r"))) return 1;
    if(!(stopWordsFile = fopen(argv[2], "r"))) return 2;

    StopWordsList *stopWordsList = readStopWordsList(stopWordsFile);
    getWordInvertedFile(txtFilesFile, stopWordsList);

    MainMenuChoices choice;
    do {
        choice = mainMenu();

        switch (choice) {
            case PrintStopWordList:
                printStopWordList(stopWordsList);
                break;
            case PrintWordInvertedFile:
                printWordInvertedFile();
                break;
            case FindWordInFiles:
                searchForEntry(txtFilesFile);
                break;
            case Exit:
                printf("Exiting Program...\n");
                break;
            default:
                break;
        }
        getch();
    } while (choice != Exit);


    fclose(txtFilesFile);
    fclose(stopWordsFile);
    freeStopWordList(stopWordsList);

    return 0;
}

MainMenuChoices mainMenu() {
    int choice;
    char isValidInput = 0;

    do {
        printf("(1) -> Print StopWord list\n");
        printf("(2) -> Print Word Inversion File\n");
        printf("(3) -> Find word in Files\n");
        printf("(0) to Exit\n");
        printf("\tChoice: ");

        fflush(stdin);
        scanf("%d", &choice);

        isValidInput = (choice >= 0 && choice <= 3);

    } while (!isValidInput);

    return (MainMenuChoices) choice;
}

// gdb --args Arquivo_Inverso.exe "./files/basedados.txt" "./files/stopwords.txt"