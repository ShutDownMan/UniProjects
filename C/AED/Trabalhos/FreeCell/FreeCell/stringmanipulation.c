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

    strToUpper(cmd);

    if(testCmdMoveToFreeCells(cmd)) return MOVETOFREECELLS;

    if(testCmdMoveToHomeCells(cmd)) return MOVETOHOMECELLS;

    if(testCmdMoveFromFreeCells(cmd)) return MOVEFROMFREECELLS;

    if(testCmdMoveColToCol(cmd)) return MOVECOLTOCOL;

    if(testCmdFindCard(cmd)) return FINDCARD;

    return 0;
}

void strToUpper(char str[]) {
    int i;
    for(i = -1; str[++i]; str[i] = toupper(str[i]))
        ;
}

int testCmdMoveToFreeCells(char cmd[]) {
    char colFrom = 0, colTo = 0;

    sscanf(cmd, " ^%c > %c ", &colFrom, &colTo);

    if(colFrom >= 'A' && colFrom <= 'H') {
        return (!colTo || (colTo >= 'A' && colTo <= 'H'));
    }

    return 0;
}

int testCmdMoveToHomeCells(char cmd[]) {
    char colFrom = 0;

    sscanf(cmd, " *%c ", &colFrom);

    return (colFrom >= 'A' && colFrom <= 'H');
}

int testCmdMoveFromFreeCells(char cmd[]) {
    char colFrom = 0, colTo = 0;

    sscanf(cmd, " V%c > %c ", &colFrom, &colTo);

    if(colFrom >= 'A' && colFrom <= 'H') {
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

    printf("From col: %c | Card qnt: %d | To col: %c\n", colFrom, cardQnt, colTo);

    if(colFrom >= 'A' && colFrom <= 'H') {
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

void readCmd1(char cmd[], char *colFrom, char *colTo) {
    sscanf(cmd, " ^%c > %c ", colFrom, colTo);
}

void readCmd2(char cmd[], char *colFrom) {
    sscanf(cmd, " *%c ", colFrom);
}

void readCmd3(char cmd[], char *colFrom, char *colTo) {
    sscanf(cmd, " V%c > %c ", colFrom, colTo);
}

void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo) {
    int i = 0, j = 0;
    sscanf(cmd, " %c%n", colFrom, &i);
    sscanf(cmd+i, "%d%n", cardQnt, &j);
    sscanf(cmd+i+j, " > %c ", colTo);
}

void readCmd5(char cmd[], char *suit, char *rank) {
    sscanf(cmd, " ( %c , %c ) ", suit, rank);
}
