#include <stdio.h>
#include <ctype.h>

#include "stringmanipulation.h"

// (v)copas, (p)espadas, (p)paus, (v)ouros,
char suits[4] = {'c', 'e', 'p', 'o'};
char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

// STRING MANIPULATION //

char getSuitByInd(unsigned char ind) {
    if(ind < 4) {
        return suits[ind];
    }
    return ' ';
}

char getRankByInd(unsigned char ind) {
    if(ind < 13) {
        return ranks[ind];
    }
    return ' ';
}

void readLine(char str[]) {
    scanf("%[^\n]%*c", str);
}

int getCmdType(char cmd[]) {
    if(!cmd[0]) return 0;

    if(cmd[0] == '?') return HELP;

    if(testCmdMoveToFreeCells(cmd)) return MOVETOFREECELLS;

    if(testCmdMoveToHomeCells(cmd)) return MOVETOHOMECELLS;

    if(testCmdMoveFromFreeCells(cmd)) return MOVEFROMFREECELLS;

    if(testCmdMoveColToCol(cmd)) return MOVECOLTOCOL;

    if(testCmdFindCard(cmd)) return FINDCARD;

    if(testCmdSaveGame(cmd)) return SAVEGAME;

    return 0;
}

int testCmdMoveToFreeCells(char cmd[]) {
    char colFrom = 0, colTo = 0;

    sscanf(cmd, " ^%c > %c ", &colFrom, &colTo);

    if(toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H') {
        return (!colTo || (colTo >= 'A' && colTo <= 'H'));
    }

    return 0;
}

int testCmdMoveToHomeCells(char cmd[]) {
    char colFrom = 0;

    sscanf(cmd, " *%c ", &colFrom);

    return (toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H');
}

int testCmdMoveFromFreeCells(char cmd[]) {
    char colFrom = 0, colTo = 0;

    sscanf(cmd, " v%c > %c ", &colFrom, &colTo);

    if(toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H') {
        return (!colTo || (colTo >= 'A' && colTo <= 'D'));
    }

    return 0;
}

int testCmdMoveColToCol(char cmd[]) {
    char colFrom = 0, colTo = 0;
    int cardQnt = 0, i = 0, j = 0;

    sscanf(cmd, " %c%n", &colFrom, &i);
    sscanf(cmd+i, "%d%n", &cardQnt, &j);
    sscanf(cmd+i+j, " > %c ", &colTo);

    if(toupper(colFrom) >= 'A' && toupper(colFrom) <= 'H') {
        return (colTo >= 'A' && colTo <= 'H');
    }

    return 0;
}

int testCmdFindCard(char cmd[]) {
    char fromCol = 0, toCol = 0;

    sscanf(cmd, " ( %c , %c ) ", &fromCol, &toCol);

    if(getIndBySuit(fromCol) != -1) {
        return (getIndByRank(toCol) != -1);
    }

    return 0;
}

int getIndBySuit(char suit) {
    int i;
    for(i = 0; i < 4; ++i) {
        // compare suits
        if(toupper(getSuitByInd(i)) == toupper(suit)) {
            return i;
        }
    }
    return -1;
}

int getIndByRank(char rank) {
    int i;
    for(i = 0; i < 13; ++i) {
        // compare ranks
        if(toupper(getRankByInd(i)) == toupper(rank)) {
            return i;
        }
    }
    return -1;
}

int testCmdSaveGame(char cmd[]) {
    char fileName[64] = {0};
    int n = 0;

    sscanf(cmd, " save \"%[^\"]\"%n", fileName, &n);

    if(n) {
        printf("%s\n", fileName);
        return isValidFileName(fileName);
    }
    return 0;
}

int isValidFileName(char str[]) {
    int i;

    for(i = 0; str[i]; ++i) {
        if(!isalpha(str[i])) {
            if(str[i] != '.' && str[i] != '_') {
                return 0;
            }
        }
    }

    return 1;
}

void readCmd1(char cmd[], char *colFrom, char *colTo) {
    sscanf(cmd, " ^%c > %c ", colFrom, colTo);
    *colFrom = toupper(*colFrom);
    *colTo = toupper(*colTo);
}

void readCmd2(char cmd[], char *colFrom) {
    sscanf(cmd, " *%c ", colFrom);
    *colFrom = toupper(*colFrom);
}

void readCmd3(char cmd[], char *colFrom, char *colTo) {
    sscanf(cmd, " v%c > %c ", colFrom, colTo);
    *colFrom = toupper(*colFrom);
    *colTo = toupper(*colTo);
}

void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo) {
    int i = 0, j = 0;
    sscanf(cmd, " %c%n", colFrom, &i);
    sscanf(cmd+i, "%d%n", cardQnt, &j);
    sscanf(cmd+i+j, " > %c ", colTo);
}

void readCmd5(char cmd[], char *suit, char *rank) {
    sscanf(cmd, " ( %c , %c ) ", suit, rank);
    *suit = tolower(*suit);
}

void readCmd6(char cmd[], char fileName[]) {
    sscanf(cmd, " save \"%[^\"]\"", fileName);
}
