#include <stdio.h>

int isIgual(char* s, char* dest) {
	int i;

	for (i = 0; dest[i]==s[i] && dest[i]!='\0' && s[i]!= '\0'; ++i)
		;

	return s[i]==dest[i];
}

char* cpyStr(char* dest, char* s) {
	int i;

	for (i = 0; s[i] != 0; ++i)
	{
		dest[i] = s[i];
	}
	
	dest[i] = '\0';

	return dest;
}

int isdigit(char c) {
	return (c >= '0' && c <= '9');
}

int main (){
	char s[100], dest [100];

	gets(dest);
	gets(s);
	while(!isIgual(s, "fim")){
		printf("%d\n", isIgual(s,dest));
		cpyStr(dest, s);
		gets(s);
	}
}