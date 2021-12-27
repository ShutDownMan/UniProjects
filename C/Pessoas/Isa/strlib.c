#include <stdio.h>
#include "strlib.h"
#include <stdlib.h>

int str_length (const char *str){
	int i = 0;
	if(str == NULL) return -1;
	while(str[i] != '\0')
		i++;
	return i;
}

char* str_duplicate (const char *str){
	if(str == NULL) return NULL;

	char *nova_string = malloc(sizeof(char) * str_length(str) + 1);
	
	int i=0;
	for (i = 0; str[i]; i++)
        nova_string[i] = str[i];

    nova_string[i]='\0';

	return nova_string;
}

int str_compare (const char *stra, const char *strb){
	int i;
	if(stra == NULL || strb == NULL) {
		printf("STRING NULA, FAVOR INICIALIZE A STRING.\n");
		return -2;
	}
	else{
		for (i = 0; stra[i] != '\0' && strb[i] != '\0'; i++){
			if (stra[i] > strb[i]) return 1;
			else if (stra[i] < strb[i]) return -1;
		}

		if(stra[i] && !strb[i]) {
			return 1;
		} else if(!stra[i] && strb[i]) {
			return -1;
		}

		return 0;
	}
}

int str_reverse (char *str) {
	int i = 0;

	if(str == NULL) return 0;

	int tam = str_length(str);
	char aux;
	for(i = 0; i < tam/2; ++i) {
		aux = str[i];
		str[i] = str[tam - i - 1];
		str[tam - i - 1] = aux;
	}

	return 1;
}

int str_upper (char *str){
	int c = 0;
	if(str != 0){
		for(int i = 0; str[i]; i++)
			if(str[i] >='a' && str[i] <= 'z') c++;
		return c;
	}
	else return -1;
}

int str_lower (char *str){
	int c = 0;
	if(str != NULL){
		for(int i = 0; str[i]; i++)
			if(str[i] >='A' && str[i] <= 'Z') c++;
		return c;
	}
	else return -1;
}

int str_copy (char *dst, const char *src) {
	int i = 0;

	if(dst == NULL || src == NULL) return -1;

	if(str_length(dst) < str_length(src)) return 0;

	for(i = 0; src[i]; i++)
		dst[i] = src[i];
	dst[i] = '\0';

	return 1;
}

char* str_concatenate (const char *stra, const char *strb){
	int tamA = str_length(stra);
	int tamB = str_length(strb);

	int i = 0, strCpyCount = 0;

	if(stra == NULL && strb == NULL) return NULL;

	tamA = (tamA < 0) ? 0 : tamA;
	tamB = (tamB < 0) ? 0 : tamB;
	
	char *nova_string = (char *)malloc(sizeof(char) * (tamA + tamB + 1));

	for(i = 0; i < tamA; ++i) {
		nova_string[strCpyCount++] = stra[i];
	}

	for(i = 0; i < tamB; ++i) {
		nova_string[strCpyCount++] = strb[i];
	}

	return nova_string;
}

int str_find_first (const char *str, const char c){
	if(str == NULL) return -1;
	else if(str != NULL){
		for (int i = 0; str[i]; i++)
			if(str[i] == c) return i;
		return -1;
	}
	else return -1;
}

int str_find_last (const char *str, const char c){
	int p = -1;

	if(str != NULL){
		for (int i = 0; str[i]; i++)
			if(str[i] == c) p = i;
	}
	return p;	
}

int str_count_words (const char *str){
	int c = 0, i = 0;
	if(str == NULL) return -1;

	for (; str[i]; i++)
		if(str[i] == ' ') c++;
	if(str[i] == '\0') c++;
	return c;
}
