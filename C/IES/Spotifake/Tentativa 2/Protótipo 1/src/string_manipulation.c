#include "string_manipulation.h"

char *newString(char *str) {
	return strcpy((char *)malloc(sizeof(str)+1), str);
}

char *concatStr(char *str1, char *str2) {
	char *newStr = malloc(strlen(str1)+strlen(str2)+1);

	newStr[0] = '\0';

	strcat(newStr, str1);
	strcat(newStr, str2);

	return newStr;
}