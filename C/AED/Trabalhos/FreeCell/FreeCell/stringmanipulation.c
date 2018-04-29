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
    int i = 0;
    i += skipSpaces(cmd);
    if(cmd[i] == '^') {
        i++;
        if(cmd[i] >= 'A' && cmd[i] <= 'H') {
            i++;
            i += skipSpaces(cmd + i);
            if(cmd[i] == '>') {
                i++;
                i += skipSpaces(cmd + i);
                return (cmd[i] >= 'A' && cmd[i] <= 'D') * MOVETOFREECELLS;
            }
            i += skipSpaces(cmd + i);
            return (!cmd[i]) * MOVETOFREECELLS;
        }
    }
    return 0;
}

int testCmdMoveToHomeCells(char cmd[]) {
    int i = 0;
    if(cmd[i] == '*') {
        i++;
        if(!cmd[i]) return 0;
        return (cmd[i] >= 'A' && cmd[i] <= 'H');
    }
    return 0;
}

int testCmdMoveFromFreeCells(char cmd[]) {
    int i = 0;
    if(cmd[i] == 'V') {
        i++;
        if(!cmd[i]) return 0;

        if(cmd[i] >= 'A' && cmd[i] <= 'D') {
            i++;
            i += skipSpaces(cmd + i);
            if(cmd[i++] == '>') {
                i += skipSpaces(cmd + i);
                return (cmd[i] >= 'A' && cmd[i] <= 'H');
            }
        }
    }
    return 0;
}

int testCmdMoveColToCol(char cmd[]) {
    int i = 0, hasNum = 0, numQnt;
    if(cmd[i] >= 'A' && cmd[i] <= 'H') {
        i++;
        if(!cmd[i]) return 0;

        // read numbers
        for(hasNum = numQnt = 0; cmd[i] && cmd[i] >= '0' && cmd[i] <= '9'; hasNum = ++i) {
            numQnt = numQnt*10 + cmd[i]-'0';
        }
        if(hasNum && numQnt == 0) return 0;

        i += skipSpaces(cmd + i);
        if(cmd[i] == '>') {
            i++;
            i += skipSpaces(cmd + i);
            return (cmd[i] >= 'A' && cmd[i] <= 'H') * MOVECOLTOCOL;
        }
    }
    return 0;
}

int testCmdFindCard(char cmd[]) {
    int i = 0;
    i += skipSpaces(cmd);
    if(cmd[i] == '&') {
        i++;
        if(cmd[i] == '(' || cmd[i] == '[') {
            i++;
            if(getIndBySuit(cmd[i]) != -1) {
                i++;
                if(cmd[i] == ',') {
                    i++;
                    i += skipSpaces(cmd + i);
                    if(getIndByRank(cmd[i]) != -1) {
                        i++;
                        return (cmd[i] == ')' || cmd[i] == ']');
                    }
                }
            }
        }
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

int skipSpaces(char str[]) {
    int i;
    for(i = 0; str[i] == ' '; i++)
        ;
    return i;
}

void readCmd1(char cmd[], char *colFrom, char *colTo) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[++i];
    i++;
    i += skipSpaces(cmd + i);

    if(cmd[i++] == '>') {
        i += skipSpaces(cmd + i);
        if(cmd[i] >= 'A' && cmd[i] <= 'D') {
            *colTo = cmd[i];
        }
    }
}

void readCmd2(char cmd[], char *colFrom) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[++i];
}

void readCmd3(char cmd[], char *colFrom, char *colTo) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[++i];
    i++;

    i += skipSpaces(cmd + i);
    i++; // >
    i += skipSpaces(cmd + i);

    *colTo = cmd[i];
}

void readCmd4(char cmd[], char *colFrom, int *cardQnt, char *colTo) {
    int i = 0;

    i += skipSpaces(cmd);
    *colFrom = cmd[i];
    i++;

    for(*cardQnt = 0; cmd[i] >= '0' && cmd[i] <= '9'; ++i) {
        *cardQnt = (*cardQnt * 10) + (cmd[i] - '0');
    }

    i += skipSpaces(cmd + i);
    i++; // >
    i += skipSpaces(cmd + i);

    *colTo = cmd[i];
}

void readCmd5(char cmd[], char *suit, char *rank) {
    int i = 0;

    i += skipSpaces(cmd);
    i++;
    *suit = cmd[++i];
    i += 2;
    i += skipSpaces(cmd + i);
    *rank = cmd[i];
}
