#include <stdio.h>
#include <string.h>

void p1(char* src, char* dst){
	int i=5,t=strlen(src);
	for(;i<t;i++)
		if(src[i]!=0)dst[i-5]=src[i];
}

void p2(char* src, char* dst){
	int i=0, t=strlen(src);
	for(;i<t-10;i++)
		dst[i]=src[i];
}

void printa(char* string){
	int i=0,t=strlen(string);
	for(;i<t;i++)printf("%c",string[i]);
	printf("\n");
}

int main (){

	char palavra1[100],palavra2[100],palanova1[100],palanova2[100];

	gets(palavra1);
	gets(palavra2);

	p1(palavra1,palanova1);
	p2(palavra2,palanova2);

	printf("%s.\n",palanova1);
	printf("%s.\n",palanova2);

}