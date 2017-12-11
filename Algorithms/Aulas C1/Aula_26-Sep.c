#include <stdio.h>
#include <string.h>
#define MAX 100


int main(int argc, char const *argv[]) {
	char s[MAX], sx[MAX];
	char* p;

	gets(s);
	gets(sx);

	p = strstr(sx, s);

	if(p) {
		printf("%s\n", p);
	}

	return 0;
}